#ifndef SDL_DISPLAY_H
#define SDL_DISPLAY_H

struct SDL_Surface;

class SDLDisplay
{
private:	//this class is a singleton
	    SDLDisplay();
		SDLDisplay(const SDLDisplay& ref) {}
		SDLDisplay operator= (const SDLDisplay& ref) {}
public:

	static SDLDisplay* instance();
	static void clear();

    ~SDLDisplay();

    void Flip();
	void setMaxDT(float mdt) {maxDT = mdt;}
	void setSize (int width, int height);

    SDL_Surface* getScreen() const;

    void Update();

    float getDtSecs() const;
	float getMaxDT() const {return maxDT;}

	void FullScreen(bool b = true);
	void ToggleFS();

	void setBPP(int i);

private:
	void setVideo();
    SDL_Surface* screen;
    float dt;
	float maxDT;
	unsigned __int32 videoFlags;
	int bpp;
	int w;
	int h;
	unsigned __int32 fullscreen;

};

#endif
