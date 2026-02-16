#pragma once
#include "raylib.h"
#include "raymath.h"

class Projectile
{
private:

	Vector2 pos;
	Vector2 dir;
	float r;

	float speed;

	bool active;

public:

	Projectile(	Vector2 _StartPos, 
				Vector2 _Target,
				float _spd);
	~Projectile();


	void Update();
	void Draw();
	
	bool IsActive() const;
	void SetActive(bool _status);
	Vector2 GetProPos() const;
	float GetRadius() const;

};

