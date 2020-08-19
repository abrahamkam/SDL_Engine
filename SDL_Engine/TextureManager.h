#pragma once
#include "SDL.h"
class TextureManager
{
public:
	TextureManager();
	static SDL_Texture* LoadTexture(const char* texture);
	static void Draw(SDL_Texture* texture,const SDL_Rect* srcRect, const SDL_Rect* destRect);

	~TextureManager();
};

