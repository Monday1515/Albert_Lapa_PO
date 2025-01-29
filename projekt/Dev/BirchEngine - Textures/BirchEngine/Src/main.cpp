#include "Game.h"

Game *game = nullptr;

int main(int argc, char *argv[])
{
	const int FPS = 60;
	const int FrameDelay = 1000 / FPS;

	Uint32 FrameStart;
	int FrameTime;

	game = new Game();
	game->init("GameWindow", 800, 640, false);

	while (game->running())
	{
		
		FrameStart = SDL_GetTicks();

		game->handleEvents();
		game->update();
		game->render();

		FrameTime = SDL_GetTicks() - FrameStart;

		if (FrameDelay > FrameTime) {
			SDL_Delay(FrameDelay - FrameTime);
		}
	}

	game->clean();
	return 0;
}