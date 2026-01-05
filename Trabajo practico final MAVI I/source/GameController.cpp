#include "GameController.h"

GameController::GameController()
{
}

GameController::~GameController()
{
}

void GameController::InitScreen()
{

	InitWindow(screen_width,screen_height, title);
	SetTargetFPS(60);
	InitAudioDevice();

}
