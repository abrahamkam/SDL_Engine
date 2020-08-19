#include "MovableSprite.h"



MovableSprite::MovableSprite(const char* texture, int w, int h, int x, int y) : Sprite{texture,w,h,x,y }
{

}

void MovableSprite::move(int dx, int dy) {
	spriteRect.x += dx;
	spriteRect.y += dy;
}

MovableSprite::~MovableSprite()
{
}
