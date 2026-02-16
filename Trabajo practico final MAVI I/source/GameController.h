#pragma once
#include "raylib.h"
#include <iostream>

#include <cmath>
#include "Player.h"
#include "Enemy.h"
#include "Projectile.h"

#include <vector>


class GameController
{
private:

	//Parametros para la construccion de la pantalla
	const int screen_width = 1080;
	const int screen_height = 720;
	const char *title = "Rainbow Shield Hero";

	int max_enemies = 2; //Limite de enemigos disp.

	Player player;

	std::vector<Enemy*>enemies;
	float enemy_spawn_timer = 0.0f;
	float enemy_spawn_interval = 2.0f;

	std::vector<Projectile>projectiles;

	

public:

	GameController(); //Aqui inicializamos la ventana
	~GameController(); //Descargamos recursos

	void Run(); //Metodo que corre el juego.

	void Events(); //Eventos del juego (inputs ej.)
	void Update(); //Acctualiza el estado del juego (movimiento ej.)
	void DrawGame(); //Dibuja en pantalla el juego
	
	Vector2 GetRandomSpawnPosition();
	void CreateEnemy();
	void DeleteInactiveEnemies();

	void DeleteInactiveProjectiles(); // Limpieza de los proyectiles
	
	void CheckPlayerCollisions();

};

