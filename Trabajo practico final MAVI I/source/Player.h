#pragma once
#include "raylib.h"
#include "raymath.h"
#include "Projectile.h"

#include <vector>

class Player
{
private:

	Vector2 pos = Vector2Zero(); //posicion en el eje
	Vector2 dir = Vector2Zero(); // fuerza de desplazamiento
	Rectangle player; //Prototipo que servira de hitbox

public:
	Player();
	~Player();

	void Init(); //Instanciamos al jugador luego de crear la ventana (momentaneo)
	
	void Move(); //Movimiento en el eje x
	void Jump(); //Salto con gravedad
	void Draw(); //Mostar el personaje en pantalla

	Vector2 GetPos() const; //Funcion que devuelve la posicion del jugador
	
	void CheckDamage(std::vector<Projectile*>& projectiles);
	float GetWidth() const; // Funcion que devuelve el ancho del pj.
	float GetHeight() const; // Funcion que devuelve el alto del pj.
};

