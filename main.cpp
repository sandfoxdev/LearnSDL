// main.cpp

#include "game.h"
#include <iostream>	
#include "sdlGameObject.h"

// Our Game object
Game* g_game = 0;

int main(int argc, char* argv[]){
	std::cout << "Game init attempt..." << std::endl;
	if(TheGame::Instance() -> init("Chapter 1", 100, 100, 640, 420, false)){
		std::cout << "Game init success!" << std::endl;
		while(TheGame::Instance() -> running()){
			TheGame::Instance() -> handleEvents();
			TheGame::Instance() -> update();
			TheGame::Instance() -> render();
		
			SDL_Delay(10);
		}
	}
	else{
		std::cout << "Game init failure - " << SDL_GetError() << std::endl;
		return -1;
	}

	std::cout << "Game closing..." << std::endl;
	TheGame::Instance() -> clean();
	
	return 0;
}
