#include "EnemyMelee.h"

#include <iostream>

void EnemyMelee::Update(Vector2 _playerPos)
{
	float deltaTime = GetFrameTime();

	pos.x += direction_to_target.x * speed * deltaTime;
	pos.y += direction_to_target.y * speed * deltaTime;
}

void EnemyMelee::Draw()
{
	DrawRectangleLines(
		pos.x,
		pos.y,
		enemy.width,
		enemy.height,
		BLUE
	);
}

void EnemyMelee::Attack(std::vector<Projectile>& projectiles)
{
}
