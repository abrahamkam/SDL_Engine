#pragma once
#include <SDL.h>
#include <vector>

class Sprite
{
public:
	std::vector<Sprite*> collissions;
	SDL_Texture* getSpriteTex() const{
		return spriteText;
	};
	const SDL_Rect* getSpriteRect() const{
		return &spriteRect;
	}
	static Sprite* spriteFactory(const char* texture, int h, int w, int x, int y) {
		return new Sprite(texture, h, w, x, y);
	}
	virtual void tick(SDL_Event& event);
	virtual void draw();
	bool checkCollision(const Sprite* otherSprite);
	~Sprite();
protected:
	Sprite(const char* texture, int h, int w, int x, int y);
	void place(int x, int y);
	Sprite(const Sprite&) = delete;
	Sprite& operator=(const Sprite&) = delete;
	SDL_Rect spriteRect;
	SDL_Texture* spriteText;
private:
	
};