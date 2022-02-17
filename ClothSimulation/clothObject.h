#pragma once
#include "basicObjects.h"
#include <vector>

class Cloth {
public:
	Cloth();
	void update();
	void render();
private:
	std::vector<Point> pointsVector;
	std::vector<Stick> sticksVector;
};