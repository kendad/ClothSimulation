#include "clothObject.h"

Cloth::Cloth() {
	//creating the points
	for (int y = 100; y < SCREEN_HEIGHT - 100; y += 40) {
		for (int x = 100; x < SCREEN_WIDTH - 100; x += 40) {
			if (y==100) { 
				Point tmpPoint = Point(x, y, x, y, true);
				pointsVector.push_back(tmpPoint);
			}
			else {
				Point tmpPoint = Point(x, y, x, y);
				pointsVector.push_back(tmpPoint);
			}
		}
	}
	int size = (SCREEN_WIDTH - 100 - 100) / 40;
	std::cout << (SCREEN_WIDTH -100-100)/40 << std::endl;
	//creating the lines
	for (int i = 0; i < (pointsVector.size()-size)-1; i++) {
		Stick tmpStick1 = Stick(&pointsVector[i], &pointsVector[i + 1]);
		Stick tmpStick2 = Stick(&pointsVector[i+1], &pointsVector[(i+1)+size]);
		Stick tmpStick3 = Stick(&pointsVector[(i + 1) + size], &pointsVector[i + size]);
		Stick tmpStick4 = Stick(&pointsVector[i + size], &pointsVector[i]);
		sticksVector.push_back(tmpStick1);
		sticksVector.push_back(tmpStick2);
		sticksVector.push_back(tmpStick3);
		sticksVector.push_back(tmpStick4);
	}
}


void Cloth::update() {
	for (int i = 0; i < pointsVector.size(); i++) {
		pointsVector[i].update();
	}
	for (int i = 0; i < sticksVector.size(); i++) {
		sticksVector[i].update();
	}
	int tmpX, tmpY;
	SDL_GetMouseState(&tmpX,&tmpY);
	pointsVector[pointsVector.size()-1].x = tmpX;
	pointsVector[pointsVector.size() - 1].y = tmpY;
}

void Cloth::render() {
	/*for (int i = 0; i < pointsVector.size(); i++) {
		pointsVector[i].render();
	}*/
	for (int i = 0; i < sticksVector.size(); i++) {
		sticksVector[i].render();
	}
}