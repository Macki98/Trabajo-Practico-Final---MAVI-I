#include "EnemyMelee.h"
#include "Sword.h"
#include <iostream>

EnemyMelee::EnemyMelee(Vector2 _startPos, Vector2 _direction)
					: Enemy(_startPos, _direction, 250.0f)
{
	enemy = { _startPos.x, _startPos.y,50.0f,120.0f };

	attack_range = 75.0f;
	shot_interval = 1.2f;
	spawn_projectile = 0.0f;

}

void EnemyMelee::Update(Vector2 _playerPos)
{
	float deltaTime = GetFrameTime();
	
	float distance = Vector2Distance(pos, _playerPos);

	if (distance > attack_range - 5.0f) 
	{	
		pos.x += direction_to_target.x * speed * deltaTime;
		pos.y += direction_to_target.y * speed * deltaTime;

		enemy.x = pos.x;
		enemy.y = pos.y;
	}
}

void EnemyMelee::Draw()
{
	DrawRectangleRec(enemy, BLUE);
}

void EnemyMelee::Attack(std::vector<Projectile*>& projectiles)
{
	projectiles.push_back(new Sword(&pos));

	std::cout << "DEBUG: EnemyShooter disparando" << std::endl;
}

bool EnemyMelee::ReadyToAttack(Vector2 player_pos)
{
	spawn_projectile += GetFrameTime();

	float distance = Vector2Distance(pos, player_pos);

	if (spawn_projectile >= shot_interval && distance <= attack_range)
	{
		spawn_projectile = 0.0f;
		return true;
	}

	return false;
}
