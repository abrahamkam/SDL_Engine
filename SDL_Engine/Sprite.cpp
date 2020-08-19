#include "Sprite.h"
#include "TextureManager.h"


Sprite::Sprite(const char* texture, int w, int h, int x, int y)
{
	spriteText = TextureManager::LoadTexture(texture);
	spriteRect = SDL_Rect();
	spriteRect.h = h;
	spriteRect.w = w;
	spriteRect.x = x;
	spriteRect.y = y;
}


bool Sprite::checkCollision(const Sprite* otherSprite) {
	if (otherSprite == this)
		return false;
	const SDL_Rect* otherRect = otherSprite->getSpriteRect();
	int rightEdge = spriteRect.x + spriteRect.w;
	int bottomEdge = spriteRect.y + spriteRect.h;
	int otherRightEdge = otherRect->x + otherRect->w;
	int otherBottomEdge = otherRect->y + otherRect->h;

	if (rightEdge >= otherRect->x &&
		bottomEdge >= otherRect->y &&
		spriteRect.x <= otherRightEdge &&
		spriteRect.y <= otherBottomEdge)
		return true;
	else
		return false;
}

void Sprite::draw() {
	TextureManager::Draw(spriteText, nullptr, &spriteRect);
}

void Sprite::place(int x, int y) {
	spriteRect.x = x;
	spriteRect.y = y;
}
void Sprite::tick(SDL_Event & event)
{
	switch (event.type)
	{
	case SDL_MOUSEBUTTONDOWN:
		spriteRect.x += 5;
	default:
		break;
	}
}
Sprite::~Sprite()
{
	SDL_DestroyTexture(spriteText);
}
