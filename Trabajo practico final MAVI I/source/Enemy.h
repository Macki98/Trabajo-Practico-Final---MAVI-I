#pragma once

#include <cmath>
#include "raylib.h"
#include "raymath.h"
#include "Projectile.h"
#include "Player.h"
#include <vector>


class Enemy
{
protected:
	Vector2 pos = Vector2Zero(); // Posicion en el eje
	Vector2 dir = Vector2Zero(); // Fuerza de desplazamiernto
	float speed; // Velocidad de mov.
	Rectangle enemy; // Prototipo que servira de hitbox

	float spawn_projectile;
	float shot_interval;

	Vector2 direction_to_target = Vector2Zero(); // Hacia donde apuntar el proyectil.


public:

	Enemy(Vector2 _StartPos, Vector2 _direction, float _spd);
	virtual ~Enemy();

	// Metodos virtuales puros
	virtual void Update(Vector2 _playerPos) = 0;
	virtual void Draw() = 0;
	virtual void Attack(std::vector<Projectile>& projectiles); // Pasamos el vector de projectiles como argumento

	// Metodos comunes para los "hijos"
	Vector2 Aim(Player& _target); // Pasamos Player como argumento
	bool ReadyToAttack(); // Bandera que indica cuando disparar.
	
	
	float GetEnemyHeigth() const;
	void SetPos(Vector2 newPos);

	Vector2 GetEnemyPos() const;
};

