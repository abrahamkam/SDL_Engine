#include "AnimatedSprite.h"
#include "TextureManager.h"
#include <iostream>
SDL_Rect dipshitRect;

AnimatedSprite::AnimatedSprite(const char* texture, int w, int h, int x, int y, int frameHeight, int frameWidth, int numFrames, int ticksPerFrame) : Sprite{ texture,w,h,x,y }
{
	this->ticksPerFrame = ticksPerFrame;
	this->frameHeight = frameHeight;
	this->frameWidth = frameWidth;
	frameCount = numFrames;
	dipshitRect.h = frameHeight;
	dipshitRect.w = frameWidth;
	dipshitRect.y = 0;
	dipshitRect.x = 0;
}

void AnimatedSprite::draw() {
	if (numTicks % ticksPerFrame == 0) {
		std::cout << "leeeeel" << std::endl;
		if (dipshitRect.x >= frameWidth * frameCount) {
			dipshitRect.x = 0;
			std::cout << "zeroed" << std::endl;
		}
		else {
			std::cout << "moved" << std::endl;
			dipshitRect.x += frameWidth;
			std::cout << "X: " << dipshitRect.x << std::endl;
		}
	}
	TextureManager::Draw(spriteText, &dipshitRect, &spriteRect);
	numTicks++;
}

AnimatedSprite::~AnimatedSprite()
{
}
