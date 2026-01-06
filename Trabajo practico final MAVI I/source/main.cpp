#ifndef NDEBUG
#include <vld.h> // Visual Leak Detector, útil en modo Debug para detectar fugas de memoria
#endif

#include "raylib.h"
#include "GameController.h"

int main(void)
{

    GameController* GM = new GameController();
    
    GM->Run();

    return 0;
}

