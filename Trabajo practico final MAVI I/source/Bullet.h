#pragma once
#include "raylib.h"
#include "raymath.h"
#include <vector>
#include <cmath>
#include "Projectile.h"

class Bullet : public Projectile
{
private:

	Vector2 direction;
	float speed;

	float r = 4.0f;

public:

	Bullet(Vector2 _pos, Vector2 _dir)
		: Projectile(_pos, 5.0f), 
					direction(_dir), 
					speed(500.0f) 
	{}

	void Update() override;
	void Draw() override;

	float GetRadius() const;

};

