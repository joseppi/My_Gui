#pragma once
#include "Gui_Elements.h"
class Image : public Gui_Elements
{
public:

	Image(ElementName name, int x, int y, SDL_Rect section, bool active, j1Module* callback, SDL_Texture* texture = nullptr) : Gui_Elements(name, x, y, section, active, callback)
	{
		if (texture == nullptr) { texture = this->texture; }
	}
	~Image()
	{}
public:
	SDL_Texture * texture = App->gui->atlas;
};

