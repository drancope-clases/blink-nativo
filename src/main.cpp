#include "tigr.h"
#include <chrono>

TPixel color[2] = {tigrRGB(0x35, 0x75, 0xef), tigrRGB(0x33, 0x33, 0x33)};

bool estado = false;

void blink() {
    estado = !estado;
}

int main(int argc, char *argv[])
{
    using namespace std::chrono;
    time_point<steady_clock> tiempoInicial = steady_clock::now();
    Tigr *screen = tigrWindow(90, 90, "Blink", TIGR_AUTO);
    while (!tigrClosed(screen))
    {
        time_point<steady_clock> tiempoActual = steady_clock::now();
        if (duration_cast<milliseconds>(tiempoActual - tiempoInicial).count() > 1000) {
            blink();
            tiempoInicial = tiempoActual;
        }
        tigrClear(screen, tigrRGB(0x80, 0x90, 0xa0));
        tigrFillCircle(screen, 45, 45, 30, color[estado]);
        tigrUpdate(screen);
    }
    tigrFree(screen);
    return 0;
}