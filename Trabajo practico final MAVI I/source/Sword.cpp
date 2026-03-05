#include "Sword.h"

void Sword::Update()
{
	
	lifeTime -= GetFrameTime();
	

	if (lifeTime <= 0)
	{
		SetActive(false);
	}

}

void Sword::Draw()
{
	Rectangle box = GetHitbox();

	DrawRectangleRec(box, Fade(BLUE, 0.5f));
}

Rectangle Sword::GetHitbox()
{
	float anchoAtaque = 80.0f;
	float altoAtaque = 40.0f;
	float offsetX = 0;

	if (ownerDir->x < 0) {
		offsetX =- anchoAtaque;
	}
	else {
		offsetX = 50.0f;
	}

	return 
	{
		pos.x + offsetX,
		pos.y + 40.0f,
		anchoAtaque,
		altoAtaque,
	};
}


