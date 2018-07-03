
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
	return true;
}

bool j1SceneGui::PreUpdate()
{
	return true;
}


bool j1SceneGui::Update(float dt)
{
	{
		//score++;
		//display_score.create("%i", score);
		//App->gui->AddButton(0.3f, 1.05f, &App->gui->button_play, "1234", 1);
		//App->gui->AddButton(0.3f, 1.30f, &App->gui->button_options, "2345", 2);
		//App->gui->AddButton(0.3f, 1.55f, &App->gui->button_exit, "3456", 3);
		//App->gui->AddButton(1.05, 0.6, &App->gui->button_play, display_score.GetString(), 4);
		//App->gui->AddButton(1.05, 1, &App->gui->button_play, "Score", 5);
		//App->render->Blit(App->gui->atlas, 0, 0, &rect1);
	}

	SDL_Rect rect1 = { 0, 0, 400, 400 };

	Image* button23;
	button23 = App->gui->AddImage(0, 0, rect1, App->gui->atlas);


	return true;
}

bool j1SceneGui::PostUpdate()
{
	return true;
}

bool j1SceneGui::CleanUp()
{
	return true;
}
