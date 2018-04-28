#include "AIController.h"
#include "Vector2D.h"
#include "Character.h"

AIController::AIController() {

}

AIController::~AIController() {

}

void AIController::onBeginPlay() {
	if (!this->character) {
		return;
	}
}

void AIController::onUpdate() {
	if (!this->character) {
		return;
	}

	this->character->move(Vector2D(1, 1));
}