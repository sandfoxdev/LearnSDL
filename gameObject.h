// gameObject.h

#include <string>
#include <SDL2/SDL.h>

class GameObject{

	public:
		void load(int x, int y, int width, int height, std::string textureID);
		void draw(SDL_Renderer* pRenderer);  //{std::cout << "draw game object";}
		void update();   //{std::cout << "update game object";}
		void clean();  //{std::cout << "clean game object";}
	
	protected:
		
		std::string m_textureID;

		int m_currentFrame;
		int m_currentRow;
		
		int m_x;
		int m_y;

		int m_width;
		int m_height;

};
