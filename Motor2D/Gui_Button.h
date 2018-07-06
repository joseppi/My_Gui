#pragma once
#include "Gui_Elements.h"
class Button : public Gui_Elements
{
public:

	Button(ElementName name, int x, int y, SDL_Rect section, bool active, const char* display_string, j1Module* callback = nullptr , SDL_Texture* texture = nullptr) : Gui_Elements(name, x, y, section, active, callback)
	{
		string.append(display_string);
		if (texture == nullptr) { texture = this->texture; }
		callback = this->callback;
	}

	~Button();

public:
	_TTF_Font*			font24;
	std::string			string;
	SDL_Texture*		texture = App->gui->atlas;
	j1Module*			callback = App->scene_gui;
};

