#pragma once
#include "raylib.h"
#include "raymath.h"
#include <vector>
#include <cmath>
#include "Projectile.h"

class Bullet : public Projectile
{
private:

	
	float speed;

	float r = 4.0f;

public:

	Bullet(Vector2 _pos, Vector2 _dir, bool _isFromPlayer)
		: Projectile(_pos, _dir, 5.0f, _isFromPlayer), 
					speed(500.0f)
	{}

	void Update() override;
	void Draw() override;

	Rectangle GetHitbox() override;

	float GetRadius() const;

};

