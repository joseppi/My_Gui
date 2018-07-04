
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
	pugi::xml_parse_result	result = Gui_config_file.load_file("gui_config.xml");
	guiconfig = Gui_config_file.first_child();

	
	int x = guiconfig.child("StartGame").child("rect").attribute("x").as_int(0);
	int y = guiconfig.child("StartGame").child("rect").attribute("y").as_int(0);
	int h = guiconfig.child("StartGame").child("rect").attribute("h").as_int(0);
	int w = guiconfig.child("StartGame").child("rect").attribute("w").as_int(0);

	int posx = guiconfig.child("StartGame").child("position").attribute("x").as_int(0);
	int posy = guiconfig.child("StartGame").child("position").attribute("y").as_int(0);

	//Image* atlas;
	//atlas = App->gui->AddImage(ATLAS, 0, 0, { 0, 0, 600, 600 }, App->gui->atlas);
	
	Button* StartGame;
	StartGame = App->gui->AddButton(STARTGAME, posx, posy, { x,y,w,h },true,this, App->gui->atlas);

	int x1 = guiconfig.child("Options").child("rect").attribute("x").as_int(0);
	int y1 = guiconfig.child("Options").child("rect").attribute("y").as_int(0);
	int h1 = guiconfig.child("Options").child("rect").attribute("h").as_int(0);
	int w1 = guiconfig.child("Options").child("rect").attribute("w").as_int(0);

	int posx1 = guiconfig.child("Options").child("position").attribute("x").as_int(0);
	int posy1 = guiconfig.child("Options").child("position").attribute("y").as_int(0);

	Button* Options;
	Options = App->gui->AddButton(OPTIONS, posx1, posy1, { x1,y1,w1,h1 }, true, this, App->gui->atlas);
	



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


	mouse_x_display.create("%i", mouse_x);
	SDL_Texture* img = App->font->Print(mouse_x_display.GetString(), { 255,255,255,255 }, App->gui->font24);
	App->render->Blit(img, 500,500);
	SDL_DestroyTexture(img);


	mouse_y_display.create("%i", mouse_y);
	SDL_Texture* img2 = App->font->Print(mouse_y_display.GetString(), { 255,255,255,255 }, App->gui->font24);
	App->render->Blit(img, 700, 500);
	SDL_DestroyTexture(img);



	return true;
}

bool j1SceneGui::PostUpdate()
{
	return true;
}

bool j1SceneGui::CleanUp()
{
	App->gui->element_list.begin();

	for (std::list<Gui_Elements*>::iterator it_e = App->gui->element_list.begin(); it_e != App->gui->element_list.end(); it_e++)
	{
		if ((*it_e)->name = STARTGAME)
		{
			guiconfig.child("StartGame").child("rect").attribute("x").set_value((*it_e)->section.x);
			guiconfig.child("StartGame").child("rect").attribute("y").set_value((*it_e)->section.y);
			guiconfig.child("StartGame").child("rect").attribute("h").set_value((*it_e)->section.h);
			guiconfig.child("StartGame").child("rect").attribute("w").set_value((*it_e)->section.w);

			guiconfig.child("StartGame").child("position").attribute("x").set_value((*it_e)->position.x);
			guiconfig.child("StartGame").child("position").attribute("y").set_value((*it_e)->position.y);

		}
	}
	return true;
}

void j1SceneGui::ActionController()
{
	
	LOG("hola");
}
