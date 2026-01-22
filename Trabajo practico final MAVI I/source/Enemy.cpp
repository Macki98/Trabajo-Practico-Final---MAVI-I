#include "Enemy.h"

Enemy::Enemy()
{

}

Enemy::~Enemy()
{
}

void Enemy::Init() 
{
	pos = {
		1000, // X
		(float)GetScreenHeight() / 2 // Y
	};

	vel = {
		200.0f, // Velocidad X
		0 // Velocidad Y
	};

	enemy = { pos.x, pos.y, 50,120 }; 
}

void Enemy::Update()
{
	float deltaTime = GetFrameTime();
	pos.x -= vel.x * deltaTime;

}

void Enemy::Draw()
{
	DrawRectangleLines(
		pos.x,
		pos.y,
		enemy.width,
		enemy.height,
		RED
		);
}