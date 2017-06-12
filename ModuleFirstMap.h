#ifndef __MODULEFIRSTMAP_H__
#define __MODULEFIRSTMAP_H__

#include "Module.h"
#include "ModuleAudio.h"

struct SDL_Texture;

class ModuleFirstMap : public Module
{
public:
	ModuleFirstMap();
	~ModuleFirstMap();

	bool Start();
	update_status Update();
	bool CleanUp();

public:

	SDL_Texture* background = nullptr;
	SDL_Texture* stars = nullptr;
	Mix_Music* musiquita;
	Mix_Chunk* lasersito;
};

#endif 
