#include "Enemy.h"
#include "Game.h"

Enemy::Enemy()
{
	TheTextureManager::Instance()->load("../Assets/textures/boat-enemy.png", "enemy",
		TheGame::Instance()->getRenderer());

	glm::vec2 size = TheTextureManager::Instance()->getTextureSize("enemy");
	setWidth(size.x);
	setHeight(size.y);
	setVelocity(glm::vec2(7, 3));
	_reset();
	setIsColliding(false);
	setType(GameObjectType::ENEMY);

	TheSoundManager::Instance()->load("../Assets/audio/engine.ogg", "engine", sound_type::SOUND_SFX);
}

Enemy::~Enemy()
{
}

void Enemy::draw()
{
	int xComponent = getPosition().x;
	int yComponent = getPosition().y;
	TheTextureManager::Instance()->draw("enemy", xComponent, yComponent,
		TheGame::Instance()->getRenderer(), true);
}

void Enemy::update()
{
	_move();
	//glm::vec2 mouseVector = TheGame::Instance()->getMousePosition();

	//setPosition(glm::vec2(mouseVector.x, getPosition().y));
	_checkBounds();
}

void Enemy::clean()
{
}

void Enemy::_move()
{
	glm::vec2 newPosition = getPosition() + getVelocity();
	setPosition(newPosition);
}

void Enemy::_checkBounds()
{
	if (getPosition().y > 480 + getHeight()) {
		_reset();
	}
	if (getPosition().x > 640 - (getWidth() * 0.5) || getPosition().x <= (getWidth() * 0.5))
	{
		setVelocity(glm::vec2(-getVelocity().x, getVelocity().y));
	}
}

void Enemy::_reset()
{
	setIsColliding(false);
	int halfWidth = getWidth() * 0.5;
	int xComponent = rand() % (640 - getWidth()) + halfWidth + 1;
	int yComponent = -getHeight();
	setPosition(glm::vec2(xComponent, yComponent));
}