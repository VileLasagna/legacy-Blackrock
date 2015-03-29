#include "SDLDisplay.h"
#include <SDL.h>
#include <assert.h>

SDLDisplay::SDLDisplay()
{
    dt = 0;
	bpp = 32;
	w = 640;
	h = 480;

    SDL_Init(SDL_INIT_EVERYTHING);	

	maxDT = 0.05f;
	//SDL_GL_SetAttribute(SDL_GL_RED_SIZE, 8);
	//SDL_GL_SetAttribute(SDL_GL_GREEN_SIZE, 8);
	//SDL_GL_SetAttribute(SDL_GL_BLUE_SIZE, 8);
	//SDL_GL_SetAttribute(SDL_GL_ALPHA_SIZE, 8);
	//SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);
	//SDL_GL_SetAttribute(SDL_GL_ACCELERATED_VISUAL, 1);

	fullscreen = 0;


	videoFlags = SDL_HWSURFACE | SDL_DOUBLEBUF | SDL_ASYNCBLIT /* | SDL_OPENGLBLIT  *//*| SDL_OPENGL*/;

    setVideo();
	assert(screen);



	//videoFlags = SDL_HWSURFACE | SDL_DOUBLEBUF | SDL_ASYNCBLIT/*| SDL_OPENGLBLIT*/ /*| SDL_OPENGL*/ | fullscreen;
	////SDL_GL_SetAttribute(SDL_GL_DEPTH_SIZE, 24);

	//setVideo();
}


SDLDisplay::~SDLDisplay()
{
    SDL_Quit();
}

void SDLDisplay::FullScreen(bool b)
{
	if (b)
	{
		fullscreen = SDL_FULLSCREEN;
	}
	else
	{
		fullscreen = 0;
	}
	setVideo();
}

void SDLDisplay::ToggleFS()
{
	if (fullscreen)
	{
		fullscreen = 0;
	}
	else
	{
		fullscreen = SDL_FULLSCREEN;
	}
	setVideo();
}


SDL_Surface* SDLDisplay::getScreen() const
{
    return screen;
}

void SDLDisplay::Flip()
{
    SDL_Flip(screen);
	//SDL_GL_SwapBuffers();
}

void SDLDisplay::Update()
{
    static unsigned int oldms = SDL_GetTicks();
    unsigned int ms = SDL_GetTicks();
    dt = ((float)(ms - oldms)) / 1000.0f;
    oldms = ms;
	if (dt > maxDT)
	{
		dt = maxDT;
	}

}

float SDLDisplay::getDtSecs() const
{
    return dt;
}


SDLDisplay* SDLDisplay::instance()
{
	static SDLDisplay* inst = 0;
	if (!inst)
	{
		inst = new SDLDisplay;
	}
	return inst;
}

void SDLDisplay::clear()
{
	delete(SDLDisplay::instance());
	//yeah, I know this might end up initialising this unnecessarily
	//but I couldn't really find an alternative
}

void SDLDisplay::setSize(int width, int height)
{
	w = width;
	h = height;
	setVideo();
}

void SDLDisplay::setVideo()
{
	screen = SDL_SetVideoMode(w, h, bpp, videoFlags | fullscreen);
}

void SDLDisplay::setBPP(int i)
{
	bpp = i;
	setVideo();
}