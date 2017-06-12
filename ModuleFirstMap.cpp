#include "Globals.h"
#include "Application.h"
#include "ModuleTextures.h"
#include "ModuleRender.h"
#include "ModuleIntro.h"
#include "ModuleFadeToBlack.h"
#include "ModuleInput.h"
#include "ModuleFirstMap.h"



ModuleFirstMap::ModuleFirstMap()
{}

ModuleFirstMap::~ModuleFirstMap()
{}


bool ModuleFirstMap::Start()
{
	LOG("Loading space scene");

	background = App->textures->Load("rtype/background.png");
	musiquita = App->audio->LoadMusic("rtype/starting.wav");
	lasersito = App->audio->LoadSFX("rtype/laser.wav");

	App->firstmap->Enable();
	/*App->player->Enable();*/


	App->audio->PlayMusic(musiquita);


	return true;
}


bool ModuleFirstMap::CleanUp()
{
	LOG("Unloading space scene");

	App->textures->Unload(background);
	/*App->player->Disable();*/
	App->audio->StopMusic();

	return true;
}

// Update: draw background
update_status ModuleFirstMap::Update()
{
	// Move camera forward -----------------------------
	int scroll_speed = 0;

	/*App->player->position.x += 1;*/
	App->render->camera.x -= 3;

	SDL_Rect map = { 0,0, STAGE_WIDTH, STAGE_HEIGHT };

	// Draw everything --------------------------------------
	App->render->Blit(1, background, SCREEN_WIDTH / 2 - STAGE_WIDTH / 2, -STAGE_HEIGHT + SCREEN_HEIGHT, { 0,1 }, &map);

	if (App->input->keyboard[SDL_SCANCODE_SPACE] == KEY_DOWN)
	{
		App->audio->PlaySFX(lasersito);
	}


	return UPDATE_CONTINUE;
}