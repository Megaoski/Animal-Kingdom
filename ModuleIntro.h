#ifndef _MODULEINTRO_H
#define _MODULEINTRO_H


#include "Module.h" 
#include "ModuleAudio.h"

struct SDL_Texture;

class ModuleIntro : public Module
{
public:
	ModuleIntro();
	~ModuleIntro();

	bool Start();
	update_status Update();
	bool CleanUp();

public:

	SDL_Texture* intro = nullptr;
	Mix_Music* musiquita;

};

#endif
