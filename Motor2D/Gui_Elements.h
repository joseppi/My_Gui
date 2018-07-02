#ifndef __GUI_ELEMENTS_H__
#define __GUI_ELEMENTS_H__
#include "j1Gui.h"
#include "p2Point.h"
#include "j1App.h"
#include "j1Textures.h"
#include "j1Gui_Scene.h"

class SDL_Texture;

class Gui_Elements  
{
public:
	Gui_Elements(int x, int y, const SDL_Rect section, SDL_Texture* texture) :
		Position({ x, y }),
		section(section),
		texture(texture)
	{}
	~Gui_Elements() {};


public:
	iPoint Position = { 0, 0 };
	SDL_Rect section = { 0, 0, 100, 100 };
	SDL_Texture* texture = App->gui->atlas;

};
#endif

