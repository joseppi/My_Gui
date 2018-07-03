#pragma once
#include "Gui_Elements.h"
class Button : public Gui_Elements
{
public:

	Button(int x, int y, SDL_Rect section, SDL_Texture* texture) : Gui_Elements(x, y, section, texture)
	{}

	~Button();

public:
	SDL_Texture*		buttons;
	_TTF_Font*			font24;

};

