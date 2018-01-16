// enemy.h

#ifndef ENEMY_H
#define ENEMY_H

#include <SDL2/SDL.h>
#include "gameObject.h"
#include <string>
#include "sdlGameObject.h"

class Enemy : public SDLGameObject{
	
	public:
		Enemy(const LoaderParams* pParams);
			
		virtual void draw();
		virtual void update();
		virtual void clean();
};

#endif
