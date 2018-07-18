
#include "p2Defs.h"
#include "p2Log.h"
#include "j1App.h"
#include "j1Input.h"
#include "j1Textures.h"
#include "j1Audio.h"
#include "j1Render.h"
#include "j1Window.h"
#include "j1Map.h"
#include "j1PathFinding.h"
#include "j1Gui.h"
#include "j1SceneGui.h"
#include "j1Fonts.h"
#include "j1Window.h"
#include "Gui_Elements.h"




j1SceneGui::j1SceneGui()
{
	name.create("scenegui");
}


j1SceneGui::~j1SceneGui()
{
}

bool j1SceneGui::Awake()
{
	return true;
}

bool j1SceneGui::Start()
{
	result = gui_config_file.load_file("gui_config.xml");
	gui_config_node = gui_config_file.first_child();
		
	Button* StartGame;
	StartGame = App->gui->AddButton(STARTGAME, 200, 500, { 0,0,192,56 },true,"Start Game");

	Button* Options;
	Options = App->gui->AddButton(OPTIONS, 200, 700, { 0,0,192,56 }, true, "Options");

	//Image* Atlas;
	//Atlas = App->gui->AddImage(ATLAS, 0, 0, { 0,0,1000,1000 }, true, this);
	
	App->scene_gui->gui_config_file.save_file("gui_config.xml");
	return true;
}

bool j1SceneGui::PreUpdate()
{
	return true;
}

bool j1SceneGui::Update(float dt)
{
	p2SString mouse_x_display;
	p2SString mouse_y_display;

	int mouse_x;
	int mouse_y;

	App->input->GetMousePosition(mouse_x, mouse_y);


	if (blittimer.Read() > 1)
	{
		mouse_x_display.create("%i", mouse_x);
		SDL_Texture* img = nullptr;

		img = App->font->Print(mouse_x_display.GetString(), { 255,255,255,255 }, App->gui->font64);
		App->render->Blit(img, 500, 500);
		SDL_DestroyTexture(img);


		mouse_y_display.create("%i", mouse_y);
		SDL_Texture* img2 = nullptr;

		img2 = App->font->Print(mouse_y_display.GetString(), { 255,255,255,255 }, App->gui->font64);
		App->render->Blit(img2, 700, 500, 0);
		blittimer.Start();
		SDL_DestroyTexture(img2);
	}





	return true;
}

bool j1SceneGui::PostUpdate()
{
	return true;
}

bool j1SceneGui::CleanUp()
{
	/*
	App->gui->element_list.begin();

	for (std::list<Gui_Elements*>::iterator it_e = App->gui->element_list.begin(); it_e != App->gui->element_list.end(); it_e++)
	{
	if ((*it_e)->name = STARTGAME)
	{
	gui_config_node.child("StartGame").child("rect").attribute("x").set_value((*it_e)->section.x);
	gui_config_node.child("StartGame").child("rect").attribute("y").set_value((*it_e)->section.y);
	gui_config_node.child("StartGame").child("rect").attribute("h").set_value((*it_e)->section.h);
	gui_config_node.child("StartGame").child("rect").attribute("w").set_value((*it_e)->section.w);

	gui_config_node.child("StartGame").child("position").attribute("x").set_value((*it_e)->position.x);
	gui_config_node.child("StartGame").child("position").attribute("y").set_value((*it_e)->position.y);

	}
	}
	*/

	return true;
}

bool j1SceneGui::ActionController(ElementName name)
{
	switch (name)
	{
		case OPTIONS:
		{

		}
		case STARTGAME:
		{

		}

	}
		
	return true;
}
