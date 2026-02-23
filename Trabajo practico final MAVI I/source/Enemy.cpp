#include "Enemy.h"

Enemy::Enemy(Vector2 _StartPos, Vector2 _direction, float _spd)
{
}

Enemy::~Enemy()
{
}


void Enemy::Aim(Vector2 _target)
{
	
	direction_to_target = 
		Vector2Normalize(Vector2Subtract(_target, pos));
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

