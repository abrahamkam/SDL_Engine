#include "Game.h"
#include <iostream>

SDL_Renderer* Game::renderer = nullptr;

Game::Game(const char* title, int xpos, int ypos, int width, int height, int FPS, bool fullscreen) :FPS{ FPS }
{
	
	int flags = 0;
	if (fullscreen) {
		flags = SDL_WINDOW_FULLSCREEN;
	}

	if (SDL_Init(SDL_INIT_EVERYTHING) == 0) {

		std::cout << "Subsystems Initialized" << std::endl;
		window = SDL_CreateWindow(title, xpos, ypos, width, height, flags);
		renderer = SDL_CreateRenderer(window, -1, 0);
		if (renderer) {
			SDL_SetRenderDrawColor(Game::renderer, 255, 255, 255, 255);
			std::cout << "Renderer up" << std::endl;
			if (IMG_Init(IMG_INIT_PNG) == IMG_INIT_PNG) {
				std::cout << "img inited" << std::endl;
			}
		}
		isRunning = true;

	}
	else {
		isRunning = false;
	}
	
}

void Game::init() {
	gameLoop();
}
/*
void Game::AddSprite(Sprite* sprite)
{
	sprites.push_back(sprite);
}

void Game::RemoveSprite(Sprite* sprite)
{
}
*/
void Game::loadLevel(const Level* level){
	/*sprites.clear();
	for (Sprite* sprite : level->getSprites()) {
		sprites.push_back(sprite);
	}*/
	currentLevel = level;
}

std::vector<Sprite*> Game::checkCollissions()
{
	return std::vector<Sprite*>();
}

void Game::gameLoop() {
	while (isRunning) {
		frameStart = SDL_GetTicks();
		handleEvents();
		update();
		render();
		frameTime = SDL_GetTicks() - frameStart;
		if (frameDelay > frameTime) {
			SDL_Delay(frameDelay - frameTime);
		}
	}
	clean();
}

void Game::handleEvents() {

	SDL_Event event;
	SDL_PollEvent(&event);

	for (Sprite* sprite : currentLevel->getSprites()) {
		for (Sprite* otherSprite : currentLevel->getSprites()) {
			if (sprite->checkCollision(otherSprite)) {
				std::cout << "Collision";
				sprite->collissions.push_back(otherSprite);
			}
		}
	}

	switch (event.type) {
	case SDL_QUIT:
		isRunning = false;
		break;
	default: 
		break;
	}
	for (Sprite* sprite : currentLevel->getSprites()) {
		sprite->tick(event);
		sprite->collissions.clear();
	}
};
void Game::update() {
	
};
void Game::render() {
	SDL_RenderClear(renderer);
	/*
	for (Sprite* sprite : sprites) {
		//SDL_RenderCopy(renderer, sprite->getSpriteTex(), NULL, sprite->getSpriteRect());
		sprite->draw();
	}
	*/
	currentLevel->drawLevel();
	SDL_RenderPresent(renderer);
};
void Game::clean() {
	SDL_DestroyWindow(window);
	SDL_DestroyRenderer(renderer);
	SDL_Quit();
	std::cout << "Cleaned up"<<std::endl;
};

Game::~Game()
{
	clean();
}
