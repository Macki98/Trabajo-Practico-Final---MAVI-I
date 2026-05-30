#pragma once

#include "raylib.h"
class Cover
{
private:

	Rectangle cover;
	bool isOccupied = false;

public:

	Cover(Vector2 _pos, float _width, float _heigth);
	~Cover();

	Rectangle GetRect() const;

	bool IsOccupied() const;
	void SetOccupied(bool _status);

	void Draw();
};

