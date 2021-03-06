#include "basicFunctionalities.h"

bool init() {
	if (SDL_Init(SDL_INIT_VIDEO) < 0) {
		std::cout << "Could not INIT SDL: " << SDL_GetError() << std::endl;
		return false;
	}
	gWindow = SDL_CreateWindow("Cloth Simulation",SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED,SCREEN_WIDTH,SCREEN_HEIGHT,SDL_WINDOW_SHOWN);
	if (gWindow == NULL) {
		std::cout << "Window Creation Error: "<<SDL_GetError() << std::endl;
		return false;
	}
	gRenderer = SDL_CreateRenderer(gWindow,-1,SDL_RENDERER_ACCELERATED|SDL_RENDERER_PRESENTVSYNC);
	if (gWindow == NULL) {
		std::cout << "Renderer Creation Error: " << SDL_GetError() << std::endl;
		return false;
	}
	return true;
}

void close() {
	SDL_DestroyRenderer(gRenderer);
	SDL_DestroyWindow(gWindow);
	gWindow = NULL;
	gRenderer = NULL;
	SDL_Quit();
}

void handelUserInput(SDL_Event* e) {
	//For single Key Press
	if (e->type == SDL_KEYDOWN && e->key.repeat == 0) {
		switch (e->key.keysym.sym) {
		case SDLK_ESCAPE:std::cout << "testing ......" << std::endl; break;//testing__(delete later)
		}
	}
}