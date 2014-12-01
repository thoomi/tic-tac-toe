#include "CApp.h"
#include "CSurface.h"
#include "CEvent.h"
#include "ArtInt.h"
#include <iostream>

// Konstruktor
// Aufgabe: Allgemeine Initialisierung
CApp::CApp() {
    mainScreen = 0;
    gameboard = 0;
    feldO = 0;
    feldX = 0;
    resetbutton = 0;
    whowon = 0;
    currentPlayer = 1;
    GameRunning = true;
    RoundFinish = 0;
    artificialEnemy = true;
}


// onExecute
// Aufgabe: Spiel ausführen bzw. laufen lassen
void CApp::onExecute() {

    SDL_Event Event;

    // Spielschleife
    while(GameRunning) {


        // Events durchlaufen
        while(SDL_PollEvent(&Event)) {
            onEvent(&Event);
        }

        // Prüfen wer gewonnen hat
        whoWon();

        // Spieldaten updaten
        onUpdate();

        // Daten auf Screen rendern
        onRender();

    }
}


// onInit
// Aufgabe: Spiel initialisieren und Grafiken laden
bool CApp::onInit() {
    // Initialisiere alle SDL Systeme
    if(SDL_Init(SDL_INIT_EVERYTHING) < 0) {
        return false;
    }

    // Erstelle das Fenster bzw. starte den VideoMode
    if((mainScreen = SDL_SetVideoMode(450, 450, 32, SDL_HWSURFACE | SDL_DOUBLEBUF)) == 0) {
        return false;
    }

    // Window Caption setzten
    SDL_WM_SetCaption( "Lonely X and O's  -- by Thomi", 0 );

    // Bild für das Spielbrett laden
    if ((gameboard = CSurface::onLoadImage("images/gameboard.bmp")) == 0) {
        return false;
    }

    // Spielstein des X-Spielers laden
    if ((feldX = CSurface::onLoadImage("images/feldX.bmp")) == 0) {
        return false;
    }

    // Spielstein des O-Spielers laden
    if ((feldO = CSurface::onLoadImage("images/feldO.bmp")) == 0) {
        return false;
    }

    // Reset Button laden
    if ((resetbutton = CSurface::onLoadImage("images/gamereset.bmp")) == 0) {
        return false;
    }


    // Color-Key setzen
    CSurface::SetColorKey(feldO, 255, 0, 255);
    CSurface::SetColorKey(feldX, 255, 0, 255);


    // Spielfeld auf Anfang setzen
    ResetGame();

    // Alles wurde ordnungsgemäß geladen
    return true;
}


// onEvent
//Aufgabe: Events abarbeiten
void CApp::onEvent(SDL_Event *Event) {
    // Events an die Event Klasse übergeben
    CEvent::onEvent(Event);

}


// onQuit
// Aufgabe: Spiel beenden
void CApp::onExit() {
    GameRunning = false;
}

// onLoop
// Aufgabe: Hauptspielschleife -->Spiel am leben erhalten :)
void CApp::onUpdate() {

    // Künstliche Intelligenz
    if(artificialEnemy && currentPlayer == 2 && RoundFinish == 0) {
        CArtInt::makemove(&gatter[0]);
        currentPlayer = 1;
    }
}


// onRender
// Aufgabe: Surfaces und Änderungen auf den Screen rendern
void CApp::onRender() {
    // Spielbrett auf den mainScreen blitten
    CSurface::onBlitImage(mainScreen, gameboard, 0, 0);


    // Aktuellen Spielstand rendern
    for(int i = 0;i < 9;i++) {
        int X = (i % 3) * 150;
        int Y = (i / 3) * 150;

        if(gatter[i] == TYPE_X) {
            CSurface::onBlitImage(mainScreen, feldX, X, Y);
        }
        else if(gatter[i] == TYPE_O) {
            CSurface::onBlitImage(mainScreen, feldO, X, Y);
        }
    }

    // Prüfen ob Runde beendet ist und Gewinner anzeigen
    if (RoundFinish != 0) {
        CSurface::onBlitImage(mainScreen, resetbutton, 150, 150);
        if(RoundFinish == 1) {
            whowon = CSurface::onLoadImage("images/owon.bmp");
            CSurface::onBlitImage(mainScreen, whowon, 150, 300);
        }
        else if(RoundFinish == 2) {
            whowon = CSurface::onLoadImage("images/xwon.bmp");
            CSurface::onBlitImage(mainScreen, whowon, 150, 300);
        }
        else {
            whowon = CSurface::onLoadImage("images/draw.bmp");
            CSurface::onBlitImage(mainScreen, whowon, 150, 300);
        }
    }

    SDL_Flip(mainScreen);
}


// onCleanup
// Aufgabe: Speicherfreigeben und aufräumen
void CApp::onCleanup() {
    // Speicher der Bilder freigeben
    SDL_FreeSurface(mainScreen);
    SDL_FreeSurface(gameboard);
    SDL_FreeSurface(feldO);
    SDL_FreeSurface(feldX);
    SDL_FreeSurface(resetbutton);

    // SDL Systeme herunterfahren
    SDL_Quit();
}


// OnKeyDown
// Aufgabe: Falls der User eine Taste drückt
void CApp::OnKeyDown(SDLKey sym, SDLMod mod, Uint16 unicode) {
    // Falls der user Escape drückt, beende das spiel
    if((sym == SDLK_ESCAPE) && (mod == KMOD_NONE)) {
        GameRunning = false;
    }
}


// ResetGame
// Aufgabe: Spielfeld resetten
void CApp::ResetGame() {
    for(int i=0; i < 9; i++) {
        gatter[i] = TYPE_NONE;
    }

    RoundFinish = 0;

    SDL_FreeSurface(whowon);

}


// SetCell
// Aufgabe: Spielstein setzen
void CApp::SetCell(int pos, int type) {
    if(pos < 0 || pos >= 9) {
        return;
    }
    if(type < 0 || type > TYPE_O) {
        return;
    }
    gatter[pos] = type;

}


// OnLButtonDown
// Aufgabe: Linke Maustaste wurde gedrückt
void CApp::OnLButtonDown(int mX, int mY) {
    int pos = mX / 150;
    pos = pos + ((mY / 150) * 3);


    if(RoundFinish != 0) {
        if(mX > 150 && mY > 150 && mX < 300 && mY < 300) {
            ResetGame();
        }
    }
    else {
        if (gatter[pos] != TYPE_NONE) {
            return;
        }
        else if(currentPlayer == 1) {
            SetCell(pos, TYPE_X);
            currentPlayer = 2;
        }
        else if(currentPlayer == 2 && artificialEnemy == false){

            SetCell(pos, TYPE_O);
            currentPlayer = 1;
        }
    }
}


// whoWon
// Aufgabe: Prüfen ob es einen Gewinner gibt
void CApp::whoWon() {
    if((gatter[0] != TYPE_NONE) && (gatter[0] == gatter[1]) && (gatter[1] == gatter[2])) {
        RoundFinish = currentPlayer;
    }
    else if ((gatter[0] != TYPE_NONE) && (gatter[0] == gatter[3]) && (gatter[3] == gatter[6])) {
        RoundFinish = currentPlayer;
    }
    else if ((gatter[0] != TYPE_NONE) && (gatter[0] == gatter[4]) && (gatter[4] == gatter[8])) {
        RoundFinish = currentPlayer;
    }
    else if ((gatter[3] != TYPE_NONE) && (gatter[3] == gatter[4]) && (gatter[4] == gatter[5])) {
        RoundFinish = currentPlayer;
    }
    else if ((gatter[6] != TYPE_NONE) && (gatter[6] == gatter[7]) && (gatter[7] == gatter[8])) {
        RoundFinish = currentPlayer;
    }
    else if ((gatter[1] != TYPE_NONE) && (gatter[1] == gatter[4]) && (gatter[4] == gatter[7])) {
        RoundFinish = currentPlayer;
    }
    else if ((gatter[2] != TYPE_NONE) && (gatter[2] == gatter[5]) && (gatter[5] == gatter[8])) {
        RoundFinish = currentPlayer;
    }
    else if ((gatter[2] != TYPE_NONE) && (gatter[2] == gatter[4]) && (gatter[4] == gatter[6])) {
        RoundFinish = currentPlayer;
    }
    // Unentschieden
    else if (gatter[0] != TYPE_NONE && gatter[1] != TYPE_NONE && gatter[2] != TYPE_NONE &&
             gatter[3] != TYPE_NONE && gatter[4] != TYPE_NONE && gatter[5] != TYPE_NONE &&
             gatter[6] != TYPE_NONE && gatter[7] != TYPE_NONE && gatter[8] != TYPE_NONE) {

                RoundFinish = 3;
             }
}


