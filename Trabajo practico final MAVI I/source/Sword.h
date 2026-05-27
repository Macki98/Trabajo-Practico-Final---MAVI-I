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
	Vector2* ownerDir;

public:

	Sword(Vector2* _ownerPos, Vector2* _ownerDir) :
		Projectile(	*_ownerPos, 0.25f), 
					ownerPos(_ownerPos), 
					ownerDir(_ownerDir)
	{}

	void Update() override;
	void Draw() override;

	Rectangle GetHitbox() override;

};

