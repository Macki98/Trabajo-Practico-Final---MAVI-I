#include "Bullet.h"

void Bullet::Update()
{
	if (!active) return;

	float deltaTime = GetFrameTime();
	lifeTime -= deltaTime;

	pos.x += direction.x * speed * deltaTime;
	pos.y += direction.y * speed * deltaTime;

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

void Bullet::Draw()
{
	if (active) {
		DrawCircleV(pos, r, ORANGE);
	}
}

float Bullet::GetRadius() const
{
	return r;
}




