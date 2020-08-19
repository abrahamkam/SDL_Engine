#pragma once
#include "SDL.h"
#include <vector>
#include <iostream>
#include "Sprite.h"
#include "SDL_image.h"
#include "Level.h"
#include <map>

class Game
{
public:
	Game(const char* title, int xpos, int ypos, int width, int height, int FPS, bool fullscreen);
	void init();
	//void AddSprite(Sprite* sprite);
	//void RemoveSprite(Sprite* sprite);
	SDL_Renderer* getRenderer() {
		return renderer;
	}
	void installShortCut(void *(*)(SDL_Keysym*), SDL_Keysym);
	void run();
	void loadLevel(const Level* level);
	static SDL_Renderer* renderer;
	~Game();

private:
	std::map<SDL_Keysym, void *(*)(SDL_Keysym*)> shortCuts;
	const Level* currentLevel;
	const int FPS;
	const int frameDelay = 1000 / FPS;
	Uint32 frameStart;
	int frameTime;
	//std::vector<Sprite*> sprites;
	std::vector<Sprite*> checkCollissions();
	void gameLoop();
	void handleEvents();
	void update();
	void render();
	void clean();
	bool running() { return isRunning; };
	bool isRunning;
	SDL_Window*window;
};

