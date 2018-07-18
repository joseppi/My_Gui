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

	font24 = App->font->Load("fonts/ninja_naruto/njnaruto.ttf", 24);
	font64 = App->font->Load("fonts/ninja_naruto/njnaruto.ttf", 64);
	

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
	App->scene_gui->gui_config_file.save_file("gui_config.xml");

	
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
	int mouse_x, mouse_y = 0;

	App->input->GetMousePosition(mouse_x, mouse_y);

	for (std::list<Gui_Elements*>::iterator it = element_list.begin(); it != element_list.end(); it++)
	{
		if (mouse_x >= (*it)->position.x &&
			mouse_y >= (*it)->position.y &&
			mouse_x <= ((*it)->position.x + (*it)->section.w) &&
			mouse_y <= ((*it)->position.y + (*it)->section.h))
		{
			(*it)->isMoving = true;
		}

		if ((*it)->isMoving == true && App->input->GetMouseButtonDown(1) == KEY_REPEAT)
		{
			if (App->input->GetKey(SDL_SCANCODE_LCTRL) == KEY_REPEAT)
			{
				for (std::list<Gui_Elements*>::iterator it2 = element_list.begin(); it2 != element_list.end(); it2++)
				{


					if ((*it)->position.x == (*it2)->position.x && (*it) != (*it2) && App->input->GetKey(SDL_SCANCODE_LCTRL) == KEY_REPEAT)
					{
						isAlign = true;
						(*it)->position.x = (*it2)->position.x;
						(*it)->position.y = mouse_y - (*it)->section.h / 2;
					}
					else if (isAlign == false)
					{
						(*it)->position.x = mouse_x - (*it)->section.w / 2;
						(*it)->position.y = mouse_y - (*it)->section.h / 2;
					}
					else if (mouse_x >= (*it2)->position.x + 30 && mouse_x <= (*it2)->position.x - 30)
					{
						isAlign = false;
					}
				}
			}
			else
			{
				isAlign = false;
				(*it)->position.x = mouse_x - (*it)->section.w / 2;
				(*it)->position.y = mouse_y - (*it)->section.h / 2;
			}
		}
		else
		{
			(*it)->isMoving = false;

			App->scene_gui->gui_config_node.child(ElementNametoString((*it)->name)).child("position").attribute("x").set_value((*it)->position.x);
			App->scene_gui->gui_config_node.child(ElementNametoString((*it)->name)).child("position").attribute("y").set_value((*it)->position.y);
		}
	}


	for (std::list<Button*>::iterator it = button_list.begin(); it != button_list.end(); it++)
	{
		if ((*it)->active == true)
		{
			if (mouse_x >= (*it)->position.x && 
				mouse_y >= (*it)->position.y && 
				mouse_x <= ((*it)->position.x + (*it)->section.w) &&
				mouse_y <= ((*it)->position.y + (*it)->section.h))
			{
				if (App->input->GetMouseButtonDown(1) == KEY_DOWN)
				{
					(*it)->callback->ActionController((*it)->name);
				}


			}
			//Blit Texture
			SDL_Rect iterator_rect = (*it)->section;
			App->render->Blit((*it)->texture, (*it)->position.x, (*it)->position.y, &iterator_rect);

			//Blit Text
			SDL_Texture* text = App->font->Print((*it)->string.c_str(), { 255,255,255,255 }, App->gui->font24);
			int text_w;
			SDL_QueryTexture(text, NULL, NULL, &text_w, NULL);
			App->render->Blit(text, (*it)->position.x + (*it)->section.w/2 - text_w/2, (*it)->position.y + (*it)->section.h/4);
		}
	}

	for (std::list<Image*>::iterator it_e = image_list.begin(); it_e != image_list.end(); it_e++)
	{
		if ((*it_e)->active == true)
		{
			SDL_Rect iterator_rect = (*it_e)->section;
			App->render->Blit((*it_e)->texture, (*it_e)->position.x, (*it_e)->position.y, &iterator_rect);
		}
	}
	
}


// class Gui ---------------------------------------------------

Image * j1Gui::AddImage(ElementName name, int spawn_x, int spawn_y, SDL_Rect rect,bool active, j1Module* callback, SDL_Texture* texture)
{
	iPoint position = { 0,0 };
	position = WriteReadXML(name, spawn_x, spawn_y, rect);

	Image* ret = new Image(name, position.x, position.y, rect, active, callback, texture);
	image_list.push_back(ret);
	element_list.push_back(ret);


	

	return ret;
}

Button * j1Gui::AddButton(ElementName name, int spawn_x, int spawn_y, SDL_Rect rect,bool active, const char* display_string, j1Module* callback,  SDL_Texture* texture)
{

	iPoint position = { 0,0 };
	position = WriteReadXML(name, spawn_x, spawn_y, rect);
	if (&position == NULL)
	{
		Button* ret = new Button(name, spawn_x, spawn_y, rect, active, display_string, callback, texture);
		button_list.push_back(ret);
		element_list.push_back(ret);
		return ret;
	}
	else
	{
		Button* ret = new Button(name, position.x, position.y, rect, active, display_string, callback, texture);
		button_list.push_back(ret);
		element_list.push_back(ret);
		return ret;
	}
	
	


}

const char* j1Gui::ElementNametoString(ElementName name)
{
	switch (name)
	{
		case ATLAS:		return "ATLAS";
		case STARTGAME: return "STARTGAME";
		case OPTIONS:	return "OPTIONS";
	}
}

iPoint j1Gui::WriteReadXML(ElementName name, int spawn_x, int spawn_y, SDL_Rect rect)
{
	iPoint ret;
	if (App->scene_gui->gui_config_node.child(ElementNametoString(name))) //if the node exists
	{
		rect.x = App->scene_gui->gui_config_node.child(ElementNametoString(name)).child("rect").attribute("x").as_int(rect.x);
		rect.y = App->scene_gui->gui_config_node.child(ElementNametoString(name)).child("rect").attribute("y").as_int(rect.y);
		rect.h = App->scene_gui->gui_config_node.child(ElementNametoString(name)).child("rect").attribute("h").as_int(rect.h);
		rect.w = App->scene_gui->gui_config_node.child(ElementNametoString(name)).child("rect").attribute("w").as_int(rect.w);
	}
	else //if not
	{
		App->scene_gui->gui_config_node.append_child(ElementNametoString(name)).append_child("position");
		App->scene_gui->gui_config_node.child(ElementNametoString(name)).child("position").append_attribute("x") = spawn_x;
		App->scene_gui->gui_config_node.child(ElementNametoString(name)).child("position").append_attribute("y") = spawn_y;

		App->scene_gui->gui_config_file.save_file("gui_config.xml");
	}
	ret.x = App->scene_gui->gui_config_node.child(ElementNametoString(name)).child("position").attribute("x").as_int(spawn_x);
	ret.y = App->scene_gui->gui_config_node.child(ElementNametoString(name)).child("position").attribute("y").as_int(spawn_y);

	return ret;
}
