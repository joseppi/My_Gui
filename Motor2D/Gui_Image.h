#pragma once
#include "Gui_Elements.h"
class Image : public Gui_Elements
{
public:

	Image(ElementName name, int x, int y, SDL_Rect section, SDL_Texture* texture) : Gui_Elements(name, x, y, section, texture)
	{}
	~Image()
	{}
};

