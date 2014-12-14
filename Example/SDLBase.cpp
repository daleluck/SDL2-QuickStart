// SDLBase.cpp : implementation of all SDL/game methods

#include "SDLBase.h"

// class constructor
SDLBase::SDLBase(string title, int width, int height) : TITLE(title), WIDTH(width), HEIGHT(height)
{
	// store the screen dimensions for later use
	screenDimensions.x = 0;
	screenDimensions.y = 0;
	screenDimensions.w = WIDTH;
	screenDimensions.h = HEIGHT;

	// initialize all data members
	gWindow = nullptr;
	gScreenSurface = nullptr;
	gCurrentSurface = nullptr;
	gSurfaces = nullptr;
	for ( int i = 0; i < 256; i++ ) keys[i] = false;
}

// class destructor
SDLBase::~SDLBase()
{

}

// Initialize() : initialize SDL
bool SDLBase::Initialize()
{
	// initialize SDL
	if ( SDL_Init( SDL_INIT_VIDEO ) < 0 )
	{
		printf( "SDL could not initialize!\nSDL_Error:\t%s\n\n", SDL_GetError() );
		return false;
	}

	// create the window
	gWindow = SDL_CreateWindow(TITLE.c_str(), SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, WIDTH, HEIGHT, SDL_WINDOW_SHOWN );
	if ( gWindow == NULL )
	{
		printf( "Window could not be created!\nSDL_Error:\t%s\n\n", SDL_GetError() );
		return false;
	}

	// get the window surface
	gScreenSurface = SDL_GetWindowSurface(gWindow);
	
	// load in the basic content
	return LoadContent();
}

// Start() : contains the main processing loop for the application
void SDLBase::Start()
{
	bool quit = false;
	SDL_Event e;

	// while there is no 'quit' flag set...
	while (!quit)
	{
		// process any system messages
		while ( SDL_PollEvent(&e) != 0 )
		{
			// quit the application when pressing the X button
			if ( e.type == SDL_QUIT )
				quit = true;
			
			// when a key is pressed down...
			else if ( e.type == SDL_KEYDOWN )
			{
				// if the escape key is pressed, quit the application
				if ( e.key.keysym.sym == SDLK_ESCAPE )
					quit = true;
				// update the key holder when any key is pressed
				else if ( e.key.keysym.sym >= 0 && e.key.keysym.sym < 256 )
					keys[e.key.keysym.sym] = true;
			}

			// when a key is released...
			else if ( e.type == SDL_KEYUP )
			{
				// update the key holder when any key is released
				if ( e.key.keysym.sym >= 0 && e.key.keysym.sym < 256 )
					keys[e.key.keysym.sym] = false;
			}
		}

		// process all data in the application
		Process();

		// render all content to the screen
		Render();
	}
}

// Release() : releases all memory taken up by the object
void SDLBase::Release()
{
	// deallocate the surface
	for ( int i = 0; i < surfaceCount; i++ )
	{
		SDL_FreeSurface(&gSurfaces[i]);
		gSurfaces = nullptr;
	}

	// destroy the window
	SDL_DestroyWindow(gWindow);
	gWindow = NULL;

	// quit SDL subsystems
	SDL_Quit();
}

// Process() : processes things that don't require active user input, such as animation updating, collision checks, etcetera.
void SDLBase::Process()
{
	ProcessInput();
}

// ProcessInput() : processes all user input, including keyboard and mouse
void SDLBase::ProcessInput()
{
	// ...
}

// Render() : draw to the screen anything that needs to be drawn
void SDLBase::Render()
{
	// all drawing elements go here
	// ...

	// update the window
	SDL_UpdateWindowSurface(gWindow);
}

// LoadContent() : loads all the basic content to the application (assumes all loading done at initial execution)
bool SDLBase::LoadContent()
{
	// set the number of "surfaces" you'll be using
	// surfaceCount = ____;
	// gSurfaces = new SDL_Surface[surfaceCount];

	// signal it finished cleanly
	return true;
}