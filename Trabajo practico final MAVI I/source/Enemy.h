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

	float spawn_projectile;
	float shot_interval;

	Vector2 direction_to_target; // Hacia donde apuntar el proyectil.

	//Mover al GameController para mas eficiencia
	//Y pasar como parametro& a funcion Attack
	std::vector<Projectile>projectiles; // Contenedor de proyectiles.

public:

	Enemy();
	~Enemy();

	void Init();

	void Update();
	void Draw();

	Vector2 Aim(Player& _target); // Pasamos Player como argumento
	void Attack();
};

