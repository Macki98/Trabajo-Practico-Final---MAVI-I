#pragma once
#include "raylib.h"
#include "raymath.h"

class Projectile
{
protected:

	Vector2 pos;
	
	float lifeTime;

	bool active;

	bool hasHit = false;

public:

	Projectile(Vector2 _StartPos,
		float _life) :
		pos(_StartPos),
		lifeTime(_life),
		active(true)
	{
	};
	
	virtual ~Projectile();


	virtual void Update() = 0;
	virtual void Draw() = 0;
	virtual Rectangle GetHitbox() = 0;
	
	
	bool IsActive() const; // bandera que dermina si esta activo o si debe ser eliminado
	
	
	void SetActive(bool _status); // Seteamos la bandera
	Vector2 GetProPos() const;
	
	bool GetHasHit();
	void SetHasHit(bool _status);

};

