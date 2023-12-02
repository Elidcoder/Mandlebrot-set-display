//So SDL doesn't kinda define main
#define SDL_MAIN_HANDLED
//Include main include
#include<SDL2/SDL.h>


#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h> 
#include<complex.h>

double complex mandleboy(double complex z, double complex c){
    //MB start point (c) z = 0 keep running z*z+c diverge == not in set so coloured
    return z*z+c;
}
int main(){
    #define len 800
    int n = 0;
    double fact = 1;
    int offsetx = 0;
    int offsety = 0;
    SDL_Init(SDL_INIT_EVERYTHING);

    SDL_Window *window = SDL_CreateWindow("Fractal", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, len, len, 0);
    //Graphics for intense operations (accelerate)
    SDL_Renderer *renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);

    SDL_Event event;

    //SDL_SetRenderDrawColor(renderer, 0,0,0,255);
    SDL_SetRenderDrawColor(renderer,0, 255, 255,255);
    SDL_RenderClear(renderer);
    //not copied in function pass (by val)
    static float complex grid[len][len];

    for(;;){

        //&variable == pointer to (variable)
        SDL_PollEvent(&event);

        switch (event.type){
            case SDL_QUIT:
                //SDL does quit
                SDL_Quit();
                //Exit with 0 errors (c program) [0 = no error others = different errors]
                exit(0);
                break;
            case SDL_KEYDOWN:
                if (event.key.keysym.sym == SDLK_EQUALS){
                        //SDL_SetRenderDrawColor(renderer, 0,0,0,255);
                        SDL_SetRenderDrawColor(renderer,0, 255, 255,255);
                        SDL_RenderClear(renderer);
                        n = 0;
                        fact /= 0.5;
                }
                else if (event.key.keysym.sym == SDLK_MINUS){
                        //SDL_SetRenderDrawColor(renderer, 0,0,0,255);
                        SDL_SetRenderDrawColor(renderer,0, 255, 255,255);
                        SDL_RenderClear(renderer);
                        n = 0;
                        fact /= 2;
                }
                else if (event.key.keysym.sym == SDLK_UP){
                        //SDL_SetRenderDrawColor(renderer, 0,0,0,255);
                        SDL_SetRenderDrawColor(renderer,0, 255, 255,255);
                        SDL_RenderClear(renderer);
                        n = 0;
                        offsety -= len/16;
                }
                else if (event.key.keysym.sym == SDLK_DOWN){
                        //SDL_SetRenderDrawColor(renderer, 0,0,0,255);
                        SDL_SetRenderDrawColor(renderer,0, 255, 255,255);
                        SDL_RenderClear(renderer);
                        n = 0;
                        offsety +=  len/16;
                }
                else if (event.key.keysym.sym == SDLK_LEFT){
                        //SDL_SetRenderDrawColor(renderer, 0,0,0,255);
                        SDL_SetRenderDrawColor(renderer,0, 255, 255,255);
                        SDL_RenderClear(renderer);
                        n = 0;
                        offsetx -=  len/16;
                }
                else if (event.key.keysym.sym == SDLK_RIGHT){
                        //SDL_SetRenderDrawColor(renderer, 0,0,0,255);
                        SDL_SetRenderDrawColor(renderer,0, 255, 255,255);
                        SDL_RenderClear(renderer);
                        n = 0;
                        offsetx += len/16;
                }
                else if (event.key.keysym.sym == SDLK_r){
                        //SDL_SetRenderDrawColor(renderer, 0,0,0,255);
                        SDL_SetRenderDrawColor(renderer,0, 255, 255,255);
                        SDL_RenderClear(renderer);
                        n = 0;
                        fact = 1;
                        offsetx = 0;
                        offsety = 0;
                }
                
        }
        // if anything was drawn update the window
        SDL_RenderPresent(renderer);
        //SDL_SetRenderDrawColor(renderer, 255 - 255 * (float)(n%8)/8.0f,125,125,255);
        SDL_SetRenderDrawColor(renderer, 0,0,191 - 191 * (float)(n%8)/8.0f,255);
        //SDL_SetRenderDrawColor(renderer, 255 * (float)(n%8)/8.0f,0,255 * (float)(n%8)/8.0f,255);
        for (int r = 0; r< len; r++){
            for (int i = 0; i< len; i++){
                if (n==0) grid[r][i] = 0;
                if (cabs(grid[r][i]) <= 2){
                    grid[r][i] = mandleboy(grid[r][i], ((float complex)(r-len/2-offsetx))/(float)(len/4 * fact) + ((float complex)(i-len/2-offsety))/(float)(len/4 * fact) * I);
                    if (cabs(grid[r][i]) > 2){
                        SDL_RenderDrawPoint(renderer, r, i);
                    }
                }
                



            }
        }

        n++;
    }
    return 0;
}