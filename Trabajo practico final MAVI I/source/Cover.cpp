#include "Cover.h"

Cover::Cover(Vector2 _pos, float _width, float _heigth)
{
	cover = { _pos.x, _pos.y, _width, _heigth };
}

Cover::~Cover()
{
}

Rectangle Cover::GetRect() const
{
	return cover;
}

bool Cover::IsOccupied() const
{
	return isOccupied;
}

void Cover::SetOccupied(bool _status)
{
	isOccupied = _status;
}

void Cover::Draw()
{
	DrawRectangleRec(cover, GRAY);
}