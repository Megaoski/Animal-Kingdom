#include "Globals.h"
#include "Application.h"
#include "ModuleTextures.h"
#include "ModuleRender.h"
#include "ModuleInput.h"
#include "ModuleIntro.h"
#include "ModuleFadeToBlack.h"
#include "ModuleFirstMap.h"




ModuleIntro::ModuleIntro()
{}

ModuleIntro::~ModuleIntro()
{}

// Load assets
bool ModuleIntro::Start()
{
	LOG("Loading intro scene");


	intro_screen = App->textures->Load("animal-kingdom/game/intro.png");
	musiquita = App->audio->LoadMusic("rtype/intro.ogg");


	intro.SetUp(0, 0, SCREEN_WIDTH, SCREEN_HEIGHT, 6, 11, "0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,2,3,4,5,6,7,8,9,10");
	intro.speed = 0.15f;

	App->intro->Enable();
	App->audio->PlayMusic(musiquita);


	return true;
}

// UnLoad assets
bool ModuleIntro::CleanUp()
{
	LOG("Unloading intro scene");

	App->textures->Unload(intro_screen);

	App->audio->StopMusic();
	App->intro->Disable();

	return true;
}

// Update: draw background
update_status ModuleIntro::Update()
{


	// Draw everything --------------------------------------
	App->render->Blit(intro_screen, 0, 0, NULL);

	if (App->input->keyboard[SDL_SCANCODE_SPACE] == KEY_REPEAT)
	{
		App->fade->FadeToBlack(App->intro, App->firstmap, 2.0f);
	}


	return UPDATE_CONTINUE;
}