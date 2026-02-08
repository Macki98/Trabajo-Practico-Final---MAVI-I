#pragma once
#include "raylib.h"
#include "raymath.h"

class Projectile
{
private:

	Vector2 pos;
	Vector2 vel;
	float r;

	float accel;

public:

	Projectile(Vector2 _StartPos);
	~Projectile();

	void Init();

	void Update();
	void Draw();

	bool IsOffScreen();
};

