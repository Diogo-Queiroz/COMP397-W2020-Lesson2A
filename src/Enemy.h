#pragma once
#ifndef __ENEMY__
#define __ENEMY__

#include "GameObject.h"
#include "TextureManager.h"
#include "SoundManager.h"

class Enemy : public GameObject
{
public:
	// Constructor / Destructor
	Enemy();
	~Enemy();

	// Inherited via GameObject
	void draw() override;
	void update() override;
	void clean() override;
private:
	void _move();
	void _checkBounds();
	void _reset();
};

#endif // defined(__ENEMY__)
