#pragma once

#include "raylib.h"
#include "raymath.h"

#include "Projectile.h"
#include "Player.h"
#include <vector>

class Enemy
{
private:
	Vector2 pos = Vector2Zero(); // Posicion en el eje
	Vector2 dir = Vector2Zero(); // Fuerza de desplazamiernto

	Rectangle enemy; // Prototipo que servira de hitbox

	float spawn_projectile = 0.0f;
	float shot_interval = 1.5f;

	Vector2 direction_to_target; // Hacia donde apuntar el proyectil.


public:

	Enemy();
	~Enemy();

	void Init();

	void Update();
	void Draw();

	Vector2 Aim(Player& _target); // Pasamos Player como argumento
	bool ReadyToAttack(); // Bandera que indica cuando disparar.
	void Attack(std::vector<Projectile>& projectiles); // Pasamos el vector de projectiles como argumento
};

