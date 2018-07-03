#ifndef __j1GUI_H__
#define __j1GUI_H__

#include "j1Module.h"
#include <list>
#include "SDL_ttf\include\SDL_ttf.h"
#include "PugiXml\src\pugixml.hpp"


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
	Image* AddImage(ElementName name, int x, int y, SDL_Rect section, SDL_Texture* texture = nullptr);

	Button * AddButton(ElementName name, int x, int y, SDL_Rect section, SDL_Texture * texture);
	

private:

	SDL_Texture*				windows;
	SDL_Texture*				buttons;
	p2SString					atlas_file_name;

public:
	SDL_Texture *				atlas;
	std::list<Gui_Elements*>	element_list;
	std::list<SDL_Rect*>		rect_list;
	SDL_Rect					home_window;
	SDL_Rect					button_play;
	SDL_Rect					button_options;
	SDL_Rect					button_exit;
	SDL_Rect					rec_logo;

	SDL_Texture*				logo;

	_TTF_Font*					font12;
	_TTF_Font*					font24;

	int							score;
	p2SString					display_score;


	p2SString					display_floating_score;

	Button*						buttons_class;
	

};

#endif // __j1GUI_H__