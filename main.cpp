#include "CApp.h"

int main(int argc, char *argv[]) {

    // Klasse des Spiels erstellen
    CApp theApp;
    // Initialisierung der SDL und Spieldaten laden
    if (theApp.onInit() == false) {
        return 0; // Falls nicht erfolgreich: -1 zurückgeben
    }
    // Spiel ausführen
    theApp.onExecute();
    // Speicher clearen und SDL herunterfahren
    theApp.onCleanup();

    return 0;
}
