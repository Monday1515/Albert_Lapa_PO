#pragma once

#include "ECS.h"
#include "TransformComponent.h"
#include "SDL.h"
#include "SDL_image.h"
#include <string>
#include <iostream>

class TileComponent : public Component {
public:
	SDL_Texture* texture;
	SDL_Rect srcRect, destRect;
	Vector2D position;

	TileComponent() = default;

	~TileComponent() {}

	TileComponent(int srcX, int srcY, int xpos, int ypos, int tsize, int tscale, const char* path) {
		static SDL_Texture *textureMap = TextureManager::LoadTexture(path);
		texture = textureMap;

		position.x = xpos;
		position.y = ypos;
	
		srcRect.x = srcX;
		srcRect.y = srcY;
		srcRect.w = srcRect.h = tsize;
	
		destRect.x = xpos;
		destRect.y = ypos;
		destRect.w = destRect.h = tsize * tscale;
	}

	void update() override {
		destRect.x = position.x - Game::camera.x;
		destRect.y = position.y - Game::camera.y;
	}

	void draw() override {
		TextureManager::Draw(texture, srcRect, destRect, SDL_FLIP_NONE);
	}
};