#include "SDL/include/SDL.h"   // The"\" slash is only used in windows and is better to use the "/" slash
#pragma comment(lib, "SDL/libx86/SDL2.lib") // This access the preprocessor directive specifically to the Visual S compiler
#pragma comment(lib, "SDL/libx86/SDL2main.lib") //So, finally is to access to the library



/* argc is "argument count" and counts the parameters passed to main. argv is "Arg.
  Vector" and it stores the parameters passed to main. Remember >>prog 5 6.
  It's like you're expecting some input arguments. From OS when starting prog */

int main(int argc, char* argv[]) {       
	
	//SDL_Init calls to initiate a subsystem (video in this case). Is a remark. SDL_INIT_VIDEO is a flag (a subsystem)

	SDL_Init(SDL_INIT_VIDEO); 


	/* Here we create a command to open a window. See that we create a pointer *window, to point the "surface"...
	   Now the syntax is: SDL_CreateWindow(char* titleofscreen, int x, int y [coordinates of screen to create it], int width, int height [of the window],
	   flag [this is to set some properties of the window]) */
	
	SDL_Window *window = SDL_CreateWindow("MyAwesomeGame", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 600, 400, SDL_WINDOW_SHOWN); //If I put MINIMIZED doesn't shows the window!!
	
	/* Here we will create a renderer to draw to the window. We associate with *window because we will draw on that window previously created
	   Syntax: SDL_CreateRenderer([window where to draw], index [of rendering driver to be used, -1 to select the first that meets our requirements],
	   flags [to specify what sort of renderer we want, for example a hardware accelerated renderer]) */

	SDL_Renderer *renderer = SDL_CreateRenderer(window, -1, 0);

	/* To set a color to the screen we use this command where syntax is:
	   (renderer where to draw the color, RedValue, GreenValue, BlueValue, AlfaChannel).
	   Blue is (0, 0, 255, 255) in RGB code.*/

	SDL_SetRenderDrawColor(renderer, 0, 0, 255, 255);

	// So, in order to make the screen appear in blue, we must follow the next:

	SDL_RenderClear(renderer); // Clear the renderer (renderer we want to clear)
	SDL_RenderPresent(renderer); // Update renderer (renderer we want to update)
	//SDL_Delay(5000);              We can put this in order to wait for (some) ms



	/* -------------------------------------------------------------------------------
	       Until here, open a blue window. Now, let's make the game loop               
       -------------------------------------------------------------------------------
          SDL allows us to create events (SDL_Event) to read an input that is            
          placed in a queue waiting to be processed. By making a SDL_PollEvent           
          instruction, we put an event in the 1st place of that queue.               */



	// Let's create a event "e" and a bool to know when we're pressing a key

	SDL_Event e;  
	bool quit = false;

	while (!quit){

		while (SDL_PollEvent(&e)) {

			if (e.type == SDL_KEYDOWN) {

				quit = true;
			}

			SDL_RenderClear(renderer);
			SDL_RenderPresent(renderer);
		}
	}
	
	return 0;
}


//An "int argc, char* argv[]" example: If we open a document, how does Microsoft office knows it? We have passed it through a parameter without knowing it