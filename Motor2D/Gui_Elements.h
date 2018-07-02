#ifndef __GUI_ELEMENTS_H__
#define __GUI_ELEMENTS_H__
#include "j1Gui.h"
#include "p2Point.h"

class Gui_Elements  
{
public:
	Gui_Elements(int x, int y, SDL_Rect section, SDL_Texture* texture = nullptr) :
		Position({ x, y }),
		section(section),
		texture(texture)
	{}
	~Gui_Elements();

public:
	iPoint Position = { 0, 0 };
	SDL_Rect section = { 0, 0, 0, 0 };
	SDL_Texture* texture = nullptr;
};
#endif

