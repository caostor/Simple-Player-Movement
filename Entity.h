#pragma once
#include <SDL.h>

class Entity
{
public:
	Entity(SDL_Renderer* rrenderer);
	int Move(SDL_Point move);
	int Update();
private:
	SDL_Rect body;
	SDL_Point move = { 0, 0 };
	SDL_Renderer* renderer = NULL;
};

