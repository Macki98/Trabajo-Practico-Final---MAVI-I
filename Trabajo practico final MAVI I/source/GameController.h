#pragma once
#include "raylib.h"
#include <iostream>

class GameController
{
private:

	int screen_width = 1080;
	int screen_height = 720;
	const char *title = "Rainbow Hero Shield";

public:

	GameController();
	~GameController();

	void InitScreen();
	
};

