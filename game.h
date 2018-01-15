// game.h

#ifndef GAME_H
#define GAME_H

#include "SDL2/SDL.h"
#include "SDL2/SDL_image.h"
#include "textureManager.h"

class Game{

	public:
		Game(){}
		~Game(){}	
	
		// Simply set the running variable to true
		bool init(const char* title, int xpos, int ypos, int width, int height, bool fullscreen);
		void render();
		void update();
		void handleEvents();
		void clean();

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
};





#endif
