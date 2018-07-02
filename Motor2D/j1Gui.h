#ifndef __j1GUI_H__
#define __j1GUI_H__

#include "j1Module.h"
#include <list>
#include "SDL_ttf\include\SDL_ttf.h"


#define CURSOR_WIDTH 2

// TODO 1: Create your structure of classes
struct SDL_Texture;
struct SDL_Rect;
class Button;
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
	bool PreUpdate();

	// Called after all Updates
	bool PostUpdate();

	// Called before quitting
	bool CleanUp();

	// TODO 2: Create the factory methods
	// Gui creation functions

	const SDL_Texture* GetWindows() const;
	const SDL_Texture* GetButtons() const;

	void AddButton(float posx, float posy, SDL_Rect* name = {}, const char* string = nullptr, int tab = -1, float scale = 0.5f );
	Button* CreateButton(int x, int y, SDL_Rect section, SDL_Texture* texture = nullptr);
	void AddFloatingScore(float posx, float posy, SDL_Rect* type, const char* string, float scale = 0.5f);

private:
	SDL_Texture*		atlas;
	SDL_Texture*		windows;
	SDL_Texture*		buttons;
	p2SString			atlas_file_name;

public:
	std::list<SDL_Rect*>rect_list;
	SDL_Rect			home_window;
	SDL_Rect			button_play;
	SDL_Rect			button_options;
	SDL_Rect			button_exit;
	SDL_Rect			rec_logo;

	SDL_Texture*		logo;

	_TTF_Font*			font12;
	_TTF_Font*			font24;

	int					score;
	p2SString			display_score;


	p2SString			display_floating_score;

	Button*			buttons_class;
	

};

#endif // __j1GUI_H__