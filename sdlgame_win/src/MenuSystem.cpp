#include "MenuSystem.h"

#include <cassert>
#include "kiss_sdl.h"
#include "Game.h"

MenuSystem::MenuSystem(int windowWidth, int windowHeight, SDL_Window* window, SDL_Renderer* renderer)
	: window(window), renderer(renderer) {
	initPauseMenu(windowWidth, windowHeight);
}

void MenuSystem::initPauseMenu(int windowWidth, int windowHeight) {
	const auto padding = 20;
	auto r = kiss_init("", &arr, windowWidth, windowHeight, window, renderer);
	assert(r);
	kiss_window_new(&pauseWindow, nullptr, 1, padding, padding, windowWidth - (padding * 2),
		windowHeight - (padding * 2));
	pauseWindow.visible = true;
	auto labelX = pauseWindow.rect.w / 2;
	auto labelY = pauseWindow.rect.h / 2;
	kiss_label_new(&debugLabel, &pauseWindow, "Debug:", labelX, labelY);
	auto selectButtonX = labelX + debugLabel.rect.w;
	kiss_selectbutton_new(&debugCheckbox, &pauseWindow, selectButtonX, labelY);
	auto exitX = labelX;
	auto exitY = pauseWindow.rect.h * 3 / 4;
	kiss_button_new(&exitButton, &pauseWindow, "Exit", exitX, exitY);
}

void MenuSystem::handleEvents(SDL_Event* event) {
	if (Game::isPaused) {
		handlePauseEvents(event);
	}
}

void MenuSystem::handlePauseEvents(SDL_Event* event) {
	kiss_window_event(&pauseWindow, event, &d);
	if (kiss_selectbutton_event(&debugCheckbox, event, &d)) {
		Game::debug = debugCheckbox.selected;
	}
	if (kiss_button_event(&exitButton, event, &d)) {
		Game::isRunning = false;
	}
}

void MenuSystem::draw() {
	if (Game::isPaused) {
		drawPauseWindow();
	}
}

void MenuSystem::drawPauseWindow() {
	kiss_window_draw(&pauseWindow, Game::renderer);
	kiss_selectbutton_draw(&debugCheckbox, Game::renderer);
	kiss_label_draw(&debugLabel, Game::renderer);
	kiss_button_draw(&exitButton, Game::renderer);
}