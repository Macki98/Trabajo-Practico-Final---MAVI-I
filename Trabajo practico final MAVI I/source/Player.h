#pragma once
#include "raylib.h"
#include "raymath.h"
#include "Projectile.h"
#include "Bullet.h"
#include "Cover.h"
#include <vector>

class Player
{
private:

	Vector2 pos = Vector2Zero(); //posicion en el eje
	Vector2 dir = Vector2Zero(); // fuerza de desplazamiento
	Rectangle player; //Prototipo que servira de hitbox
	
	Vector2 mousePos = Vector2Zero();
	bool aiming;

	bool isCovered = false;
	Cover* currentCover = nullptr;
	const float normalHeight = 120.0f;
	const float interactionRange = 55.0f;

public:
	Player();
	~Player();

	void Init(); //Instanciamos al jugador luego de crear la ventana (momentaneo)
	
	void Move(std::vector<Cover*>& covers); //Movimiento en el eje x
	void Jump(); //Salto con gravedad
	void Shoot(std::vector<Projectile*>& projectiles);

	void Draw(); //Mostar el personaje en pantalla

	Vector2 GetPos() const; //Funcion que devuelve la posicion del jugador
	
	
	bool IsCovered() const;
	Cover* GetCurrentCover() const;

	void CheckDamage(std::vector<Projectile*>& projectiles);

	float GetWidth() const; // Funcion que devuelve el ancho del pj.
	float GetHeight() const; // Funcion que devuelve el alto del pj.
};

