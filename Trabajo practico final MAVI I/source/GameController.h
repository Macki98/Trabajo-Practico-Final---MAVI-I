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

	void InitScreen(); //Se inicia la ventana

	void Events(); //Eventos del juego (inputs ej.)
	void UpdateGame(); //Acctualiza el estado del juego (movimiento ej.)
	void DrawGame(); //Dibuja en pantalla el juego
	
};

