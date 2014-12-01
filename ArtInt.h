#include "SDL/SDL.h"

class CArtInt {
    private:

    public:
        static void makemove(int array[]);
        static bool completeRow(int array[]);
        static bool blockRow(int array[]);
        static bool randomMove(int array[]);
};
