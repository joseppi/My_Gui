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
	
	//atlas = App->tex->Load(atlas_file_name.GetString());
	atlas = App->tex->Load("gui/ui_big_pieces.png");
	buttons = App->tex->Load("gui/Button.png");
	windows = App->tex->Load("gui/Windows2.png");
	logo = App->tex->Load("gui/logo.png");

	font12 = App->font->Load("fonts/ninja_naruto/njnaruto.ttf", 12);
	font24 = App->font->Load("fonts/ninja_naruto/njnaruto.ttf", 64);


	home_window = { 0, 0, 1020, 924 };

	button_play = { 400, 972, 183, 191 };
	button_options = { 3093, 318, 183, 191 };
	button_exit = { 2556,1407,183,191 };

	rec_logo = { 0,0,629,141 };

	

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
	rect_list.clear();
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
	SDL_Rect iterator_rect;
	for (std::list<Gui_Elements*>::iterator it_e = element_list.begin(); it_e != element_list.end(); it_e++)
	{
		iterator_rect = { (*it_e)->section.x, (*it_e)->section.y, (*it_e)->section.h, (*it_e)->section.w};
		App->render->Blit((*it_e)->texture, (*it_e)->Position.x, (*it_e)->Position.y, &iterator_rect);
	}
}

// class Gui ---------------------------------------------------
void j1Gui::AddButton(float posx, float posy, SDL_Rect* type, const char* string, int tab, float scale )
{
	int temp_x = -App->render->camera.x + App->win->screen_surface->w * posx;
	int temp_y = -App->render->camera.y + App->win->screen_surface->h * posy;

	App->render->Blit(buttons, temp_x, temp_y, type, scale);
	
	int mouse_x;
	int mouse_y;
	App->input->GetMousePosition(mouse_x, mouse_y);
	mouse_x = mouse_x * 4;
	mouse_y = mouse_y * 4;
	if (string != nullptr)
	{
		if (mouse_x >= temp_x 
			&& mouse_y >= temp_y 
			&& mouse_x < (temp_x + type->w) 
			&& mouse_y < (temp_y + type->h))//hover mouse over
		{
			SDL_Texture* img = App->font->Print(string, { 255,255,255,255 }, font24);
			App->render->Blit(img, temp_x / 2 + type->w / 2, temp_y / 2 + type->h*0.1);
			SDL_DestroyTexture(img);

			if (App->input->GetMouseButtonDown(KEY_DOWN)) //button pressed
			{
				App->scene->tabstate = 0;
			}
		}
	}
	if (App->scene->tabstate == tab)
	{
		SDL_Texture* img = App->font->Print(string, { 255,255,255,255 }, font24);
		App->render->Blit(img, temp_x / 2 + type->w / 2, temp_y / 2 + type->h*0.1);
		SDL_DestroyTexture(img);
	}
	if (App->scene->tabstate >= 6)
	{
		App->scene->tabstate = 1;
	}

}

Button * j1Gui::CreateButton(int x, int y, SDL_Rect section, SDL_Texture* texture)
{

	Button* ret = new Button(x, y, section, texture);
	element_list.push_back(ret);
	
	return ret;
}


void j1Gui::AddFloatingScore(float posx, float posy, SDL_Rect* type, const char* string, float scale)
{
	int temp_x = -App->render->camera.x + App->win->screen_surface->w * posx;
	int temp_y = -App->render->camera.y + App->win->screen_surface->h * posy;

	App->render->Blit(App->font->Print(App->scene->display_floating_score.GetString(), { 255,255,255,255 }, font24), temp_x*0.6, temp_y*0.52, {});
}