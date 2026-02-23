#include "Sword.h"

void Sword::Update()
{
	lifeTime -= GetFrameTime();

	if (ownerPos != nullptr)
	{
		pos = *ownerPos;
	}

}

void Sword::Draw()
{
	DrawRectangleV({ pos.x - 20, pos.y + 10 }, 
					{ 80,30 }, 
					Fade(SKYBLUE, 0.6f));
}


