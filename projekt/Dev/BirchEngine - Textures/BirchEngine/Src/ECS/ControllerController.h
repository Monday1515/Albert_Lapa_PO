#pragma once

#include "../Game.h"
#include "ECS.h"
#include "Components.h"

class ControllerController : public Component {
private:
	SDL_GameController* controller = nullptr;
public:
	TransformComponent* transform;
	SpriteComponent* sprite;

	void initController() {
		if (SDL_NumJoysticks() > 0) {
			for (int i = 0; i < SDL_NumJoysticks(); ++i) {
				if (SDL_IsGameController(i)) {
					controller = SDL_GameControllerOpen(i);
					if (controller) {
						std::cout << "Kontroller podłączony:  " << SDL_GameControllerName(controller) << std::endl;
						break;
					}
					else {
						std::cout << "Nie udało się odtworzyć kontrolera." << std::endl;
					}
				}
			}
		}
	}

	void init() override {
		transform = &entity->getComponent<TransformComponent>();
		sprite = &entity->getComponent<SpriteComponent>();
	}

	void update() override {
		if (Game::event.type == SDL_CONTROLLERAXISMOTION) {
            if (controller) {
                Sint16 axisX = SDL_GameControllerGetAxis(controller, SDL_CONTROLLER_AXIS_LEFTX);
                Sint16 axisY = SDL_GameControllerGetAxis(controller, SDL_CONTROLLER_AXIS_LEFTY);

                // Normalizacja danych wejściowych z gałki (zakres od -32768 do 32767)
                const float DEADZONE = 8000; // Martwa strefa, aby wyeliminować dryf
                float normalizedX = 0;
                float normalizedY = 0;

                if (axisX > DEADZONE || axisX < -DEADZONE) {
                    normalizedX = axisX / 32768.0f; // Przeskalowanie do zakresu od -1 do 1
                }
                if (axisY > DEADZONE || axisY < -DEADZONE) {
                    normalizedY = axisY / 32768.0f;
                }

                // Aktualizacja prędkości na podstawie gałki
                transform->velocity.x = normalizedX;
                transform->velocity.y = normalizedY;

                // Wybór odpowiedniej animacji
                if (normalizedX != 0 || normalizedY != 0) {
                    sprite->Play("Melee");

                    // Obrót na podstawie kierunku poruszania
                    if (normalizedX < 0) {
                        sprite->spriteFlip = SDL_FLIP_HORIZONTAL;
                    }
                    else {
                        sprite->spriteFlip = SDL_FLIP_NONE;
                    }
                }
                else {
                    sprite->Play("Idle");
                }
            }
        }

        if (Game::event.type == SDL_CONTROLLERBUTTONDOWN) {
            if (Game::event.cbutton.button == SDL_CONTROLLER_BUTTON_BACK) {
                Game::isRunning = false; // Wyłącz grę przyciskiem BACK
            }
        }
    }

    ~ControllerController() {
        if (controller) {
            SDL_GameControllerClose(controller);
        }
    }
};