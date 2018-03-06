#include "SDL/include/SDL.h"
//#include "SDL_Image/Include/SDL_image.h"
#pragma comment(lib, "SDL/libx86/SDL2.lib") 
#pragma comment(lib, "SDL/libx86/SDL2main.lib")
//#pragma comment(lib, "SDL_Image/libx86/SDL2_image.lib")


int main(int argc, char* argv[]) {       

	SDL_Init(SDL_INIT_VIDEO); 
	SDL_Window *window = SDL_CreateWindow("MyAwesomeGame", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 600, 400, SDL_WINDOW_SHOWN);
	SDL_Renderer *renderer = SDL_CreateRenderer(window, -1, 0);

	SDL_Rect rect;
	rect.x = 240;
	rect.y = 150;
	rect.h = 100;
	rect.w = 120;

	SDL_Rect bullet;
	bullet.h = 5;
	bullet.w = 20;
	
	bool quit = false, UP = false, DOWN = false, LEFT = false, RIGHT = false, SHOOT = false;

	while (!quit) {

		SDL_Event e;
		while (SDL_PollEvent(&e)) {

			if (e.type == SDL_KEYDOWN) {

				switch (e.key.keysym.scancode) {

				case SDL_SCANCODE_LEFT:
					LEFT = true;
					break;
				case SDL_SCANCODE_RIGHT:
					RIGHT = true;
					break;
				case SDL_SCANCODE_UP:
					UP = true;
					break;
				case SDL_SCANCODE_DOWN:
					DOWN = true;
					break;

				case SDL_SCANCODE_SPACE:
					SHOOT = true;
					break;
				}
			}

			if (e.type == SDL_KEYUP) {

				switch (e.key.keysym.scancode) {

				case SDL_SCANCODE_LEFT:
					LEFT = false;
					break;
				case SDL_SCANCODE_RIGHT:
					RIGHT = false;
					break;
				case SDL_SCANCODE_UP:
					UP = false;
					break;
				case SDL_SCANCODE_DOWN:;
					DOWN = false;
					break;

				case SDL_SCANCODE_SPACE:
					SHOOT = false;
					break;
				}
			}

			if (e.type == SDL_QUIT || e.type == SDL_SCANCODE_ESCAPE) {

				quit = true;
			}
		}

		if (UP == true) { rect.y -= 0.5; }
		if (DOWN == true) { rect.y += 0.5; }
		if (LEFT == true) { rect.x -= 0.5; }
		if (RIGHT == true) { rect.x += 0.5; }

		if (SHOOT == true) {

			bullet.x = rect.x;
			bullet.y = rect.y -2;
			while (bullet.x < 600) {

				SDL_SetRenderDrawColor(renderer, 0, 255, 0, 255);
				SDL_RenderFillRect(renderer, &bullet);
				SDL_RenderPresent(renderer);
				bullet.x++;
			}
		}

		SDL_SetRenderDrawColor(renderer, 0, 0, 255, 255);
		SDL_RenderClear(renderer);
		SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);
		SDL_RenderFillRect(renderer, &rect);
		SDL_RenderPresent(renderer);

	}
	
	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);
	SDL_Quit();
	return 0;
}