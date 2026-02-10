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

	Projectile(Vector2 _StartPos, Vector2 _Aim);
	~Projectile();


	void Update();
	void Draw();

	bool active;
	bool IsOffScreen();
};

