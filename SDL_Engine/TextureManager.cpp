#include "TextureManager.h"
#include "SDL_image.h"
#include <iostream>
#include "Game.h"

TextureManager::TextureManager()
{
}

SDL_Texture* TextureManager::LoadTexture(const char* texture) {
	std::cout << texture << std::endl;
	SDL_Surface* tmpsurface = IMG_Load(texture);
	if (!tmpsurface) {
		std::cout << "woopsie daisy" << std::endl;
	}
	SDL_Texture* tmpTex = SDL_CreateTextureFromSurface(Game::renderer, tmpsurface);
	if (!tmpTex) {
		std::cout << "lel fail" << std::endl;
	}
	else {
		std::cout << "worked I guess";
	}
	SDL_FreeSurface(tmpsurface);
	return tmpTex;
}

void TextureManager::Draw(SDL_Texture* texture, const SDL_Rect* sRect,const SDL_Rect* dRect) {
	
	SDL_RenderCopy(Game::renderer, texture, sRect, dRect);
	
}
TextureManager::~TextureManager()
{
}
