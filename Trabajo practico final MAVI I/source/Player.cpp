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

	accel = 125.0f;
	player = { pos.x,pos.y, 50,120 };
}
void Player::Move()
{
	float deltaTime = GetFrameTime();
	if (IsKeyDown(KEY_A))
	{
		pos.x -= vel.x * deltaTime;
	}
	else if (IsKeyDown(KEY_D))
	{
		pos.x += vel.x * deltaTime;
	}

}

void Player::Jump()
{
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
