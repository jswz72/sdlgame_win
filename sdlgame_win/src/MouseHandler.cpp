#include "MouseHandler.h"

MouseButtonHandler::MouseButtonHandler() {
	for (uint8_t i = 0; i < std::numeric_limits<uint8_t>::max(); i++) {
		buttonState[i] = new MouseButtonData{};
	}
}

void MouseButtonHandler::handleMouseButtonEvent(SDL_MouseButtonEvent event) {
	uint8_t button = event.button;
	Vector2D position = { static_cast<float>(event.x), static_cast<float>(event.y) };
	buttonState[button]->pos = position;
	if (event.type == SDL_MOUSEBUTTONUP) {
		buttonState[button]->state = MouseButtonData::RELEASED;
	}
	else if (event.type == SDL_MOUSEBUTTONDOWN) {
		buttonState[button]->state = MouseButtonData::PRESSED;
	}
}

MouseButtonData* MouseButtonHandler::mouseButtonData(uint8_t button) {
	return buttonState[button];
}