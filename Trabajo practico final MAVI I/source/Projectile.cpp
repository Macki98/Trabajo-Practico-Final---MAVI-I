#include "Projectile.h"
#include <iostream>

Projectile::Projectile(Vector2 _StartPos, Vector2 _Target, float _spd)
{
	this->pos = _StartPos;
	this->dir = _Target;
	this->speed = _spd;

}

Projectile::~Projectile()
{
}

void Projectile::Update() 
{
	if (!active) return;

	float deltaTime = GetFrameTime();

	pos.x -= dir.x * deltaTime;
	pos.y -= dir.y * deltaTime;

	// si sale de pantalla desactivamos el proyectil
	if (
		(pos.x - r) <= 0 ||
		(pos.x + r) >= GetScreenWidth() ||
		(pos.y - r) <= 0 ||
		(pos.y + r) >= GetScreenHeight()
		)
	{
		active = false;
	}
}

void Projectile::Draw()
{
	if (active) {
		DrawCircleV(pos, r, ORANGE);
	}
}

