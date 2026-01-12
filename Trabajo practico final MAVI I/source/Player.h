#pragma once
#include "raylib.h"
#include "raymath.h"
class Player
{
private:

	Vector2 pos = Vector2Zero(); //posicion en el eje
	Vector2 vel = Vector2Zero(); // fuerza de desplazamiernto
	float accel = 0.0f; //Aceleracion del personaje
	Rectangle player; //Prototipo que servira de hitbox

public:
	Player();
	~Player();

	void Init(); //Instanciamos al jugador luego de crear la ventana
	
	void Move(); //Movimiento en el eje x
	void Jump(); //Salto con gravedad
	void Draw(); //Mostar el personaje en pantalla

	
};

