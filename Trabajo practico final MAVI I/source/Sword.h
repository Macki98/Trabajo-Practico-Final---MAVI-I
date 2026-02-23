#pragma once
#include "raylib.h"
#include "raymath.h"
#include <vector>
#include <cmath>
#include "Projectile.h"

class Sword : public Projectile
{
private:

	Vector2* ownerPos;

public:

	Sword(Vector2* _ownerPos) :
		Projectile(*_ownerPos, 0.12f), ownerPos(_ownerPos)
	{}

	void Update() override;

	void Draw() override;


};

