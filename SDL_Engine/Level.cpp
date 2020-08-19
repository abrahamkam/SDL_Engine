#include "Level.h"



Level::Level(const char* backgroundPath, std::vector<Sprite*> spriteList, int screenWidth, int screenHeight) : sprites{spriteList}
{
	background = TextureManager::LoadTexture(backgroundPath);
}

void Level::addSprite(Sprite* sprite) {
	sprites.push_back(sprite);
}
void Level::removeSprite(Sprite* sprite) {
	for (Sprite* sprite : sprites) {

	}
}
void Level::drawLevel() const{
	for (Sprite* sprite : sprites) {
		sprite->draw();
	}
	TextureManager::Draw(background, NULL, NULL);
}
Level::~Level()
{

}
