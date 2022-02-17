#include "basicObjects.h"


//POINT OBJECT
Point::Point(float _x, float _y, float _oldX, float _oldY,bool _pinned) {
	x = _x;
	y = _y;
	width = 10;
	height = 10;
	oldX = _oldX;
	oldY = _oldY;

	pinned = _pinned;

	bounce = 0.9f;
	friction = 0.9f;
	gravity= 0.8f;
	pointBody = { (int)x,(int)y,width,height };
}

void Point::update() {
	if (!pinned) {
		float vx = x - oldX;
		float vy = y - oldY;

		oldX = x;
		oldY = y;

		x += vx;
		y += vy;
		y += gravity;

		//check for edges
		if (x > SCREEN_WIDTH) {
			x = SCREEN_WIDTH;
			oldX = x + vx * bounce;
		}
		else if (x < 0) {
			x = 0;
			oldX = x + vx * bounce;
		}
		else if (y + height > SCREEN_HEIGHT) {
			y = SCREEN_HEIGHT - height;
			oldY = y + vy * bounce * friction;
		}
		else if (y < 0) {
			y = 0;
			oldY = y + vy * bounce;
		}
		
		//update pointBody with latest X&Y vals
		pointBody.x = (int)x;
		pointBody.y = (int)y;
	}
	/*else {
		int tmpX;
		int tmpY;
		
		SDL_GetMouseState(&pointBody.x, &pointBody.y);
		
		SDL_GetMouseState(&tmpX, &tmpY);
		x = tmpX;
		y = tmpY;
	}*/
}

void Point::render() {
	SDL_SetRenderDrawColor(gRenderer, 255, 0, 0, 255);
	SDL_RenderFillRect(gRenderer,&pointBody);
}


//STICK OBJECT
Stick::Stick(Point *_p0, Point *_p1):p0(_p0),p1(_p1) {
	length = distance();
}

float Stick::distance() {
	float dx = p1->x - p0->x;
	float dy = p1->y - p0->y;
	return sqrt((dx * dx) + (dy * dy));
}

void Stick::update() {
	float dx = p1->x - p0->x;
	float dy = p1->y - p0->y;
	float _distance = sqrt((dx * dx) + (dy * dy));
	float _difference = length - _distance;
	float _percent = (_difference / _distance) / 2;
	float _offsetX = dx * _percent;
	float _offsetY = dy * _percent;

	if (!p0->pinned) {
		p0->x -= _offsetX;
		p0->y -= _offsetY;
	}

	if (!p1->pinned) {
		p1->x += _offsetX;
		p1->y += _offsetY;
	}
}

void Stick::render() {
	SDL_SetRenderDrawColor(gRenderer,255,0,0,255);
	SDL_RenderDrawLine(gRenderer,p0->x,p0->y,p1->x,p1->y);
}