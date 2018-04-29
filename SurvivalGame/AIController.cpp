#include "AIController.h"
#include "Vector2D.h"
#include "Character.h"
#include "Random.h"

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

	switch (random(8)) {
	case 0:
		// Move upwards
		this->character->move(Vector2D(0, -1));
		break;
	case 1:
		// Move to the left
		this->character->move(Vector2D(-1, 0));
		break;
	case 2:
		// Move downwards
		this->character->move(Vector2D(0, 1));
		break;
	case 3:
		// Move to the right
		this->character->move(Vector2D(1, 0));
		break;
	case 4:
		// Move to the top-left
		this->character->move(Vector2D(-1, -1));
		break;
	case 5:
		// Move to the bottom-left
		this->character->move(Vector2D(-1, 1));
		break;
	case 6:
		// Move to the bottom-right
		this->character->move(Vector2D(1, 1));
		break;
	case 7:
		// Move to the top-right
		this->character->move(Vector2D(1, -1));
		break;
	default:
		// Idle
		break;
	}
}