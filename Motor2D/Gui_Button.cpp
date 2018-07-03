#include "Gui_Button.h"
#include "j1Render.h"
#include "j1Input.h"
#include "j1Window.h"
#include "j1App.h"
#include "j1Fonts.h"
#include "j1Scene.h"


Button::~Button()
{
}
/*
void Button::AddGuiButtons2(float posx, float posy, SDL_Rect* type, const char* string, int tab, float scale)
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
*/
