#include "Projectile.h"
#include <iostream>

Projectile::Projectile()
{

}

Projectile::~Projectile()
{
}

void Projectile::Init() 
{
	pos = {
		(float)GetScreenWidth() / 2,
		(float)GetScreenHeight() / 2
	};

	vel = {
		200.0f,
		200.0f
	};

	r = 25.0;
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
	DrawCircleV(pos,r,ORANGE);
}

bool Projectile::IsOffScreen()
{
	if (
		(pos.x - r) <= 0 || (pos.x + r) >= GetScreenWidth() ||
		(pos.y - r) <= 0 || (pos.y + r) >= GetScreenHeight()
		)
	{
		
		return true;
	}
	else
	{
		return false;
	}
}
