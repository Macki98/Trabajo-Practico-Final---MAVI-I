#include "GameController.h"
#include <iostream>

GameController::GameController()
{
	InitWindow(screen_width, screen_height, title);
	SetTargetFPS(60);
	InitAudioDevice();

	p1.Init();
	e1.Init();
}

GameController::~GameController()
{
	CloseAudioDevice();
	CloseWindow();
	p1.~Player();
}

void GameController::Run()
{

	while (!WindowShouldClose()) {
		Events();
		Update();
		DrawGame();
	}
}

void GameController::Events()
{
	if (IsKeyPressed(KEY_ESCAPE))
	{

		CloseWindow();

	}


}


void GameController::Update()
{
	p1.Move();

	e1.Aim(p1);
	
	e1.Update();

	DeleteInactiveProjectiles();

	// Test
	std::cout << "Projectiles activos: " << projectiles.size() << std::endl;
}

void GameController::DrawGame()
{
	// Iniciamos la etapa de dibujo
	BeginDrawing();
	// Limpiamos la pantalla 
	ClearBackground(WHITE);

	p1.Draw();
	e1.Draw();
	// Finalizamos el dibujo
	EndDrawing();
}

void GameController::DeleteInactiveProjectiles()
{
	projectiles.erase(
		std::remove_if(
			projectiles.begin(),
			projectiles.end(),
			[](const Projectile& p) {return !p.IsActive();}),
		projectiles.end()
	);
}


