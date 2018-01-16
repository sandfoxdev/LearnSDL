// game.h

#ifndef GAME_H
#define GAME_H

#include "SDL2/SDL.h"
#include "SDL2/SDL_image.h"
#include "textureManager.h"
#include "gameObject.h"
#include "player.h"
#include "enemy.h"
#include <vector>

class Game{

	public:

		// Create the public instance function
		static Game* Instance(){
			if(s_pInstance == 0){
				s_pInstance = new Game();
				return s_pInstance;
			}
			return s_pInstance;
		}
		
		//Game(){}
		//~Game(){}	
	
		// Simply set the running variable to true
		bool init(const char* title, int xpos, int ypos, int width, int height, bool fullscreen);
		void render();
		void update();
		void handleEvents();
		void clean();

		SDL_Renderer* getRenderer() const {return m_pRenderer;}

		// a function to access the private running variable
		bool running() {return m_bRunning;}

	private:
		bool m_bRunning;

		SDL_Window* m_pWindow;
		SDL_Renderer* m_pRenderer;
		
		// The new SDL_Texture variable
		SDL_Texture* m_pTexture;
		// The first rectaingle
		SDL_Rect m_sourceRectangle;
		// Another rectaingle
		SDL_Rect m_destinationRectangle;

		int m_currentFrame;
		//TextureManager m_textureManager;

		GameObject* m_go;
		GameObject* m_player;
		GameObject* m_enemy;		

		std::vector<GameObject*> m_gameObjects;

		//GameObject* m_player;
		//GameObject* m_enemy1;
		//GameObject* m_enemy2;
		//GameObject* m_enemy3;		

		
		Game();
		~Game();
		// Create the s_pInstance member variable
		static Game* s_pInstance;

};

// Create the typedef
typedef Game TheGame;



#endif
