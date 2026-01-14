#pragma once

#include "raylib.h"

class Enemy
{
private:
	Vector2 pos;
	Vector2 vel;

	Rectangle enemy;

public:

	Enemy();
	~Enemy();

	void Update();

	void Draw();
};

