#include "Enemy.h"

Enemy::Enemy(Vector2 _StartPos, Vector2 _direction, float _spd)
{
	pos = _StartPos;
	dir = _direction;
	speed = _spd;

	enemy = { _StartPos.x, _StartPos.y, 50.0f, 120.0f };

	spawn_projectile = 0.0f;
	shot_interval = 0.0f;
}

Enemy::~Enemy()
{
}


void Enemy::Aim(Vector2 _target)
{
	Vector2 diff = Vector2Subtract(_target, pos);

	if (Vector2Length(diff) > 0)
	{
		direction_to_target = Vector2Normalize(diff);
	}
	else {
		direction_to_target = { 0,0 };
	}
}

float Enemy::GetEnemyHeigth() const
{
	return enemy.height;
}

void Enemy::SetPos(Vector2 newPos)
{
	pos = newPos;
	enemy.x = newPos.x;
	enemy.y = newPos.y;
}

Vector2 Enemy::GetEnemyPos() const
{
	return pos;
}

float Enemy::GetSpawnProjectile() const
{
	return spawn_projectile;
}

float Enemy::GetShotInterval() const
{
	return shot_interval;
}

