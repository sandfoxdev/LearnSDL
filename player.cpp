// player.cpp

#include "player.h"
#include <string>
#include "sdlGameObject.h"

Player::Player(const LoaderParams* pParams) : SDLGameObject(pParams){ }

void Player::draw(){
	// We now use SDLGameObject
	SDLGameObject::draw();
}

void Player::update(){
	m_x -= 1;
	m_currentFrame = int(((SDL_GetTicks() / 100) % 6));
}

void Player::clean(){ }
