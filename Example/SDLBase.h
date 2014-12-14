// SDLBase.h : handles all initialize and running of SDL based applications

#ifndef SDLBase___
#define SDLBase___

// standard libraries
#include <iostream>
#include <stdio.h>
#include <string>
using namespace std;

// SDL library
#include <SDL2/SDL.h>

class SDLBase
{
private:
	string TITLE;
	int WIDTH, HEIGHT;

	SDL_Window *gWindow;
	SDL_Surface *gScreenSurface, *gCurrentSurface, *gSurfaces;
	SDL_Rect screenDimensions;
	int surfaceCount;

	bool LoadContent();
	SDL_Surface *loadSurface(string path)
	{
		SDL_Surface *loadedSurface = SDL_LoadBMP(path.c_str());
		if ( loadedSurface == NULL ) printf("Unable to load file: \t%s\nSDL Error:\t%s\n\n", path.c_str(), SDL_GetError());
		else
		{
			SDL_Surface *optimizedSurface = SDL_ConvertSurface(loadedSurface, gScreenSurface->format, NULL);
			if ( optimizedSurface == NULL ) printf("Unable to optimize file: \t%s\nSDL Error:\t%s\n\n", path.c_str(), SDL_GetError());
			SDL_FreeSurface(loadedSurface);
			loadedSurface = optimizedSurface;
		}

		return loadedSurface;
	}
public:
	bool keys[256];

	SDLBase(string name = "SDL Application", int width = 800, int height = 600);
	~SDLBase();

	bool Initialize();
	void Start();
	void Release();

	void Render();
	void Process();
	void ProcessInput();
};

#endif