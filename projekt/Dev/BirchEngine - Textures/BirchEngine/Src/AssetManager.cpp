#include "AssetManager.h"
#include "ECS/Components.h"

AssetManager::AssetManager(Manager* man) : manager(man) {

}

AssetManager::~AssetManager() {

}

//void CreateProjectile(Vector2D pos, int range, int speed, std::string) {
//	auto& projectile(manager.addEntity());
//	projectile.addComponent<TransformComponent>(pos.x, pos.y, 32, 32, 1);
//	projectile.addComponent<SpriteComponent>("proj_test", false);
//	projectile.addComponent<ProjectileComponent>(range, speed);
//	projectile.addComponent<ColliderComponent>("projectile");
//	projectile.addGroup(Game::groupProjectiles);
//}

void AssetManager::AddTexture(std::string id, const char* path) {
	textures.emplace(id, TextureManager::LoadTexture(path));
}

SDL_Texture* AssetManager::GetTexture(std::string id) {
	return textures[id];
}