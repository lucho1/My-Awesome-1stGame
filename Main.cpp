#include "SDL/include/SDL.h"  
#pragma comment(lib, "SDL/libx86/SDL2.lib") 
#pragma comment(lib, "SDL/libx86/SDL2main.lib") 

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
	bullet.w = 50;
	
	bool quit = false;
	bool UP = false;
	bool DOWN = false;
	bool LEFT = false;
	bool RIGHT = false;
	bool SHOOT = false;

	while (!quit){

		SDL_Event e;
		while (SDL_PollEvent(&e)) {

			if (e.type == SDL_KEYDOWN) {

				switch (e.key.keysym.scancode) {

				case SDL_SCANCODE_LEFT:
					//rect.x -= 5;
					LEFT = true;
					break;
				case SDL_SCANCODE_RIGHT:
					//rect.x += 5;
					RIGHT = true;
					break;
				case SDL_SCANCODE_UP:
					//rect.y -= 5;
					UP = true;
					break;
				case SDL_SCANCODE_DOWN:
					//rect.y += 5;
					DOWN = true;
					break;

				/*case SDL_SCANCODE_SPACE:
					bullet.x = rect.x + 10;
					bullet.y = rect.y - 10;
					SHOOT = true;
					break;
					/*while (bullet.x < 600) { 
						
						bullet.x++;
						SDL_SetRenderDrawColor(renderer, 0, 255, 0, 255);
						SDL_RenderFillRect(renderer, &bullet);
						SDL_RenderPresent(renderer);
					
					}
					break;*/
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

				/*case SDL_SCANCODE_SPACE:
					SHOOT = false;
					break;*/
				}
			}

			else if (e.type == SDL_QUIT || e.type == SDL_SCANCODE_ESCAPE) {

				quit = true;
			}
		}

		if (UP) { rect.y -= 0.1; }
		if (DOWN) { rect.y += 0.1; }
		if (LEFT) { rect.x -= 0.1; }
		if (RIGHT) { rect.x += 0.1; }
		
		/*if (SHOOT) {

			while (bullet.x < 600) {

				bullet.x++;
			}
		}*/

		SDL_SetRenderDrawColor(renderer, 0, 0, 255, 255);
		SDL_RenderClear(renderer);
		//SDL_SetRenderDrawColor(renderer, 0, 255, 0, 255);
		//SDL_RenderFillRect(renderer, &bullet);
		SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);
		SDL_RenderFillRect(renderer, &rect);
		SDL_RenderPresent(renderer);

	}
	
/*	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);
	SDL_Quit();*/
	return 0;
}