#pragma once
#include "Sprite.h"
class MovableSprite :
	public Sprite
{
public:
	MovableSprite(const char* texture, int w, int h, int x, int y);
	void move(int x, int y);
	~MovableSprite();
};

