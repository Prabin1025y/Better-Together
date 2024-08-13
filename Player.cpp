#include "Player.h"

#include "Animation.h"

// Player::Player(sf::Texture *texture, sf::Vector2u imageCount, float switchTime, float speed, float jumpHeight)
Player::Player(sf::Texture* texture, sf::Vector2u imageCount, float switchTime, float speed, float jumpHeight, sf::Vector2f position) : animation(new Animation(texture, imageCount, switchTime))
{
	this->speed = speed;
	this->jumpHeight = jumpHeight;
	row = 0;
	maxCol = 6;
	facingRight = true;
	canJump = true;
	canPerformAction = true;
	// animationInfinite = true;


	body.setSize(sf::Vector2f(80 / 1.5f, 100 / 1.5f));
	body.setOrigin(body.getSize() / 2.0f);
	body.setPosition(position);
	body.setTexture(texture);

	// printf("%d, %d\n", texture->getSize().x, texture->getSize().y);
}

void Player::death() {
	if (canPerformAction)
		animation->setCurrentImageX(0);
	canPerformAction = false;
	row = 6;
	maxCol = 8;
}

void Player::Update(float deltaTime)
{
	// sf::Vector2f movement(0.0f, 0.0f);
	GameManager& gameManager = GameManager::getInstance();
	velocity.x = 0.0f;

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
		velocity.x -= speed;
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
		velocity.x += speed;

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::W) && canJump)
	{
		canJump = false;
		velocity.y = -sqrtf(2.0f * 981.0f * jumpHeight);
	}

	velocity.y += gravity * deltaTime;

	if (velocity.x > 0)
		facingRight = true;
	else if (velocity.x < 0)
		facingRight = false;

	// printf("%d , %d \n",velocity.x, velocity.y);
	// if (gameManager.getCanPerformActionByPlayer1())
	if (canPerformAction)
	{
		if (velocity.y < 0.0f)
		{
			maxCol = 1;
			row = 2;
		}
		else if (!canJump)
		{
			maxCol = 1;
			row = 3;
		}
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
		{
			// gameManager.setCanPerformActionByPlayer1(false);
			canPerformAction = false;
			row = 4;
			maxCol = 6;
			animation->setCurrentImageX(0);
			printf("\nPunch");
		}
		else if (velocity.x == 0.0f)
		{
			row = 0;
			maxCol = 6;
		}
		else
		{
			row = 1;
			maxCol = 6;
			if (velocity.x > 0)
				facingRight = true;
			else
				facingRight = false;
		}
	}

	// animation->Update(row, deltaTime, maxCol, facingRight, gameManager);
	animation->Update(row, deltaTime, maxCol, facingRight, this);
	body.setTextureRect(animation->uvRect);
	// body.setTextureRect(sf::IntRect(0, 0, 16, 20));
	body.move(velocity * deltaTime);
}

void Player::setCanPerformAction(bool value)
{
	canPerformAction = value;
}

void Player::Draw(sf::RenderWindow& window)
{
	window.draw(body);
}

void Player::OnCollision(sf::Vector2f direction)
{
	// printf("%d", direction.y);
	if (direction.x > 0.0f)
	{
		velocity.x = 0.0f;
	}
	else if (direction.x < 0.0f)
	{
		velocity.x = 0.0f;
	}

	if (direction.y < 0.0f)
	{
		velocity.y = 0.0f;
		canJump = true;
	}
	else if (direction.y > 0.0f)
	{
		velocity.y = 0.0f;
	}
}

Player::~Player()
{
	delete animation;
}