#include "tigr.h"
#include <chrono>

TPixel color[2] = {tigrRGB(0x35, 0x75, 0xef), tigrRGB(0x33, 0x33, 0x33)};

void blink(bool *estado, Tigr *screen) {
    *estado = !*estado;
    tigrFillCircle(screen, 80, 80, 30, color[*estado]);
    tigrUpdate(screen);
}

int main(int argc, char *argv[])
{
    bool estado = false;
    using namespace std::chrono;
    time_point<steady_clock> tiempoInicial = steady_clock::now();
    Tigr *screen = tigrWindow(160, 160, "Blink", TIGR_AUTO);
    tigrClear(screen, tigrRGB(0x80, 0x90, 0xa0));
    while (!tigrClosed(screen))
    {
        time_point<steady_clock> tiempoActual = steady_clock::now();
        if (duration_cast<milliseconds>(tiempoActual - tiempoInicial).count() > 1000) {
            blink(&estado, screen);
            tiempoInicial = tiempoActual;
        }

        
    }
    tigrFree(screen);
    return 0;
}