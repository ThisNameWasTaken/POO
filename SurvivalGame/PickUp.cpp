#include "PickUp.h"
#include "Random.h"
#include "Scene.h"

PickUp::PickUp(const Vector2D& position) : Actor(position){

}

PickUp::PickUp(const PickUp& pickup) : Actor(pickup) {

}

PickUp::PickUp(const Sprite& sprite, const Vector2D& position) : Actor(sprite, position) {

}

void PickUp::beginPlay() {
	const Scene* scene = Scene::getActiveScene();
	if (scene) {
		this->setPosition(Vector2D(random(scene->getHeight()), random(scene->getWidth())));
	}

	this->shouldUpdate = false;
}

void PickUp::update() {

}