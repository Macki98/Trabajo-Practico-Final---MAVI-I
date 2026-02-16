#include "GameController.h"
#include <iostream>

#include <cmath>
#include <algorithm>

GameController::GameController()
{
	InitWindow(screen_width, screen_height, title);
	SetTargetFPS(60);
	InitAudioDevice();

	player.Init();
}

GameController::~GameController()
{
	CloseAudioDevice();
	CloseWindow();
	player.~Player();
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
	player.Move();

	enemy_spawn_timer += GetFrameTime();

	if (enemy_spawn_timer >= enemy_spawn_interval &&
		enemies.size() < max_enemies) 
	{
		CreateEnemy();
		enemy_spawn_timer = 0.0f;
	}
	// Test
	std::cout << "Cantidad de enemigos activos " << enemies.size()<< std::endl;
	
	for (auto e : enemies )
	{
		e->Update();
		e->Aim(player);

		if (e->ReadyToAttack())
		{
			e->Attack(projectiles);
		}
	}

	for (auto& pro : projectiles)
	{
		pro.Update();
	}

	CheckPlayerCollisions();
	
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

	player.Draw();
	
	
	for (auto& e : enemies) {
		e->Draw();
	}

	for (auto& pro : projectiles)
	{
		pro.Draw();
	}
	
	// Finalizamos el dibujo
	EndDrawing();
}

Vector2 GameController::GetRandomSpawnPosition()
{
	float x;
	float y;

	x = (float)GetScreenWidth() + 100.0f;
	y = (float)GetRandomValue(0, GetScreenHeight() - 120);

	return {x,y};
}

void GameController::CreateEnemy()
{
	if (enemies.size() < max_enemies)
	{

		// creamos una X fija fuera de pantalla
		// ademas de una Y temporal
		float spawnX = (float)GetScreenWidth() + 100.0f;
		Enemy* nuevo_enemy = new Enemy({ spawnX, 0.0f }, {70,0});

		//con el objeto creado, podemos saber si altura
		float enemy_height = nuevo_enemy->GetEnemyHeigth();

		// con su altura podemos calcular la cordena maxima en Y
		// para su spawn
		int y_max = (int)(GetScreenHeight() - enemy_height);

		// evitamos que y_max sea menor a 0
		float final_y = (float)GetRandomValue(0, (y_max > 0 ? y_max : 0));
		
		// lo ubicamos en su posicion final
		nuevo_enemy->SetPos({ spawnX,final_y });

		enemies.push_back(nuevo_enemy);
	}

}

void GameController::DeleteInactiveEnemies()
{
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

void GameController::CheckPlayerCollisions()
{
	for (auto& pro : projectiles)
	{
		if (!pro.IsActive()) continue;

		float offSet = 6.0f; // margen de impacto

		//Definimos los bordes del player, su hitbox.
		float playerLeft = player.GetPos().x + offSet;
		float playerRight = (player.GetPos().x + player.GetWidth()) - offSet;
		float playerTop = player.GetPos().y;
		float playerBottom = (player.GetPos().y + player.GetHeight()) - offSet;
		
		//Punto mas cercano al circulo dentro del rect.
		float closestX = std::clamp(pro.GetProPos().x,
							playerLeft,
							playerRight);

		float closestY = std::clamp(pro.GetProPos().y,
							playerTop,
							playerBottom);


		// Distancia entre el centro del ciruclo y wl punto cercano.

		float distancePlayer = (pro.GetProPos().x - closestX) * 
								(pro.GetProPos().x - closestX) +
								(pro.GetProPos().y - closestY) *
								(pro.GetProPos().y - closestY);

		// Comprobar colision.
		if (distancePlayer < (pro.GetRadius() * pro.GetRadius()))
		{
			pro.SetActive(false);

			std::cout << "Impacto al player" << std::endl;
		}

	}

}


