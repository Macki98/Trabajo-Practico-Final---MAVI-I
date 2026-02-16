#pragma once

#include <cmath>
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

	float spawn_projectile;
	float shot_interval;

	Vector2 direction_to_target; // Hacia donde apuntar el proyectil.


public:

	Enemy(Vector2 _StartPos, Vector2 _orientation);
	~Enemy();

	void Update();
	void Draw();

	Vector2 Aim(Player& _target); // Pasamos Player como argumento
	bool ReadyToAttack(); // Bandera que indica cuando disparar.
	void Attack(std::vector<Projectile>& projectiles); // Pasamos el vector de projectiles como argumento
	
	float GetEnemyHeigth() const;
	void SetPos(Vector2 newPos);
};

