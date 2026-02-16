#include "Projectile.h"
#include <iostream>

Projectile::Projectile(Vector2 _StartPos, Vector2 _Target, float _spd)
{
	this->pos = _StartPos;
	this->dir = _Target;
	this->speed = _spd;

	r = 15;

	active = true;


}

Projectile::~Projectile()
{
	std::cout << "DEBUG: Proyectil en X: " << pos.x << 
								 " en Y: " << pos.y <<
				" eliminada. Eliminado de memoria." <<
					std::endl;
}

void Projectile::Update() 
{
	if (!active) return;

	float deltaTime = GetFrameTime();

	pos.x += dir.x * speed * deltaTime;
	pos.y += dir.y * speed * deltaTime;

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

bool Projectile::IsActive() const
{
	return active;
}

void Projectile::SetActive(bool _status)
{
	active = _status;
}

Vector2 Projectile::GetProPos() const
{
	return pos;
}

float Projectile::GetRadius() const
{
	return r;
}

