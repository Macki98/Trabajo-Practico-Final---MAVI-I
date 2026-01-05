#include "GameController.h"

GameController::GameController()
{
	InitWindow(screen_width, screen_height, title);
	SetTargetFPS(60);
	InitAudioDevice();
}

GameController::~GameController()
{
	CloseAudioDevice();
	CloseWindow();
}


