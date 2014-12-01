#include "ArtInt.h"

// makemove
// Aufgabe: das aktuelle Gatter aus dem Spielabrufen
void CArtInt::makemove(int array[]) {

    if (!CArtInt::completeRow(&array[0])) {

        if (!CArtInt::blockRow(&array[0])) {

            CArtInt::randomMove(&array[0]);

        }
    }
}


// completeRow
// Aufgabe: eine Reihe des Gatters vervollständigen
bool CArtInt::completeRow(int array[]) {

    // Obere waagrechte Reihe vervollständigen
    if((array[0] == 0) && (array[1] == 2) && (array[2] == 2)) {
        array[0] = 2;
        return true;
    }
    else if((array[0] == 2) && (array[1] == 0) && (array[2] == 2)) {
        array[1] = 2;
        return true;
    }
    else if((array[0] == 2) && (array[1] == 2) && (array[2] == 0)) {
        array[2] = 2;
        return true;
    }

    // mittlere waagrechte Reihe vervollständigen
    if((array[3] == 0) && (array[4] == 2) && (array[5] == 2)) {
        array[3] = 2;
        return true;
    }
    else if((array[3] == 2) && (array[4] == 0) && (array[5] == 2)) {
        array[4] = 2;
        return true;
    }
    else if((array[3] == 2) && (array[4] == 2) && (array[5] == 0)) {
        array[5] = 2;
        return true;
    }

    // untere waagrechte Reihe vervollständigen
    if((array[6] == 0) && (array[7] == 2) && (array[8] == 2)) {
        array[6] = 2;
        return true;
    }
    else if((array[6] == 2) && (array[7] == 0) && (array[8] == 2)) {
        array[7] = 2;
        return true;
    }
    else if((array[6] == 2) && (array[7] == 2) && (array[8] == 0)) {
        array[8] = 2;
        return true;
    }

    // linke senkrechte Reihe vervollständigen
    if((array[0] == 0) && (array[3] == 2) && (array[6] == 2)) {
        array[0] = 2;
        return true;
    }
    else if((array[0] == 2) && (array[3] == 0) && (array[6] == 2)) {
        array[3] = 2;
        return true;
    }
    else if((array[0] == 2) && (array[3] == 2) && (array[6] == 0)) {
        array[6] = 2;
        return true;
    }

    // mittlere senkrechte Reihe vervollständigen
    if((array[1] == 0) && (array[4] == 2) && (array[7] == 2)) {
        array[1] = 2;
        return true;
    }
    else if((array[1] == 2) && (array[4] == 0) && (array[7] == 2)) {
        array[4] = 2;
        return true;
    }
    else if((array[1] == 2) && (array[4] == 2) && (array[7] == 0)) {
        array[7] = 2;
        return true;
    }

    // rechte senkrechte Reihe vervollständigen
    if((array[2] == 0) && (array[5] == 2) && (array[8] == 2)) {
        array[2] = 2;
        return true;
    }
    else if((array[2] == 2) && (array[5] == 0) && (array[8] == 2)) {
        array[5] = 2;
        return true;
    }
    else if((array[2] == 2) && (array[5] == 2) && (array[8] == 0)) {
        array[8] = 2;
        return true;
    }

    // linke schräge Reihe vervollständigen
    if((array[0] == 0) && (array[4] == 2) && (array[8] == 2)) {
        array[0] = 2;
        return true;
    }
    else if((array[0] == 2) && (array[4] == 0) && (array[8] == 2)) {
        array[4] = 2;
        return true;
    }
    else if((array[0] == 2) && (array[4] == 2) && (array[8] == 0)) {
        array[8] = 2;
        return true;
    }

    // rechte schräge Reihe vervollständigen
    if((array[2] == 0) && (array[4] == 2) && (array[6] == 2)) {
        array[2] = 2;
        return true;
    }
    else if((array[2] == 2) && (array[4] == 0) && (array[6] == 2)) {
        array[4] = 2;
        return true;
    }
    else if((array[2] == 2) && (array[4] == 2) && (array[6] == 0)) {
        array[6] = 2;
        return true;
    }

    return false;
}


// blockRow
// Aufgabe: die Reihe des Gegners blockieren
bool CArtInt::blockRow(int array[]) {

        // Obere waagrechte Reihe blockieren
    if((array[0] == 0) && (array[1] == 1) && (array[2] == 1)) {
        array[0] = 2;
        return true;
    }
    else if((array[0] == 1) && (array[1] == 0) && (array[2] == 1)) {
        array[1] = 2;
        return true;
    }
    else if((array[0] == 1) && (array[1] == 1) && (array[2] == 0)) {
        array[2] = 2;
        return true;
    }

    // mittlere waagrechte Reihe blockieren
    if((array[3] == 0) && (array[4] == 1) && (array[5] == 1)) {
        array[3] = 2;
        return true;
    }
    else if((array[3] == 1) && (array[4] == 0) && (array[5] == 1)) {
        array[4] = 2;
        return true;
    }
    else if((array[3] == 1) && (array[4] == 1) && (array[5] == 0)) {
        array[5] = 2;
        return true;
    }

    // untere waagrechte Reihe blockieren
    if((array[6] == 0) && (array[7] == 1) && (array[8] == 1)) {
        array[6] = 2;
        return true;
    }
    else if((array[6] == 1) && (array[7] == 0) && (array[8] == 1)) {
        array[7] = 2;
        return true;
    }
    else if((array[6] == 1) && (array[7] == 1) && (array[8] == 0)) {
        array[8] = 2;
        return true;
    }

    // linke senkrechte Reihe blockieren
    if((array[0] == 0) && (array[3] == 1) && (array[6] == 1)) {
        array[0] = 2;
        return true;
    }
    else if((array[0] == 1) && (array[3] == 0) && (array[6] == 1)) {
        array[3] = 2;
        return true;
    }
    else if((array[0] == 1) && (array[3] == 1) && (array[6] == 0)) {
        array[6] = 2;
        return true;
    }

    // mittlere senkrechte Reihe blockieren
    if((array[1] == 0) && (array[4] == 1) && (array[7] == 1)) {
        array[1] = 2;
        return true;
    }
    else if((array[1] == 1) && (array[4] == 0) && (array[7] == 1)) {
        array[4] = 2;
        return true;
    }
    else if((array[1] == 1) && (array[4] == 1) && (array[7] == 0)) {
        array[7] = 2;
        return true;
    }

    // rechte waagrechte Reihe vervollständigen
    if((array[2] == 0) && (array[5] == 1) && (array[8] == 1)) {
        array[2] = 2;
        return true;
    }
    else if((array[2] == 1) && (array[5] == 0) && (array[8] == 1)) {
        array[5] = 2;
        return true;
    }
    else if((array[2] == 1) && (array[5] == 1) && (array[8] == 0)) {
        array[8] = 2;
        return true;
    }

    // linke schräge Reihe blockieren
    if((array[0] == 0) && (array[4] == 1) && (array[8] == 1)) {
        array[0] = 2;
        return true;
    }
    else if((array[0] == 1) && (array[4] == 0) && (array[8] == 1)) {
        array[4] = 2;
        return true;
    }
    else if((array[0] == 1) && (array[4] == 1) && (array[8] == 0)) {
        array[8] = 2;
        return true;
    }

    // rechte schräge Reihe blockieren
    if((array[2] == 0) && (array[4] == 1) && (array[6] == 1)) {
        array[2] = 2;
        return true;
    }
    else if((array[2] == 1) && (array[4] == 0) && (array[6] == 1)) {
        array[4] = 2;
        return true;
    }
    else if((array[2] == 1) && (array[4] == 1) && (array[6] == 0)) {
        array[6] = 2;
        return true;
    }

    return false;
}


// randomMove
// Aufgabe: zufälligen Zug machen
bool CArtInt::randomMove(int array[]) {
    int random = 0;

        do {

            random = rand() % 9;

        }while(array[random] != 0);


    array[random] = 2;

    return true;

}
