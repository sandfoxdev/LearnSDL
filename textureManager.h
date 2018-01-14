// textureManaher.h

#ifndef TEXTURE_MANAGER_H
#define TEXTURE_MANAGER_H

#include "SDL2/SDL.h"
#include "SDL2/SDL_image.h"
#include <string>

class TextureManager{

	public:
		bool load(std::string fileName, std::string id, SDL_Renderer* pRenderer);
		// Draw
		void draw(std::string id,
				int x,
				int y,
				int width,
				int height,
				SDL_Renderer* pRenderer,
				SDL_RendererFlip flip = SDL_FLIP_NONE);
		// DrawFrame
		void drawFrame(std::string id,
				int x,
				int y,
				int width,
				int height,
				int currentRow,
				int currentFrame,
				SDL_Renderer* pRenderer,
				SDL_RendererFlip flip = SDL_FLIP_NONE);

		std::map<std::string, SDL_Texture*> m_textureMap;
		
}


#endif
