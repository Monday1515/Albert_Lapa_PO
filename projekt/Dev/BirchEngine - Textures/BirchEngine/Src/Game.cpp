#include "Game.h"
#include "SDL_image.h"
#include "TextureManager.h"
#include "Map.h"
#include "ECS/Components.h"
#include "Vector2D.h"
#include "Collision.h"

Map* map;

SDL_Renderer* Game::renderer = nullptr;
SDL_Event Game::event;

SDL_Rect Game::camera = { 0, 0, 800, 640 };

bool Game::isRunning = false;

Manager manager;
auto& player(manager.addEntity());
auto& projectile(manager.addEntity());
//auto& wall(manager.addEntity());

Game::Game()
{}

Game::~Game()
{}

void Game::init(const char* title, int width, int height, bool fullscreen)
{
	int flags = 0;
	
	if (fullscreen)
	{
		flags = SDL_WINDOW_FULLSCREEN;
	}

	if (SDL_Init(SDL_INIT_EVERYTHING) == 0)
	{
		window = SDL_CreateWindow(title, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, width, height, flags);
		renderer = SDL_CreateRenderer(window, -1, 0);
		if (renderer)
		{
			SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
		}

		isRunning = true;
	}

	map = new Map("assets//terrain_textures.png", 4, 32);

	map->LoadMap("assets//map1.map", 16, 16);

	player.addComponent<TransformComponent>(2);
	player.addComponent<SpriteComponent>("assets//character_animation.png", true);
	player.addComponent<KeyboardController>();
	player.addComponent<ColliderComponent>("player");
	player.addGroup(groupPlayers);

	projectile.addComponent<TransformComponent>(0, 300, 32, 32, 4);
	projectile.addComponent<SpriteComponent>("assets//bullet_anim.png", true);
	projectile.addComponent<ProjectileComponent>(200, 2, Vector2D(2,0));
	projectile.addComponent<ColliderComponent>("projectile");
	projectile.addGroup(Game::groupProjectiles);

	//wall.addComponent<TransformComponent>(300.0f, 300.0f, 300, 20, 1);
	//wall.addComponent<SpriteComponent>("assets/dirt.png");
	//wall.addComponent<ColliderComponent>("wall");
	//wall.addGroup(groupMap);

}

auto& tiles(manager.getGroup(Game::groupMap));
auto& players(manager.getGroup(Game::groupPlayers));
auto& enemies(manager.getGroup(Game::groupEnemies));
auto& colliders(manager.getGroup(Game::groupColliders));
auto& projectiles(manager.getGroup(Game::groupProjectiles));

void Game::handleEvents()
{
	SDL_PollEvent(&event);

	switch (event.type)
	{
	case SDL_QUIT :
		isRunning = false;
		break;
	default:
		break;
	}
}

void Game::update()
{

	SDL_Rect playerCol = player.getComponent<ColliderComponent>().collider;
	Vector2D playerPos = player.getComponent<TransformComponent>().position;

	cnt++;
	manager.refresh();
	manager.update();

	for (auto& c : colliders) {
		SDL_Rect cCol = c->getComponent<ColliderComponent>().collider;
		if (Collision::AABB(cCol, playerCol)) {
			std::cout << "Collision detected: World Border" << std::endl;
			player.getComponent<TransformComponent>().position = playerPos;
		}
	}

	for (auto& p : projectiles) {
		if (Collision::AABB(player.getComponent<ColliderComponent>().collider, p->getComponent<ColliderComponent>().collider)) {
			std::cout << "Collision detected: Projectile" << std::endl;
			p->destroy();
		}
	}

	//-half the size of display
	camera.x = player.getComponent<TransformComponent>().position.x - 400;
	camera.y = player.getComponent<TransformComponent>().position.y - 320;

	if (camera.x < 0) {
		camera.x = 0;
	}
	if (camera.y < 0) {
		camera.y = 0;
	}
	if (camera.x > camera.w) {
		camera.x = camera.w;
	}
	if (camera.y > camera.h) {
		camera.y = camera.h;
	}

	//Vector2D pVel = player.getComponent<TransformComponent>().velocity;
	//int pSpeed = player.getComponent<TransformComponent>().speed;

	//for (auto t : tiles) {
	//	t->getComponent<TileComponent>().destRect.x += -(pVel.x * pSpeed);
	//	t->getComponent<TileComponent>().destRect.y += -(pVel.y * pSpeed);
	//}

	/*for (auto cc : colliders) {
		Collision::AABB(player.getComponent<ColliderComponent>(), *cc);
	}*/

	//std::cout << cnt << std::endl;
}

void Game::render()
{
	SDL_RenderClear(renderer);
	for (auto& t : tiles) {
		t->draw();
	}
	for (auto& c : colliders) {
		c->draw();
	}
	for (auto& p : players) {
		p->draw();
	}
	for (auto& e : enemies) {
		e->draw();
	}
	for (auto& p : projectiles) {
		p->draw();
	}
	SDL_RenderPresent(renderer);
}

void Game::clean()
{
	SDL_DestroyWindow(window);
	SDL_DestroyRenderer(renderer);
	SDL_Quit();
}