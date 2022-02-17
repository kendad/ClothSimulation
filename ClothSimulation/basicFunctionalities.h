#pragma once
#include <SDL.h>
#include <iostream>
#include "globalVariables.h"

bool init();//intializes SDL 

void close();//Closes everything when application closes

void handelUserInput(SDL_Event* e);//handel User Inputs
