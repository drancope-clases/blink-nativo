#include "tigr.h"
#include <chrono>

#define AZUL tigrRGB(0x35, 0x75, 0xef)
#define GRIS tigrRGB(0x33, 0x33, 0x33)

TPixel color[2] = {AZUL, GRIS};

bool estado = false;

void blink() {
    estado = !estado;
}

int main(int argc, char *argv[])
{
    std::chrono::time_point<std::chrono::steady_clock> tiempoInicial = std::chrono::steady_clock::now();
    Tigr *screen = tigrWindow(90, 90, "Blink", TIGR_AUTO);
    while (!tigrClosed(screen))
    {
        std::chrono::time_point<std::chrono::steady_clock> tiempoActual = std::chrono::steady_clock::now();
        if (std::chrono::duration_cast<std::chrono::milliseconds>(tiempoActual - tiempoInicial).count() > 1000) {
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