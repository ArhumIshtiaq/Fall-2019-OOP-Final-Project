/*This source code copyrighted by Lazy Foo' Productions (2004-2015)
  and may not be redistributed without written permission.*/

//Using SDL, SDL_image, standard IO, math, and strings

#include <SDL.h>
#include <SDL_image.h>

// #include "Game.hpp"

#include <cmath>
#include <cstdio>
#include <iostream>
#include <string>
#include <ctime>
#include <cstdlib>

const int SCREEN_WIDTH = 1280;
const int SCREEN_HEIGHT = 960;

//Loads individual image as texture
SDL_Texture *loadTexture(std::string path);

//The window we'll be rendering to
SDL_Window *gWindow = NULL;

//The window renderer
SDL_Renderer *gRenderer = NULL;

SDL_Surface *gScreenSurface = NULL;

SDL_Surface *image = NULL;

std::string bg;

bool init()
{
    //Initialization mouseClicked
    bool success = true;

    //Initialize SDL
    if (SDL_Init(SDL_INIT_VIDEO) < 0)
    {
        printf("SDL could not initialize! SDL Error: %s\n", SDL_GetError());
        success = false;
    }
    else
    {

        gWindow = SDL_CreateWindow("SDL Tutorial", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
        if (gWindow == NULL)
        {
            printf("Window could not be created! SDL Error: %s\n", SDL_GetError());
            success = false;
        }
        else
        {
            gScreenSurface = SDL_GetWindowSurface(gWindow);
            //start PNG loading
            int imgFlags = IMG_INIT_PNG;
            if (!(IMG_Init(imgFlags) & imgFlags))
            {
                printf("SDL_image could not initialize! SDL_image Error: %s\n", IMG_GetError());
                success = false;
            }
        }
    }

    return success;
}

// bool loadMedia()
// {
//     //Loading success flag
//     bool success = true;

//     //Load sprite sheet texture
//     if (!gSpriteSheetTexture.loadFromFile("C://Users//Arhum Ishtiaq//Desktop//Habib University - Arhum Ishtiaq - ai05182//Fall 2019//OOP//Project//Final Project//Fall-2019-OOP-Final-Project//Assets//bgn.png", gWindow, gRenderer))
//     {
//         printf("Failed to load sprite sheet texture!\n");
//         success = false;
//     }
//     else
//     {
//         //Set top left sprite
//         gSpriteClips[0].x = 0;
//         gSpriteClips[0].y = 0;
//         gSpriteClips[0].w = 1280;
//         gSpriteClips[0].h = 960;

//         //Set top right sprite
//         gSpriteClips[1].x = 1280;
//         gSpriteClips[1].y = 0;
//         gSpriteClips[1].w = 1280;
//         gSpriteClips[1].h = 960;

//         //Set bottom left sprite
//         gSpriteClips[2].x = 2560;
//         gSpriteClips[2].y = 0;
//         gSpriteClips[2].w = 1280;
//         gSpriteClips[2].h = 960;

//         //Set bottom right sprite
//         gSpriteClips[3].x = 3840;
//         gSpriteClips[3].y = 0;
//         gSpriteClips[3].w = 1280;
//         gSpriteClips[3].h = 960;

//         gSpriteClips[4].x = 5120;
//         gSpriteClips[4].y = 0;
//         gSpriteClips[4].w = 1280;
//         gSpriteClips[4].h = 960;

//         gSpriteClips[5].x = 6500;
//         gSpriteClips[5].y = 0;
//         gSpriteClips[5].w = 1280;
//         gSpriteClips[5].h = 960;
//     }

//     return success;
// }

bool loadBG()
{
    bool success = true;
    time_t curr_time;
    curr_time = time(NULL);
    tm *tm_local = localtime(&curr_time);
    std::cout << tm_local->tm_hour << std::endl;
    if (tm_local->tm_hour >= 6 && tm_local->tm_hour <= 18)
    {
        bg = "BGD.jpg";
    }
    else
    {
        bg = "BGN.jpg";
    }
    std::string path = "Assets/" + bg;
    image = IMG_Load(path.c_str());
    return success;
}

void close()
{
    SDL_DestroyRenderer(gRenderer);
    SDL_DestroyWindow(gWindow);
    gWindow = NULL;
    gRenderer = NULL;
    IMG_Quit();
    SDL_Quit();
}

SDL_Surface *loadSurface(std::string path)
{
    //The final optimized image
    SDL_Surface *optimizedSurface = NULL;

    //Load image at specified path
    SDL_Surface *loadedSurface = IMG_Load(path.c_str());
    if (loadedSurface == NULL)
    {
        printf("Unable to load image %s! SDL_image Error: %s\n", path.c_str(), IMG_GetError());
    }
    else
    {
        //Convert surface to screen format
        optimizedSurface = SDL_ConvertSurface(loadedSurface, gScreenSurface->format, 0);
        if (optimizedSurface == NULL)
        {
            printf("Unable to optimize image %s! SDL Error: %s\n", path.c_str(), SDL_GetError());
        }

        //Get rid of old loaded surface
        SDL_FreeSurface(loadedSurface);
    }

    return optimizedSurface;
}

int main(int argc, char *argv[])
{
    if (!init())
    {
        printf("Failed to initialize!\n");
    }
    else
    {

        if (!loadBG())
        {
            printf("Failed to load media!\n");
        }
        else
        {
            bool quit = false;
            SDL_Event e;

            bool mouseClicked = false;

            while (!quit)
            {

                std::string path = "C://Users//Arhum Ishtiaq//Desktop//Habib University - Arhum Ishtiaq - ai05182//Fall 2019//OOP//Project//Final Project//Fall-2019-OOP-Final-Project//Assets//bgn1.png";
                image = loadSurface(path.c_str());
                SDL_BlitSurface(image, NULL, gScreenSurface, NULL);
                SDL_UpdateWindowSurface(gWindow);
                SDL_Delay(100);
                path = "C://Users//Arhum Ishtiaq//Desktop//Habib University - Arhum Ishtiaq - ai05182//Fall 2019//OOP//Project//Final Project//Fall-2019-OOP-Final-Project//Assets//bgn2.png";
                image = loadSurface(path.c_str());
                SDL_BlitSurface(image, NULL, gScreenSurface, NULL);
                SDL_UpdateWindowSurface(gWindow);
                SDL_Delay(100);
                path = "C://Users//Arhum Ishtiaq//Desktop//Habib University - Arhum Ishtiaq - ai05182//Fall 2019//OOP//Project//Final Project//Fall-2019-OOP-Final-Project//Assets//bgn3.png";
                image = loadSurface(path.c_str());
                SDL_BlitSurface(image, NULL, gScreenSurface, NULL);
                SDL_UpdateWindowSurface(gWindow);
                SDL_Delay(100);
                path = "C://Users//Arhum Ishtiaq//Desktop//Habib University - Arhum Ishtiaq - ai05182//Fall 2019//OOP//Project//Final Project//Fall-2019-OOP-Final-Project//Assets//bgn4.png";
                image = loadSurface(path.c_str());
                SDL_BlitSurface(image, NULL, gScreenSurface, NULL);
                SDL_UpdateWindowSurface(gWindow);
                SDL_Delay(100);
                path = "C://Users//Arhum Ishtiaq//Desktop//Habib University - Arhum Ishtiaq - ai05182//Fall 2019//OOP//Project//Final Project//Fall-2019-OOP-Final-Project//Assets//bgn5.png";
                image = loadSurface(path.c_str());
                SDL_BlitSurface(image, NULL, gScreenSurface, NULL);
                SDL_UpdateWindowSurface(gWindow);
                SDL_Delay(100);
                //event handling
                while (SDL_PollEvent(&e) != 0)
                {
                    switch (e.type)
                    {
                    case SDL_KEYDOWN:
                        switch (e.key.keysym.sym)
                        {
                        case SDLK_ESCAPE:
                            close();
                            return 0;
                        }
                    case SDL_WINDOWEVENT:
                        switch (e.window.event)
                        {

                        case SDL_WINDOWEVENT_CLOSE:
                            close();
                            return 0;
                        }
                    }
                }
            }
            //deallocation and closing
            close();
            return 0;
        }
    }
}
