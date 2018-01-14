// game.cpp

#include "game.h"
#include <iostream>

bool Game::init(const char* title, int xpos, int ypos, int width, int height, bool fullscreen){
	int flags = 0;
	if(fullscreen){
		flags = SDL_WINDOW_FULLSCREEN;
	}

	// Attempt to initialize SDL
	if(SDL_Init(SDL_INIT_EVERYTHING) == 0){
		std::cout << "SDL init success" << std::endl;
		// Init the window
		m_pWindow = SDL_CreateWindow(title, xpos, ypos, width, height, flags);
		if(m_pWindow != 0){
			// Window init success
			std::cout << " Window creation success" << std::endl;
			m_pRenderer = SDL_CreateRenderer(m_pWindow, -1, 0);
			if(m_pRenderer != 0){
				// Renderer init success
				std::cout << "Renderer creation success" << std::endl;
				SDL_SetRenderDrawColor(m_pRenderer, 0, 255, 0, 255);
			}
			else{
				// Render init fail
				std::cout << "Render init fail" << std::endl;
				return false;
			}
		}
		else{
			// Window init fail
			std::cout << "Window init fail" << std::endl;
			return false;
		}
	}
	else{
		// SDL init fail
		std::cout << "SDL init fail" << std::endl;
		return false;
	}

	std::cout << "Init success" << std::endl;
	// Everything inited successfully
	m_bRunning = true;
	// Start main loop
	

	//SDL_Surface* pTempSurface = SDL_LoadBMP("assets/rider.bmp");
	//m_pTexture = SDL_CreateTextureFromSurface(m_pRenderer, pTempSurface);
	//SDL_FreeSurface(pTempSurface);
	//SDL_QueryTexture(m_pTexture, NULL, NULL, &m_sourceRectangle.w, &m_sourceRectangle.h);	
	//m_destinationRectangle.x = m_sourceRectangle.x = 0;
	//m_destinationRectangle.y = m_sourceRectangle.y = 0;
	//m_destinationRectangle.w = m_sourceRectangle.w;
	//m_destinationRectangle.h = m_sourceRectangle.h;

	SDL_Surface* pTempSurface = IMG_Load("assets/animate-alpha.png");
	m_pTexture = SDL_CreateTextureFromSurface(m_pRenderer, pTempSurface);
	SDL_FreeSurface(pTempSurface);
	m_sourceRectangle.w = 128;
	m_sourceRectangle.h = 82;	
	m_destinationRectangle.x = m_sourceRectangle.x = 0;
	m_destinationRectangle.y = m_sourceRectangle.y = 0;
	m_destinationRectangle.w = m_sourceRectangle.w;
	m_destinationRectangle.h = m_sourceRectangle.h;

	return true;
}

void Game::update(){
	m_sourceRectangle.x = 128 * int(((SDL_GetTicks() / 100) % 6));
}

void Game::render(){
	// Clear the renderer to the draw color
	SDL_RenderClear(m_pRenderer);
	
	SDL_RenderCopyEx(m_pRenderer, m_pTexture, &m_sourceRectangle, &m_destinationRectangle, 0, 0, SDL_FLIP_HORIZONTAL);
	// SDL_RenderCopy(m_pRenderer, m_pTexture, NULL, NULL);
	
	// Draw to the screen
	SDL_RenderPresent(m_pRenderer);
}

void Game::handleEvents(){
	SDL_Event event;
	if(SDL_PollEvent(&event)){
		switch(event.type){
			case SDL_QUIT:
				m_bRunning = false;
				break;
			
			default:
				break;
		}
	}
}

void Game::clean(){
	std::cout << "Cleaning game" << std::endl;
	SDL_DestroyWindow(m_pWindow);
	SDL_DestroyRenderer(m_pRenderer);
	SDL_Quit();
}




