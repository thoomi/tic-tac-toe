#ifndef CSURFACE_H
#define CSURFACE_H

#include <SDL/SDL.h>
#include <iostream>
using namespace std;

class CSurface {
    private:
        CSurface();

    public:
        static SDL_Surface *onLoadImage(string filename);
        static bool onBlitImage(SDL_Surface *surf_Dest, SDL_Surface *surf_Src, int x, int y);
        static bool onBlitImage(SDL_Surface *surf_Dest, SDL_Surface *surf_Src, int x, int y, int X2, int Y2, int W, int H);
        static bool SetColorKey(SDL_Surface *surf_Dest, int R, int G, int B);
};

#endif
