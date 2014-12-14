// SDL library
#include "SDLBase.h"

// program entry point
int main(int argc, char* argv[])
{
	// create the application
	SDLBase application;

	// attempt to initialize the application
	if ( !application.Initialize() )
		return -1;

	// start the application (i.e. enter the main loop)
	application.Start();

	// release all content used up by the application
	application.Release();

	// exit program cleanly
	return 0;
}