#pragma once
#include "raylib.h"
#include "raymath.h"
#include <vector>
#include <cmath>

#include "Enemy.h"

class EnemyMelee : public Enemy
{
private:
	
	float attack_range;

public:

	EnemyMelee(	Vector2 _startPos,
				Vector2 _direction) :
		Enemy	(_startPos,
				_direction,
				250.0f)
	{}

	void Update(Vector2 _playerPos) override;
	void Draw() override;
	void Attack(std::vector<Projectile*>& projectiles) override;

	bool ReadyToAttack(Vector2 player_pos) override;
};

