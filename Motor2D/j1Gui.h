#ifndef __j1GUI_H__
#define __j1GUI_H__

#include "j1Module.h"
#include <list>
#include "SDL_ttf\include\SDL_ttf.h"
#include "PugiXml\src\pugixml.hpp"
#include "j1SceneGui.h"
#include "p2Point.h"


#define CURSOR_WIDTH 2

// TODO 1: Create your structure of classes
struct SDL_Texture;
struct SDL_Rect;
class Gui_Elements;
class Button;
class Image;
enum ElementName
{
	ATLAS,
	STARTGAME,
	OPTIONS
};
// ---------------------------------------------------
class j1Gui : public j1Module
{
public:

	j1Gui();

	// Destructor
	virtual ~j1Gui();

	// Called when before render is available
	bool Awake(pugi::xml_node&);

	// Call before first frame
	bool Start();

	// Called before all Updates
	bool PreUpdate(float dt);

	bool Update(float dt);

	// Called after all Updates
	bool PostUpdate();

	// Called before quitting
	bool CleanUp();

	// TODO 2: Create the factory methods
	// Gui creation functions

	const SDL_Texture* GetWindows() const;
	const SDL_Texture* GetButtons() const;

	void BlitElements();
	
	Image * AddImage(ElementName name, int x, int y, SDL_Rect rect, bool active, j1Module * callback = nullptr, SDL_Texture * texture = nullptr);
	Button* AddButton(ElementName name, int x, int y, SDL_Rect section, bool active, const char* display_string = NULL, j1Module* callback = nullptr,  SDL_Texture * texture = nullptr);
	
	const char* ElementNametoString(ElementName name);
	iPoint WriteReadXML(ElementName name, int spawn_x, int spawn_y, SDL_Rect rect);
	

private:

	SDL_Texture*				windows;
	SDL_Texture*				buttons;
	p2SString					atlas_file_name;

public:
	SDL_Texture *				atlas;
	std::list<Gui_Elements*>	element_list;
	std::list<Button*>			button_list;
	std::list<Image*>			image_list;
	std::list<SDL_Rect*>		rect_list;

	_TTF_Font*					font24;
	_TTF_Font*					font64;

	Button*						buttons_class;

	bool isAlign = false;
	bool isMoving = false;


};

#endif // __j1GUI_H__