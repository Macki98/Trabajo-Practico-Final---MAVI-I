#pragma once

#include "raylib.h"
#include "raymath.h"
#include <vector>
#include <cmath>
#include "Bullet.h"
#include "Enemy.h"

class EnemyShooter : public Enemy
{
public:

	EnemyShooter(Vector2 _startPos, Vector2 _direction);
	
	void Update(Vector2 _playerPos) override;
	void Draw() override;
	void Attack(std::vector<Projectile*>& projectiles) override;
	
	bool ReadyToAttack(Vector2 player_pos) override;

};

