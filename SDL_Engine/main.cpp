#define SDL_MAIN_HANDLED
#include "SDL.h"
#include <stdio.h>
#include "Game.h"
#include "Sprite.h"
#include "AnimatedSprite.h"
#include <vector>
Game *game = nullptr;

int main(int argc, char *argv) {
	
	//std::vector<Sprite*> sprites;

	game = new Game("flurgs", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 600, 200, 10, false);
	Level* level = new Level("c:/Users/Thingy/source/repos/SDL_Engine/assets/anime.png", sprites, 600, 200);
	Sprite*sprite = AnimatedSprite::AnimatedSpriteFactory("c:/Users/Thingy/source/repos/SDL_Engine/assets/player.png", 40, 40, 100, 100, 16, 16, 1, 10);

	//game->AddSprite(AnimatedSprite::AnimatedSpriteFactory("c:/Users/Thingy/source/repos/SDL_Engine/assets/anime.png", 40, 40, 100, 100,16,16,1,10));
	//game->AddSprite(Sprite::spriteFactory("c:/Users/Thingy/source/repos/SDL_Engine/assets/anime.png", 40, 40, 100, 100));
	//game->AddSprite(Sprite::spriteFactory("assets/player.png", 40, 40, 105, 100));
	game->init();
	
	return 0;
}