#include "basicFunctionalities.h"
#include "basicObjects.h"
#include <vector>
#undef main


void main() {
	if (!init()) {
		std::cout << "INIT FAILED" << std::endl;
		return;
	}

	bool quit = false;
	SDL_Event e;

	Point kelaPoint1 = Point(100,100,85,95);
	Point kelaPoint2 = Point(200,100,200,100);
	Point kelaPoint3 = Point(100, 200, 100, 200);
	Point kelaPoint4 = Point(200, 200, 200, 200);

	Point kelaPoint5 = Point(500, 100, 500, 100,true);
	Point kelaPoint6 = Point(450, 100, 450, 100);
	Point kelaPoint7 = Point(250, 100, 250, 100);
	std::vector<Point> pointObjectVector;
	pointObjectVector.push_back(kelaPoint1);
	pointObjectVector.push_back(kelaPoint2);
	pointObjectVector.push_back(kelaPoint3);
	pointObjectVector.push_back(kelaPoint4);
	pointObjectVector.push_back(kelaPoint5);
	pointObjectVector.push_back(kelaPoint6);
	pointObjectVector.push_back(kelaPoint7);

	Stick stick1 = Stick(&pointObjectVector[0],&pointObjectVector[1]);
	Stick stick2 = Stick(&pointObjectVector[1], &pointObjectVector[3]);
	Stick stick3 = Stick(&pointObjectVector[3], &pointObjectVector[2]);
	Stick stick4 = Stick(&pointObjectVector[2], &pointObjectVector[0]);
	Stick stick5 = Stick(&pointObjectVector[0], &pointObjectVector[3]);

	Stick stick6 = Stick(&pointObjectVector[5], &pointObjectVector[4]);
	Stick stick7 = Stick(&pointObjectVector[6], &pointObjectVector[5]);
	Stick stick8 = Stick(&pointObjectVector[0], &pointObjectVector[6]);
	std::vector<Stick> stickObjectVector;
	stickObjectVector.push_back(stick1);
	stickObjectVector.push_back(stick2);
	stickObjectVector.push_back(stick3);
	stickObjectVector.push_back(stick4);
	stickObjectVector.push_back(stick5);
	stickObjectVector.push_back(stick6);
	stickObjectVector.push_back(stick7);
	stickObjectVector.push_back(stick8);

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
		for (int i = 0; i < pointObjectVector.size(); i++) {
			pointObjectVector[i].update();
		}
		for (int i = 0; i < stickObjectVector.size(); i++) {
			stickObjectVector[i].update();
		}

		for (int i = 0; i < pointObjectVector.size(); i++) {
			pointObjectVector[i].render();
		}
		for (int i = 0; i < stickObjectVector.size(); i++) {
			stickObjectVector[i].render();
		}

		//Update the screen
		SDL_RenderPresent(gRenderer);
	}
}
