// inputHandler.h

#ifndef INPUT_HANDLER_H
#define INPUT_HANDLER_H

#include "SDL.h"
#include <vector>
#include "vector2D.h"


class InputHandler {

	public:

		static InputHandler* Instance() {
			if (s_pInstance == 0) {
				s_pInstance = new InputHandler();
			}
			return s_pInstance;
		}

		void update();
		void clean();

		void initializeJoysticks();
		bool joysticksInitialized() { return m_bJoysticksInitialized; }

		int xvalue(int joy, int stick);
		int yvalue(int joy, int stick);

	private:

		InputHandler();
		~InputHandler() {};

		std::vector<std::pair<Vector2D*, Vector2D*>> m_joystickValues;

		static InputHandler* s_pInstance;

		std::vector<SDL_Joystick*> m_joysticks;
		bool m_bJoysticksInitialized;
};

typedef InputHandler TheInputHandler;


#endif
