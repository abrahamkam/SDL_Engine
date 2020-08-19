#pragma once
#include <vector>
#include "Sprite.h"
#include <SDL_image.h>
#include "TextureManager.h"
class Level
{
public:
	Level(const char* background, std::vector<Sprite*> sprites, int screenWidth, int screenHeight);
	void drawLevel() const;
	const std::vector<Sprite*> getSprites() const{
		return sprites;
	}
	void addSprite(Sprite* sprite);
	void removeSprite(Sprite* sprite);
	~Level();
private:
	std::vector<Sprite*> sprites;
	SDL_Texture* background;
};

