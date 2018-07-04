#ifndef __j1SCENEGUI_H__
#define __j1SCENEGUI_H__

#include "j1Module.h"

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

	void ActionController();

private:
	SDL_Texture*			debug_tex;
	GuiImage*				banner;
	GuiText*				text;

	pugi::xml_node			guiconfig;
	pugi::xml_document		Gui_config_file;

private:
	_TTF_Font*				Font;







};

#endif // __j1SCENE_H__
