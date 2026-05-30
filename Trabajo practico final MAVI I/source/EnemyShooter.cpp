#include "EnemyShooter.h"

#include <iostream>

EnemyShooter::EnemyShooter	(Vector2 _startPos,
							Vector2 _direction) :
				Enemy		(_startPos,
							_direction,
							100.0f)
{
	

	shot_interval = 2.0f;
	spawn_projectile = 0.0f;
}

void EnemyShooter::Update(Vector2 /*_playerPos*/)
{
	float x_max = 500.0f;

	float deltaTime = GetFrameTime();

	pos.x -= speed * deltaTime;
	if (pos.x <= x_max)
	{
		pos.x = x_max;
	}
	enemy.x = pos.x;
}

void EnemyShooter::Draw()
{
	DrawRectangleRec(enemy, RED);
}

void EnemyShooter::Attack(std::vector<Projectile*>& projectiles)
{
	
	projectiles.push_back(new Bullet(pos, direction_to_target, false));

	std::cout << "DEBUG: EnemyShooter disparando" << std::endl;
}

bool EnemyShooter::ReadyToAttack(Vector2 /*player_pos*/)
{
	if (pos.x > (float)GetScreenWidth() - 50.0f) return false;

	spawn_projectile += GetFrameTime();

	if (spawn_projectile >= shot_interval)
	{
		spawn_projectile = 0.0f;
		return true;
	}
	return false;
}
