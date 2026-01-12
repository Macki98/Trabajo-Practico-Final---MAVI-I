#include "Player.h"

Player::Player()
{

}

Player::~Player()
{
}

void Player::Init() {
	
	pos = {
	(float)GetScreenWidth() / 2, // X
	(float)GetScreenHeight() / 2 // Y
	};

	vel = {
		200.0f, //velocidada X
		0 // velocidad Y
	};

	accel = 0.95f;

	player = { pos.x,pos.y, 50,120 };
}

void Player::Move()
{
	float deltaTime = GetFrameTime();
	float gravity = 450.0f;
	if (IsKeyDown(KEY_A))
	{
		pos.x -= vel.x * deltaTime;
	}
	else if (IsKeyDown(KEY_D))
	{
		pos.x += vel.x * deltaTime;
	}

	if (pos.y >= GetScreenHeight() - player.height)
	{
		pos.y = (GetScreenHeight() - player.height);
		vel.y = 0;
		Jump();
	}
	else 
	{
		vel.y += gravity * deltaTime;
	}

	pos.y += vel.y * deltaTime;
}


void Player::Jump()
{
	if (IsKeyPressed(KEY_SPACE))
	{
		vel.y = -350.0f;
	}
}

void Player::Draw()
{
	DrawRectangleLines(
		pos.x, 
		pos.y, 
		player.width, 
		player.height, 
		GREEN);
}


