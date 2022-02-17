#include "basicFunctionalities.h"
#include "basicObjects.h"
#include "clothObject.h"
#include <vector>
#undef main


void main() {
	if (!init()) {
		std::cout << "INIT FAILED" << std::endl;
		return;
	}

	bool quit = false;
	SDL_Event e;

	Cloth cloth;

	//game loop
	while (!quit) {
		//HANDEL USER INPUT
		while (SDL_PollEvent(&e) != 0) {
			if (e.type == SDL_QUIT) quit = true;
			handelUserInput(&e);
		}
		
		//clears the screen
		SDL_SetRenderDrawColor(gRenderer,0,0,0,255);
		SDL_RenderClear(gRenderer);

		//draw stuff here
		cloth.update();
		cloth.render();

		//Update the screen
		SDL_RenderPresent(gRenderer);
	}
}
