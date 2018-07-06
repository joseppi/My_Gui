#include "p2Defs.h"
#include "p2Log.h"
#include "j1App.h"
#include "j1Render.h"
#include "j1Textures.h"
#include "j1Fonts.h"
#include "j1Input.h"
#include "j1Gui.h"
#include "j1Window.h"
#include "j1Scene.h"
#include "p2Animation.h"
#include "Gui_Button.h"
#include "Gui_Image.h"
#include "j1SceneGui.h"


j1Gui::j1Gui() : j1Module()
{
	name.create("gui");
}

// Destructor
j1Gui::~j1Gui()
{}

// Called before render is available
bool j1Gui::Awake(pugi::xml_node& conf)
{
	LOG("Loading GUI atlas");
	bool ret = true;

	atlas_file_name = conf.child("atlas").attribute("file").as_string("");

	return ret;
}

// Called before the first frame
bool j1Gui::Start()
{
	atlas = App->tex->Load(atlas_file_name.GetString());

	font12 = App->font->Load("fonts/ninja_naruto/njnaruto.ttf", 12);
	font24 = App->font->Load("fonts/ninja_naruto/njnaruto.ttf", 64);
	

	return true;
}

// Update all guis
bool j1Gui::PreUpdate(float dt)
{

	return true;
}

bool j1Gui::Update(float dt)
{
	BlitElements();
	return true;
}
// Called after all Updates
bool j1Gui::PostUpdate()
{
	return true;
}

// Called before quitting
bool j1Gui::CleanUp()
{
	LOG("Freeing GUI");
	App->font->CleanUp();

	return true;
}

// const getter for atlas
const SDL_Texture* j1Gui::GetWindows() const
{
	return windows;
}

const SDL_Texture* j1Gui::GetButtons() const
{
	return buttons;
}

void j1Gui::BlitElements()
{
	int mouse_x = 0;
	int mouse_y = 0;
	App->input->GetMousePosition(mouse_x, mouse_y);
	for (std::list<Gui_Elements*>::iterator it_e = element_list.begin(); it_e != element_list.end(); it_e++)
	{
		if ((*it_e)->active == true)
		{
			if (mouse_x >= (*it_e)->position.x && 
				mouse_y >= (*it_e)->position.y && 
				mouse_x <= ((*it_e)->position.x + (*it_e)->section.w) &&
				mouse_y <= ((*it_e)->position.y + (*it_e)->section.h) &&
				App->input->GetMouseButtonDown(KEY_DOWN))
			{
				(*it_e)->active = false;

			}
			SDL_Rect iterator_rect = (*it_e)->section;
			App->render->Blit((*it_e)->texture, (*it_e)->position.x, (*it_e)->position.y, &iterator_rect);
			(*it_e)->callback->ActionController();
			


		}


		
	}
	
}

// class Gui ---------------------------------------------------

Image * j1Gui::AddImage(pugi::xml_node& node, ElementName name, int x, int y, SDL_Rect rect,bool active, j1Module* callback, SDL_Texture* texture)
{
	node.append_child("ATLAS").append_child("rect").append_attribute("x") = rect.x;
	node.append_child("ATLAS").append_child("rect").append_attribute("y") = rect.y;
	node.append_child("ATLAS").append_child("rect").append_attribute("h") = rect.h;
	node.append_child("ATLAS").append_child("rect").append_attribute("w") = rect.w;

	//ElenemtNametoString(name)
	SDL_Texture* img3 = App->font->Print("hola", { 255,255,255,255 }, App->gui->font24);
	App->render->Blit(img3, 100, 100);

	Image* ret = new Image(name, x, y, rect, active, callback, texture);
	element_list.push_back(ret);

	return ret;
}

Button * j1Gui::AddButton(ElementName name, int x, int y, SDL_Rect rect,bool active, j1Module* callback, SDL_Texture* texture)
{
	Button* ret = new Button(name, x, y, rect, active, callback, texture);
	element_list.push_back(ret);

	return ret;
}

const char* j1Gui::ElenemtNametoString(ElementName name)
{
	switch (name)
	{
		case ATLAS:		return "ATLAS";
		case STARTGAME: return "STARTGAME";
		case OPTIONS:	return "OPTIONS";
	}
}
