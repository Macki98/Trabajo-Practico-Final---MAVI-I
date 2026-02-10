#pragma once

#include "raylib.h"
#include "raymath.h"

#include "Projectile.h"

#include <vector>

class Enemy
{
private:
	Vector2 pos = Vector2Zero(); // Posicion en el eje
	Vector2 vel = Vector2Zero(); // Fuerza de desplazamiernto

	Rectangle enemy; // Prototipo que servira de hitbox

	float spawn_projectile;
	float shot_interval;

	std::vector<Projectile>projectiles;

public:

	Enemy();
	~Enemy();

	void Init();

	void Update();
	void Draw();

	void Aim();
	void Attack();
};

