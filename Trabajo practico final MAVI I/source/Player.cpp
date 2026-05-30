#include "Player.h"

#include <iostream>

Player::Player()
{

	player = { pos.x,pos.y, 50, 120};
	aiming = false;
}

Player::~Player()
{
}

void Player::Init() {
	
	pos = {
	(float)GetScreenWidth() / 2, // X
	(float)GetScreenHeight() / 2 // Y
	};

	dir = {
		200.0f, // Velocidada X
		0 // Velocidad Y
	};

}

void Player::Move(std::vector<Cover*>& covers)
{
	float deltaTime = GetFrameTime();
	float gravity = 450.0f;

	if (IsKeyPressed(KEY_E))
	{
		if (isCovered)
		{
			if (currentCover != nullptr)
			{
				currentCover->SetOccupied(false);
			}

			isCovered = false;
			currentCover = nullptr;
			player.height = normalHeight;
			
		}
		else
		{
			for (auto c : covers)
			{
				c->SetOccupied(true);

				Rectangle cRect = c->GetRect();

				Vector2 coverCenter = { cRect.x + cRect.width / 2.0f, cRect.y + cRect.height / 2.0f };
				
				Vector2 playerCenter = { pos.x + player.width / 2.0f, pos.y + player.height / 2.0f };
			
				if (Vector2Distance(playerCenter, coverCenter) <= interactionRange)
				{
					isCovered = true;
					currentCover = c;
					c->SetOccupied(true);

					if (cRect.height < this->normalHeight) 
					{
						player.height = cRect.height * 0.9f; // Nos encogemos un 10% más abajo que la cobertura
					}

					if (playerCenter.x < coverCenter.x)
					{
						pos.x = cRect.x - player.width;
					}
					else
					{
						pos.x = cRect.x + cRect.width;
					}
					// Alineamos la base de los rectángulos (suponiendo que el suelo es el mismo)
					pos.y = (cRect.y + cRect.height) - player.height;
				}
			}
		}
	}

	if (!isCovered)
	{
		if (IsKeyDown(KEY_A)) // Movimiento Izq
		{
			pos.x -= dir.x * deltaTime;
		}
		else if (IsKeyDown(KEY_D)) // Movimiento Der
		{
			pos.x += dir.x * deltaTime;
		}
	}

	if (pos.y >= GetScreenHeight() - player.height) // Impacto contra el limite inferior de la pantalla
	{
		pos.y = (GetScreenHeight() - player.height);
		dir.y = 0;
		Jump();
	}
	else // Aplicamos gravedad
	{
		dir.y += gravity * deltaTime;
	}

	pos.y += dir.y * deltaTime; // Actualizamos la posicion segun la fuerza de gravedad
	
	player.x = pos.x;
	player.y = pos.y;
}


void Player::Jump()
{
	if (IsKeyPressed(KEY_SPACE)) // Salto con Barra espaciadora
	{
		dir.y = -350.0f;
	}
}

void Player::Shoot(std::vector<Projectile*>& projectiles)
{
	if (IsMouseButtonDown(MOUSE_BUTTON_RIGHT))
	{
		mousePos = GetMousePosition();
		aiming = true;
	}
	else
	{
		aiming = false;
	}

	if (aiming && IsMouseButtonPressed(MOUSE_BUTTON_LEFT))
	{
		Vector2 direction = Vector2Subtract(mousePos, pos);
		direction = Vector2Normalize(direction);

		projectiles.push_back(new Bullet(pos, direction, true));

		std::cout << "DEBUG: Player disparando" << std::endl;
	}
}

void Player::Draw() // Dibujamos el personaje en pantalla
{
	DrawRectangleLines(
		pos.x, 
		pos.y, 
		player.width, 
		player.height, 
		GREEN);
}

Vector2 Player::GetPos() const
{
	return pos;
}



bool Player::IsCovered() const
{
	return isCovered;
}

Cover* Player::GetCurrentCover() const
{
	return currentCover;
}

void Player::CheckDamage(std::vector<Projectile*>& projectiles)
{
	for (Projectile* p : projectiles) {

		if (p->IsActive() && !p->IsFromPlayer()) {

			if (CheckCollisionRecs(player, p->GetHitbox())) 
			{
				std::cout << "El jugador recibio daño" << std::endl;
				p->SetActive(false);
			}
		}
	}
}

float Player::GetWidth() const
{
	return player.width;
}

float Player::GetHeight() const
{
	return player.height;
}


