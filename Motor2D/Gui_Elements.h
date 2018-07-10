#ifndef __GUI_ELEMENTS_H__
#define __GUI_ELEMENTS_H__
#include "j1Gui.h"
#include "p2Point.h"
#include "j1App.h"
#include "j1Textures.h"
#include "j1SceneGui.h"

class SDL_Texture;
class Gui_Elements  
{
public:
	Gui_Elements(ElementName name, int x, int y, const SDL_Rect section, bool active, j1Module* callback) :
		name(name),
		position({ x, y }),
		section(section),
		callback(callback),
		active(active)
	{}
	~Gui_Elements() {};


public:
	iPoint position = { 0, 0 };
	SDL_Rect section = { 0, 0, 100, 100 };
	ElementName name;
	j1Module* callback;
	bool active;
	bool isMoving = false;



};

#endif

