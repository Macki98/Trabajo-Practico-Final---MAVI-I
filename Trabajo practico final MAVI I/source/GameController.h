#pragma once
#include "raylib.h"
#include <iostream>

class GameController
{
private:

	//Parametros para la construccion de la pantalla
	const int screen_width = 1080;
	const int screen_height = 720;
	const char *title = "Rainbow Shield Hero";

public:

	GameController(); //Aqui inicializamos la ventana
	~GameController(); //Descargamos recursos

	void Run(); //Metodo que corre el juego.

	void Events(); //Eventos del juego (inputs ej.)
	void UpdateGame(); //Acctualiza el estado del juego (movimiento ej.)
	void DrawGame(); //Dibuja en pantalla el juego
	
};

