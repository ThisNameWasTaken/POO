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

	const Actor* closestActor = nullptr;
	// The closest position between the controlled Character and another Actor
	Vector2D closestDeltaPosition(INT_MAX, INT_MAX);
	Vector2D deltaPosition; 

	const set<Actor*> actors = this->character->getWorldActors();
	for (const Actor* actor : actors) {
		if (!actor) {
			continue;
		}

		// The Actor should not be the controlled Character
		if (actor == this->character) {
			continue;
		}

		// Check if this Actor is closers
		deltaPosition = this->character->getPosition() - actor->getPosition();
		deltaPosition.x = abs(deltaPosition.x);
		deltaPosition.y = abs(deltaPosition.y);
		if (deltaPosition.x < closestDeltaPosition.x && deltaPosition.y < closestDeltaPosition.y) {
			closestActor = actor;
			closestDeltaPosition = deltaPosition;
		}
	}

	if (closestActor) {
		chase(closestActor);
	}
}

void AIController::chase(const Actor* actor) {
	const Vector2D& actorPosition = actor->getPosition();
	Vector2D newPosition = character->getPosition();
	
	if (newPosition.x < actorPosition.x) { // If the chased Actor is on the right side
		// Go to the right
		newPosition.x++;
	} else if (newPosition.x > actorPosition.x) { // If the chased Actor is on the left side
		// Go to the left
		newPosition.x--;
	}

	if (newPosition.y < actorPosition.y) { // If the chased Actor is on the top side
		// Go higher
		newPosition.y++;
	} else if (newPosition.y > actorPosition.y) { // If the chased Actor is on the bottom side
		// Go lower
		newPosition.y--;
	}

	this->character->setPosition(newPosition);
}
