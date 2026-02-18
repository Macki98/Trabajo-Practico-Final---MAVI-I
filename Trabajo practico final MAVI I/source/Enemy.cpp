#include "Enemy.h"

Enemy::Enemy(Vector2 _StartPos, Vector2 _direction, float _spd)
	: pos(_StartPos), dir(_direction), speed(_spd)
{
	this->pos = _StartPos;
	
	enemy = { pos.x, pos.y, 50,120 };

	shot_interval = 3.5f;

	spawn_projectile = (float)GetRandomValue(0, (int)(shot_interval * 100)) / 100.0f;
}

Enemy::~Enemy()
{
}


void Enemy::Update(Vector2 _playerPos)
{
}

void Enemy::Draw()
{

}

Vector2 Enemy::Aim(Player& _target)
{
	Vector2 playerPos = _target.GetPos();

	float diffX = playerPos.x - pos.x;
	float diffY = playerPos.y - pos.y;

	float distance = sqrtf(diffX * diffX + diffY * diffY);

	if (distance != 0)
	{
		direction_to_target.x = diffX / distance;
		direction_to_target.y = diffY / distance;
	}

	return direction_to_target;

}

bool Enemy::ReadyToAttack()
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

void Enemy::Attack(std::vector<Projectile>& projectiles)
{

}

float Enemy::GetEnemyHeigth() const
{
	return enemy.height;
}

void Enemy::SetPos(Vector2 newPos)
{
	this->pos = newPos;
}

Vector2 Enemy::GetEnemyPos() const
{
	return pos;
}

