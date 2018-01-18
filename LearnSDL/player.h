// player.h

#ifndef PLAYER_H
#define PLAYER_H

#include "SDL.h"
#include "gameObject.h"
#include "loaderParams.h"
#include "sdlGameObject.h"

// Inheritj from GameObject
class Player : public SDLGameObject{

	public:
		Player(const LoaderParams* pParams);
		
		virtual void draw(); 
		virtual void update();
		virtual void clean();

};	


#endif	
