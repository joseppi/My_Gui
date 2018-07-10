#ifndef __j1SCENEGUI_H__
#define __j1SCENEGUI_H__

#include "j1Module.h"
#include "j1Timer.h"

struct SDL_Texture;
class GuiImage;
class GuiText;
class GuiElements;
struct _TTF_Font;

class j1SceneGui : public j1Module
{
public:

	j1SceneGui();

	// Destructor
	virtual ~j1SceneGui();

	// Called before render is available
	bool Awake();

	// Called before the first frame
	bool Start();

	// Called before all Updates
	bool PreUpdate();

	// Called each loop iteration
	bool Update(float dt);

	// Called before all Updates
	bool PostUpdate();

	// Called before quitting
	bool CleanUp();

	bool ActionController(ElementName name);

private:
	SDL_Texture*			debug_tex;
	GuiImage*				banner;
	GuiText*				text;
	j1Timer					blittimer;

private:
	_TTF_Font*				Font;

public:
	pugi::xml_node			gui_config_node;
	pugi::xml_document		gui_config_file;
	pugi::xml_parse_result	result;






};

#endif // __j1SCENE_H__
