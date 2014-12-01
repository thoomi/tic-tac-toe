#include "CSurface.h"

// Konstruktor
// Aufgabe: noch nichts
CSurface::CSurface() {}


// onLoadImage
// Aufgabe: .bmp Bild laden und auf Display Format anpassen
SDL_Surface *CSurface::onLoadImage(string filename) {
    SDL_Surface *surf_Temp = 0;
    SDL_Surface *surf_Return = 0;

    if((surf_Temp = SDL_LoadBMP(filename.c_str())) == 0) {
        return 0;
    }

    surf_Return = SDL_DisplayFormat(surf_Temp);
    SDL_FreeSurface(surf_Temp);

    return surf_Return;
}


// onBlitImage
// Aufgabe: Geladenes Bild auf Ziel Surface blitten
bool CSurface::onBlitImage(SDL_Surface *surf_Dest, SDL_Surface *surf_Src, int x, int y) {
    if(surf_Dest == 0 || surf_Src == 0) {
        return false;
    }

    SDL_Rect DestR;

    DestR.x = x;
    DestR.y = y;

    SDL_BlitSurface(surf_Src, 0, surf_Dest, &DestR);

    return true;
}


// onBlitImage  /* mit Angabe des Bildauschnitts
// Aufgabe: Bildausschnit auf Ziel Surface blitten
bool onBlitImage(SDL_Surface *surf_Dest, SDL_Surface *surf_Src, int x, int y, int X2, int Y2, int W, int H) {
    if(surf_Dest == 0 || surf_Src == 0) {
        return false;
    }

    SDL_Rect DestR;

    DestR.x = x;
    DestR.y = y;

    SDL_Rect SrcR;

    SrcR.x = X2;
    SrcR.y = Y2;
    SrcR.w = W;
    SrcR.h = H;

    SDL_BlitSurface(surf_Src, &SrcR, surf_Dest, &DestR);

    return true;
}


// SetColorKey
// Aufgabe: Farbe eines Bmp transparent machen
bool CSurface::SetColorKey(SDL_Surface *surf_Dest, int R, int G, int B) {
    if(surf_Dest == NULL) {
        return false;
    }

    SDL_SetColorKey(surf_Dest, SDL_SRCCOLORKEY | SDL_RLEACCEL, SDL_MapRGB(surf_Dest->format, R, G, B));

    return true;
}
