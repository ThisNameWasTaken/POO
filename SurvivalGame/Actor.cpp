#include "Actor.h"
#include "Scene.h"

set<Actor*> Actor::worldActors;

Actor::Actor(const Vector2D& position) {
	this->setPosition(position);
	worldActors.insert(this);
	this->shouldUpdate = true;
}

Actor::Actor(const Actor& actor) : Actor(sprite) {
	this->setPosition(actor.getPosition());
}

Actor::Actor(const Sprite& sprite, const Vector2D& position) : Actor(position) {
	this->setSprite(sprite);
}

Actor::~Actor() {
	this->shouldUpdate = false;
	worldActors.erase(this);
}

const Actor& Actor::operator=(const Actor& actor) {
	this->setPosition(actor.getPosition());
	this->setSprite(actor.getSprite());
	
	return *this;
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
		if (actor->getPosition() == this->position && actor != this) {
			overlappingActors.insert(actor);
		}
	}

	return overlappingActors;
}

void Actor::Destroy() {
	this->~Actor();
}
