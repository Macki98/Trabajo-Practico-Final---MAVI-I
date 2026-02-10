#include "Projectile.h"
#include <iostream>

Projectile::Projectile(Vector2 _StartPos, Vector2 _Aim)
{
	this->pos = _StartPos;
	this->vel = _Aim;
}

Projectile::~Projectile()
{
}

void Projectile::Update() 
{
	float deltaTime = GetFrameTime();
	pos.x -= vel.x * deltaTime;
	pos.y -= vel.y * deltaTime;

	if (IsOffScreen())
	{
		//Chequeando colisiones
		std::cout << "salio de la pantalla" << std::endl;

	}
}

void Projectile::Draw()
{
	if (active) {
		DrawCircleV(pos, r, ORANGE);
	}
}

bool Projectile::IsOffScreen()
{
	if (
		(pos.x - r) <= 0 || 
		(pos.x + r) >= GetScreenWidth() ||
		(pos.y - r) <= 0 || 
		(pos.y + r) >= GetScreenHeight()
		)
	{
		active = false;
		return true;
	}
	else
	{
		active = true;
		return false;
	}
}
