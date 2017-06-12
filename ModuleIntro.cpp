#include "Globals.h"
#include "Application.h"
#include "ModuleTextures.h"
#include "ModuleRender.h"
#include "ModuleInput.h"
#include "ModuleIntro.h"





ModuleIntro::ModuleIntro()
{}

ModuleIntro::~ModuleIntro()
{}

// Load assets
bool ModuleIntro::Start()
{
	LOG("Loading intro scene");


	intro = App->textures->Load("rtype/intro.png");
	musiquita = App->audio->LoadMusic("rtype/intro.ogg");

	App->intro->Enable();
	App->audio->PlayMusic(musiquita);


	return true;
}

// UnLoad assets
bool ModuleIntro::CleanUp()
{
	LOG("Unloading intro scene");

	App->textures->Unload(intro);

	App->audio->StopMusic();
	App->intro->Disable();

	return true;
}

// Update: draw background
update_status ModuleIntro::Update()
{


	// Draw everything --------------------------------------
	App->render->Blit(intro, 0, 0, NULL);

	if (App->input->keyboard[SDL_SCANCODE_SPACE] == KEY_DOWN)
	{
		App->fade->FadeToBlack(App->intro, App->scene_space, 2.0f);
	}


	return UPDATE_CONTINUE;
}