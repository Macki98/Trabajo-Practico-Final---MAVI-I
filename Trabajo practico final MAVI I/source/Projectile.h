#pragma once
#include "raylib.h"
#include "raymath.h"

class Projectile
{
protected:

	Vector2 pos;
	Vector2 direction;
	
	float lifeTime;

	bool active;

	bool isFromPlayer;

public:

	Projectile(Vector2 _StartPos,
		Vector2 _dir,
		float _life,
		bool _isFromPlayer) :
		pos(_StartPos),
		direction(_dir),
		lifeTime(_life),
		active(true), 
		isFromPlayer (_isFromPlayer)
	{
	};
	
	virtual ~Projectile();


	virtual void Update() = 0;
	virtual void Draw() = 0;
	virtual Rectangle GetHitbox() = 0;
	
	
	bool IsActive() const; // bandera que dermina si esta activo o si debe ser eliminado
	
	
	void SetActive(bool _status); // Seteamos la bandera
	Vector2 GetProPos() const;
	
	bool IsFromPlayer();
	Vector2 GetProDir() const;

};

