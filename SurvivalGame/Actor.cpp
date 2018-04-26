#include "Actor.h"
#include "Scene.h"

set<Actor*> Actor::worldActors;

Actor::Actor() {
	this->setPosition(Vector2D(0, 0));
	worldActors.insert(this);
}

Actor::Actor(Sprite sprite) {
	this->setPosition(Vector2D(0, 0));
	this->setSprite(sprite);
	worldActors.insert(this);
}

Actor::~Actor() {
	worldActors.erase(this);
}

void Actor::setPosition(const Vector2D& position) {
	const Scene* activeScene = Scene::getActiveScene();

	// If there is no active scene then leave the Actor where it is.
	if (!activeScene) {
		return;
	}

	// If it is outside of the scene's bounds then leave the Actor where it is.
	if (position.x < 0 || position.y < 0 || 
		position.x >= activeScene->getWidth() || position.y >= activeScene->getHeight()) {
		return;
	}

	this->position = position;
}

set<Actor*> Actor::getActorsInRange(int range) const {
	set<Actor*> actorsInRange;

	Vector2D actorPosition;
	for (Actor* actor : worldActors) {
		actorPosition = actor->getPosition();
		if (actorPosition.x <= range && actorPosition.y <= range) {
			actorsInRange.insert(actor);
		}
	}

	return actorsInRange;
}

set<Actor*> Actor::getOverlappingActors() const {
	set<Actor*> overlappingActors;

	for (Actor* actor : worldActors) {
		if (actor->getPosition() == this->position) {
			overlappingActors.insert(actor);
		}
	}

	return overlappingActors;
}
