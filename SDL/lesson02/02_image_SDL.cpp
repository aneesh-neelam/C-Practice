#include <stdio.h>
#include <SDL2/SDL.h>

//Screen dimension constants
const int SCREEN_WIDTH = 130;
const int SCREEN_HEIGHT = 25;

//The window we'll be rendering to
SDL_Window* gWindow = NULL;

//The surface contained by the window
SDL_Surface* gScreenSurface = NULL;

//The image we will load and show on the screen
SDL_Surface* gImage = NULL;

bool init_SDL()
{
  //Initialization flag
    bool success = true;

    //Initialize SDL
    if(SDL_Init(SDL_INIT_VIDEO) < 0)
    {
        printf("SDL could not initialize! SDL_Error: %s\n", SDL_GetError());
        success = false;
    }
    else
    {
        //Create window
        gWindow = SDL_CreateWindow("SDL Tutorial", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
        if(gWindow == NULL)
        {
            printf("Window could not be created! SDL_Error: %s\n", SDL_GetError());
            success = false;
        }
        else
        {
            //Get window surface
            gScreenSurface = SDL_GetWindowSurface( gWindow );
        }
    }

    return success;
}

bool load_image()
{
    //Loading success flag
    bool success = true;

    //Load image
    gImage = SDL_LoadBMP("/home/aneesh/Pictures/captcha.bmp");
    if(gImage == NULL)
    {
        printf("Unable to load image %s! SDL Error: %s\n", "/home/aneesh/Pictures/captcha.bmp", SDL_GetError());
        success = false;
    }

    return success;
}

void close_window()
{
    //Deallocate surface
    SDL_FreeSurface(gImage);
    gImage = NULL;

    //Destroy window
    SDL_DestroyWindow(gWindow);
    gWindow = NULL;

    //Quit SDL subsystems
    SDL_Quit();
}

int main(int argc, char* args[])
{
    //Start up SDL and create window
    if(!(init_SDL()))
    {
        printf("Failed to initialize!\n");
    }
    else
    {
        //Load image
        if((!load_image()))
        {
            printf("Failed to load media!\n");
        }
        else
        {
            //Apply the image
            SDL_BlitSurface(gImage, NULL, gScreenSurface, NULL);

            //Update the surface
            SDL_UpdateWindowSurface(gWindow);

            //Wait two seconds
            SDL_Delay(5000);
        }
    }

    //Free resources and close SDL
    close_window();

    return 0;
}
