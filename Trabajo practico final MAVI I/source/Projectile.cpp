#include "Projectile.h"
#include <iostream>

Projectile::~Projectile()
{
	std::cout << "DEBUG: Proyectil en X: " << pos.x << 
								 " en Y: " << pos.y <<
				" eliminada. Eliminado de memoria." <<
					std::endl;
}

bool Projectile::IsActive() const
{
	return active && lifeTime > 0;
}

void Projectile::SetActive(bool _status)
{
	active = _status;
}

Vector2 Projectile::GetProPos() const
{
	return pos;
}

bool Projectile::IsFromPlayer()
{
	return isFromPlayer;
}

Vector2 Projectile::GetProDir() const
{
	return direction;
}



