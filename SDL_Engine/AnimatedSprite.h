#pragma once
#include "Sprite.h"
class AnimatedSprite :
	public Sprite
{
public:
	
	~AnimatedSprite();
	virtual void draw();
	static AnimatedSprite* AnimatedSpriteFactory(const char* texture, int h, int w, int x, int y, int frameHeight, int frameWidth, int numFrames, int ticksPerFrame) {
		return new AnimatedSprite(texture, w, h, x, y, frameHeight, frameWidth, numFrames, ticksPerFrame);
	}
protected:
	AnimatedSprite(const char* texture, int w, int h, int x, int y, int frameHeight, int frameWidth, int numFrames, int ticksPerFrame);
private:
	int frameCount,ticksPerFrame,frameWidth,frameHeight;
	Uint32 numTicks;

};

