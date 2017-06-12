#include "Application.h"
#include "ModuleWindow.h"
#include "ModuleRender.h"
#include "ModuleInput.h"
#include "ModuleTextures.h"
#include "ModuleAudio.h"
#include "ModuleFirstMap.h"
#include "ModuleIntro.h"
#include "ModuleFadeToBlack.h"
#include "ModuleCollision.h"



Application::Application()
{
	uint i = 0;
	modules[i++] = window = new ModuleWindow();
	modules[i++] = render = new ModuleRender();
	modules[i++] = input = new ModuleInput();
	modules[i++] = textures = new ModuleTextures();
	modules[i++] = audio = new ModuleAudio();
	modules[i++] = firstmap = new ModuleFirstMap();
	modules[i++] = intro = new ModuleIntro();
	modules[i++] = fade = new ModuleFadeToBlack();
	modules[i++] = collision = new ModuleCollision();
	
	
}

Application::~Application()
{
	for (int i = 0; i < NUM_MODULES; ++i)
		delete modules[i];
	
}

bool Application::Init()
{
	bool ret = true;

	//Disabling stopped modules
	firstmap->Disable();
	/*player->Disable();
	bonus->Disable();*/
	//-

	for (int i = 0; i < NUM_MODULES && ret == true; ++i)
		ret = modules[i]->Init();

	for (int i = 0; i < NUM_MODULES && ret == true; ++i)
		ret = modules[i]->IsEnabled() ? modules[i]->Start() : true;

	return ret;
}

update_status Application::Update()
{
	update_status ret = UPDATE_CONTINUE;

	for (int i = 0; i < NUM_MODULES && ret == UPDATE_CONTINUE; ++i)
		ret = modules[i]->IsEnabled() ? ret = modules[i]->PreUpdate() : UPDATE_CONTINUE;

	for (int i = 0; i < NUM_MODULES && ret == UPDATE_CONTINUE; ++i)
		ret = modules[i]->IsEnabled() ? ret = modules[i]->Update() : UPDATE_CONTINUE;

	for (int i = 0; i < NUM_MODULES && ret == UPDATE_CONTINUE; ++i)
		ret = modules[i]->IsEnabled() ? ret = modules[i]->PostUpdate() : UPDATE_CONTINUE;


	return ret;
}

bool Application::CleanUp()
{
	bool ret = true;

	for (int i = NUM_MODULES - 1; i >= 0 && ret == true; --i)
		ret = modules[i]->CleanUp();

	return ret;
}