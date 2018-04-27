#include "InputController.h"
#include "Character.h"
#include "Vector2D.h"

InputController::InputController() {

}

InputController::~InputController() {

}

void InputController::onBeginPlay() {

}

void InputController::onUpdate() {
	if (!this->character) {
		return;
	}
	this->character->move(Vector2D(1, 1));
}