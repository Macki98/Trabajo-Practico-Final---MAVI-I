#include "Player.h"

Player::Player()
{

	player = { pos.x,pos.y, 50, 120};
}

Player::~Player()
{
}

void Player::Init() {
	
	pos = {
	(float)GetScreenWidth() / 2, // X
	(float)GetScreenHeight() / 2 // Y
	};

	dir = {
		200.0f, // Velocidada X
		0 // Velocidad Y
	};

	accel = 0.95f;

	
}

void Player::Move()
{
	float deltaTime = GetFrameTime();
	float gravity = 450.0f;

	if (IsKeyDown(KEY_A)) // Movimiento Izq
	{
		pos.x -= dir.x * deltaTime;
	}
	else if (IsKeyDown(KEY_D)) // Movimiento Der
	{
		pos.x += dir.x * deltaTime;
	}

	if (pos.y >= GetScreenHeight() - player.height) // Impacto contra el limite inferior de la pantalla
	{
		pos.y = (GetScreenHeight() - player.height);
		dir.y = 0;
		Jump();
	}
	else // Aplicamos gravedad
	{
		dir.y += gravity * deltaTime;
	}

	pos.y += dir.y * deltaTime; // Actualizamos la posicion segun la fuerza de gravedad
}


void Player::Jump()
{
	if (IsKeyPressed(KEY_SPACE)) // Salto con Barra espaciadora
	{
		dir.y = -350.0f;
	}
}

void Player::Draw() // Dibujamos el personaje en pantalla
{
	DrawRectangleLines(
		pos.x, 
		pos.y, 
		player.width, 
		player.height, 
		GREEN);
}

Vector2 Player::GetPos() const
{
	return pos;
}

float Player::GetWidth() const
{
	return player.width;
}

float Player::GetHeight() const
{
	return player.height;
}


