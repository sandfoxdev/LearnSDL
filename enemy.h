// enemy.h

#ifndef ENEMY_H
#define ENEMY_H

#include <SDL2/SDL.h>
#include "gameObject.h"
#include <string>


class Enemy : public GameObject{
	
	public:
		void load(int x, int y, int width, int height, std::string textureID);
		void draw(SDL_Renderer* pRenderer);
		void update();
		void clean();
};

#endif
