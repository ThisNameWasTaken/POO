#include "InputController.h"
#include "Vector2D.h"
#include "Character.h"

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
	
}