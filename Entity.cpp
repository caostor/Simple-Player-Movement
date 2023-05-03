#include "Entity.h"

Entity::Entity(SDL_Renderer* rrenderer)
{
	body.w = 50;
	body.h = 50;
	renderer = rrenderer;
}

int Entity::Move(SDL_Point movew)
{
	move.x += movew.x;
	move.y += movew.y;

	return 0;
}

int Entity::Update()
{
	body.x += move.x;
	body.y += move.y;

	SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
	SDL_RenderFillRect(renderer, &body);

	move.x = 0;
	move.y = 0;

	return 0;
}
