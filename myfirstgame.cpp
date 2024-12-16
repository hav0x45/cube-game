#define SDL_MAIN_HANDLED
#include <iostream>
#include <Windows.h>
#include "include/SDL.h"

int main() {

    // Ikkuna muuttujat
    const int SCREEN_WIDTH = 1280;
    const int SCREEN_HEIGHT = 720;

    // Kuutio muuttujat
    const int CUBE_WIDTH = 50;
    const int CUBE_HEIGHT = 50;

    // Luo ikkuna
    SDL_Window* window = SDL_CreateWindow("Ikkuna", 50, 50, SCREEN_WIDTH, SCREEN_HEIGHT, 0);

    // Luo renderer
    SDL_Renderer* renderer = SDL_CreateRenderer(window, 0, 0);

    // Luo kulmio
    SDL_Rect rect;
    rect.x = SCREEN_WIDTH / 2 - CUBE_WIDTH / 2;
    rect.y = SCREEN_HEIGHT / 2 - CUBE_HEIGHT / 2;
    rect.w = CUBE_WIDTH;
    rect.h = CUBE_HEIGHT;

    // Peli loopin muuttuja
    bool running = true;

    // Peli looppi
    while (running == true) {

        // Katso painetaanko välilyöntiä
        if (GetAsyncKeyState(VK_SPACE)) {
            
            // Vähennä yksi piste suorakulmion y koordinaatista
            rect.y--;
        }

        // Aseta renderöijän väri
        SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
        
        // Renderöi tyhjä ruutu
        SDL_RenderClear(renderer);
        
        // Aseta renderöijän väri
        SDL_SetRenderDrawColor(renderer, 0, 255, 0, 255);
        
        // Renderöi suorakulmio tai jotain sellaista
        SDL_RenderFillRect(renderer, &rect);
        
        // Renderöi ruutu
        SDL_RenderPresent(renderer);

        // Luupin viive
        SDL_Delay(1);

        // Jos painetaan ENDiä riko looppi
        if (GetAsyncKeyState(VK_END)) {
            running = false;
        }
    }

    // Riko SDL ikkuna
    SDL_DestroyWindow(window);
    
    // Quittaa ohjelmasta
    SDL_Quit();

    // Ohjelma ajettiin onnistuneesti!
    return 0;
}