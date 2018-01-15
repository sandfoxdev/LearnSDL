// player.h


#include "SDL2/SDL.h"
#include "gameObject.h"

// Inheritj from GameObject
class Player : public GameObject{

	public:
		void load(int x, int y, int width, int height, std::string textureID);
		void draw(SDL_Renderer* pRenderer);  //{GameObject::draw(); std::cout << "draw player";}
		void update();  //{std::cout << "update player"; m_x = 10; m_y = 20;}
		void clean();  //{GameObject::clean(); std::cout << "clean player";}

};		
