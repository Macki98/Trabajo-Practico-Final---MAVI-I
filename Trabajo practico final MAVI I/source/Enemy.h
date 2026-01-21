#pragma once

#include "raylib.h"
#include "raymath.h"

class Enemy
{
private:
	Vector2 pos = Vector2Zero(); // Posicion en el eje
	Vector2 vel = Vector2Zero(); // Fuerza de desplazamiernto

	Rectangle enemy; // Prototipo que servira de hitbox


public:

	Enemy();
	~Enemy();

	void Init();

	void Update();
	void Draw();
};

