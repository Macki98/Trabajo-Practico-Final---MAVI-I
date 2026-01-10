#pragma once
#include "raylib.h"
class Player
{
private:

	Vector2 pos;
	Vector2 vel;
	float accel; //Aceleracion del personaje
	Rectangle player; //Prototipo que servira de hitbox

public:
	Player();
	~Player();

	void Init(); //Instanciamos al jugador luego de crear la ventana
	
	void Move(); //Movimiento en el eje x
	void Jump(); //Salto con gravedad
	void Draw(); //Mostar el personaje en pantalla

	
};

