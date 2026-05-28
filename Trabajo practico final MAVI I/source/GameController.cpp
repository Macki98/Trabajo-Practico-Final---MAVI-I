#include "GameController.h"
#include <iostream>

#include <cmath>
#include <algorithm>

#include "EnemyShooter.h"


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


	//Limpieza de vector de enemigos
	for (int i = 0; i < enemies.size(); i++)
	{
		delete enemies[i];
	}
	enemies.clear();

	//Limpieza de vector de proyectiles
	for (int i = 0; i < projectiles.size(); i++)
	{
		delete projectiles[i];
	}
	projectiles.clear();

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
	
	UpdateEnemies();
	UpdateProjectiles();

	player.CheckDamage(projectiles);
	
	DeleteInactiveProjectiles();
	DeleteInactiveEnemies();
	
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

		DrawText(TextFormat("Enemigo 0 en: X:%.2f Y:%.2f", e->GetEnemyPos().x, e->GetEnemyPos().y),10,50,20,RED);
	}

	for (auto& pro : projectiles)
	{
		pro->Draw();
		DrawRectangleLinesEx(pro->GetHitbox(), 2, GREEN);
	}
	
	// Finalizamos el dibujo
	EndDrawing();
}


void GameController::CreateEnemy()
{
	if (enemies.size() < max_enemies)
	{

		// Seleccionamos que enemigo crear

		Enemy* nuevo_enemy = nullptr;
		// creamos una X fija fuera de pantalla
		// ademas de una Y temporal
		float spawnX = (float)GetScreenWidth() + 100.0f;
		Vector2 initialDir = { -1.0f,0.0f };

		nuevo_enemy = new EnemyShooter({ spawnX,0.0f }, initialDir);
		
		// Posicionamos de manera segura al enemigo
		// con el objeto creado, podemos saber su altura
		float enemy_height = nuevo_enemy->GetEnemyHeigth();

		// con su altura podemos calcular la cordena maxima en Y
		// para su spawn
		// evitamos que y_max sea menor a 0
		// lo ubicamos en su posicion final
		int y_max = (int)(GetScreenHeight() - enemy_height);
		float final_y = (float)GetRandomValue(0, (y_max > 0 ? y_max : 0));

		nuevo_enemy->SetPos({ spawnX, final_y });

		// Registramos al enemigo.
		enemies.push_back(nuevo_enemy);
	}

}

void GameController::UpdateEnemies()
{
	for (auto e : enemies)
	{
		e->Aim(player.GetPos());
		e->Update(player.GetPos());

		if (e->ReadyToAttack(player.GetPos()))
		{
			e->Attack(projectiles);
		}
	}
}

void GameController::UpdateProjectiles()
{
	for (Projectile* pro : projectiles)
	{
		pro->Update();
	}
}

void GameController::DeleteInactiveEnemies()
{
	for (auto enemy = enemies.begin(); enemy != enemies.end();)
	{
		if ((*enemy)->GetEnemyPos().x < -100.0f)
		{
			delete *enemy;

			enemy = enemies.erase(enemy);

			std::cout << "DEBUG: Enemigo eliminado de memoria." << std::endl;
		}
		else {
			++enemy++;
		}
	}
}

void GameController::DeleteInactiveProjectiles()
{
	for (auto projectile = projectiles.begin(); 
			  projectile != projectiles.end();)
	{
		if (!(*projectile)->IsActive())
		{
			delete* projectile;
			projectile = projectiles.erase(projectile);
		}
		else
		{
			++projectile;
		}
	}
}


