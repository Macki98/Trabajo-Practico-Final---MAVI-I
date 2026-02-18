#include "EnemyShooter.h"
#include <iostream>

void EnemyShooter::Update(Vector2 _playerPos)
{

	float deltaTime = GetFrameTime();

	
	pos.x -= speed * deltaTime;

}

void EnemyShooter::Draw()
{
	DrawRectangleLines(
		pos.x,
		pos.y,
		enemy.width,
		enemy.height,
		RED
	);
}

void EnemyShooter::Attack(std::vector<Projectile>& projectiles)
{
	Projectile bullet(pos, direction_to_target, 150.0f);

	projectiles.push_back(bullet);

	std::cout << "DEBUG: EnemyShooter disparando" << std::endl;
}
