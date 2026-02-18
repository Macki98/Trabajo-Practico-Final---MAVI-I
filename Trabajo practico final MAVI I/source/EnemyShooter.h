#pragma once

#include "raylib.h"
#include "raymath.h"
#include <vector>
#include <cmath>

#include "Enemy.h"

class EnemyShooter : public Enemy
{
public:

	EnemyShooter(Vector2 _startPos, Vector2 _direction) : Enemy(_startPos, _direction, 100.0f){}
	
	void Update(Vector2 _playerPos) override;
	void Draw() override;
	void Attack(std::vector<Projectile>& projectiles) override;
	

};

