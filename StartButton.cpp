#include "StartButton.hpp"


void StartButton::click(SDL_Rect*)
{
    int x, y;
    SDL_Event event;

    while(1)
    {
        while(SDL_PollEvent(&event))
        {
            switch(event.type)
            {
                case SDL_QUIT:
                    close();
                    break;
                case SDL_MOUSEBUTTONDOWN:
                    x = event.button.x;
                    y = event.motion.y;
                    if(x>=13 && x<=256 && y>=553 && y<=643)
                    {
                        image = loadSurface("Assets/BGD.jpg");
                        SDL_BlitSurface(image, NULL, gScreenSurface, NULL);
                        SDL_UpdateWindowSurface(gWindow);
                    }

            }
        }
    }
}
