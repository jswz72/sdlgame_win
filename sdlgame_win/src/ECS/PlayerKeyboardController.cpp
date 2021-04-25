#include "PLayerKeyboardController.h"
#include "Components.h"

void PlayerKeyboardController::update() {
	const auto & kbh = Game::keyboardHandler;
	// RELEASED
	if (kbh.isReleased(SDLK_w)) {
		transform->velocity.y = 0;
		sprite->play("idle");
	}
	if (kbh.isReleased(SDLK_a)) {
		transform->velocity.x = 0;
		sprite->play("idle");
	}
	if (kbh.isReleased(SDLK_s)) {
		transform->velocity.y = 0;
		sprite->play("idle");
	}
	if (kbh.isReleased(SDLK_d)) {
		transform->velocity.x = 0;
		sprite->play("idle");
	}
	if (kbh.isReleased(SDLK_LSHIFT)) {
		transform->resetSpeed();
	}
	// PRESSED
	if (kbh.isPressed(SDLK_w)) {
	transform->velocity.y = -1;
		sprite->play("walk");
	}
	if (Game::keyboardHandler.isPressed(SDLK_a)) {
		transform->velocity.x = -1;
		sprite->spriteFlip = SDL_FLIP_HORIZONTAL;
		sprite->play("walk");
	}
	if (Game::keyboardHandler.isPressed(SDLK_s)) {
		transform->velocity.y = 1;
		sprite->play("walk");
	}
	if (Game::keyboardHandler.isPressed(SDLK_d)) {
		sprite->spriteFlip = SDL_FLIP_NONE;
		transform->velocity.x = 1;
		sprite->play("walk");
	}
	if (kbh.isPressed(SDLK_LSHIFT)) {
		transform->resetSpeed();
		transform->speed *= shiftSpeedMult;
	}
}