#include "GameController.h"
#include <iostream>

GameController::GameController()
{
	InitWindow(screen_width, screen_height, title);
	SetTargetFPS(60);
	InitAudioDevice();

	p1.Init();
}

GameController::~GameController()
{
	CloseAudioDevice();
	CloseWindow();
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
}

void GameController::DrawGame()
{
	// Iniciamos la etapa de dibujo
	BeginDrawing();
	// Limpiamos la pantalla 
	ClearBackground(WHITE);

	p1.Draw();

	// Finalizamos el dibujo
	EndDrawing();
}


