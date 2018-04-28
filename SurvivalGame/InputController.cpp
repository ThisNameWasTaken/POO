#include "InputController.h"
#include "Vector2D.h"
#include "Character.h"
#include <windows.h>
#include "Keyboard.h"

InputController::InputController() {

}

InputController::~InputController() {

}

void InputController::onBeginPlay() {
	if (!this->character) {
		return;
	}
}

void InputController::onUpdate() {
	if (!this->character) {
		return;
	}

	if (GetAsyncKeyState(Keyboard::W)) {
		// Move upwards
		this->character->move(Vector2D(0, -1));
	}

	if (GetAsyncKeyState(Keyboard::A)) {
		// Move to the left
		this->character->move(Vector2D(-1, 0));
	}

	if (GetAsyncKeyState(Keyboard::S)) {
		// Move downwards
		this->character->move(Vector2D(0, 1));
	}

	if (GetAsyncKeyState(Keyboard::D)) {
		// Move to the right
		this->character->move(Vector2D(1, 0));
	}
}