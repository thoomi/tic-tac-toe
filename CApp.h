#ifndef CAPP_H_
#define CAPP_H_

#include <SDL/SDL.h>
#include "CEvent.h"

class CApp : public CEvent {
    private:
        bool GameRunning;
        int RoundFinish;
        bool artificialEnemy;
        SDL_Surface *mainScreen;
        SDL_Surface *gameboard;
        SDL_Surface *feldX;
        SDL_Surface *feldO;
        SDL_Surface *resetbutton;
        SDL_Surface *whowon;


        // Spielfeld Array
        int gatter[9];
        int currentPlayer;
        // Enum Type für bessere Übersichtlichkeit
        enum {TYPE_NONE = 0, TYPE_X, TYPE_O};

    public:
        CApp();
        void onExecute();
        bool onInit();
        void onExit();
        void onEvent(SDL_Event *Event);
        void onUpdate();
        void onRender();
        void onCleanup();
        void whoWon();

        void OnKeyDown(SDLKey sym, SDLMod mod, Uint16 unicode);
        void OnLButtonDown(int mX, int mY);
        void ResetGame();
        void SetCell(int pos, int type);

};

#endif
