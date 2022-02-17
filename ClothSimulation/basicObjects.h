#pragma once
#include <SDL.h>
#include "globalVariables.h"
#include <iostream>

class Point {
public:
	Point(float _x, float _y,float _oldX,float _oldY,bool _pinned=false);
	void update();
	void render();

	float x;
	float y;
	bool pinned;
private:
	int width;
	int height;

	float oldX;
	float oldY;

	//Some Forces of nature
	float bounce;//friction to slow down the object
	float friction;
	float gravity;

	SDL_Rect pointBody;
};

class Stick {
public:
	Stick(Point *_p0,Point *_p1);
	void update();
	void render();
	float distance();
private:
	Point *p0;
	Point *p1;
	float length;
};
