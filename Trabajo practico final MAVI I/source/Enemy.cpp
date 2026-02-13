#include "Enemy.h"

Enemy::Enemy()
{

}

Enemy::~Enemy()
{
}

void Enemy::Init() 
{
	pos = {
		1000, // X
		(float)GetScreenHeight() / 2 // Y
	};

	dir = {
		200.0f, // Velocidad X
		0 // Velocidad Y
	};

	enemy = { pos.x, pos.y, 50,120 }; 
}

void Enemy::Update()
{

	float deltaTime = GetFrameTime();
	pos.x -= dir.x * deltaTime;

}

void Enemy::Draw()
{
	DrawRectangleLines(
		pos.x,
		pos.y,
		enemy.width,
		enemy.height,
		RED
		);
}

Vector2 Enemy::Aim(Player& _target)
{
	Vector2 playerPos = _target.GetPos();

	direction_to_target = { playerPos.x - pos.x,
							playerPos.y - pos.y 
	};
	
	return direction_to_target;

}

bool Enemy::ReadyToAttack()
{
	spawn_projectile += GetFrameTime();
	
	if (spawn_projectile >= shot_interval) 
	{
		spawn_projectile = 0.0f;
		return true; 
	}
	return false;
}

void Enemy::Attack(std::vector<Projectile>& projectiles)
{
	projectiles.push_back(Projectile(pos, 
									direction_to_target, 
									150.0f));
}

