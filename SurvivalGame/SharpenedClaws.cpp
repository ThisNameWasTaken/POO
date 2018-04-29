#include "SharpenedClaws.h"
#include "Agent.h"

SharpenedClaws::SharpenedClaws(const Vector2D& position) : PickUp(position) {

}

SharpenedClaws::SharpenedClaws(const SharpenedClaws& pickup) : PickUp(pickup) {

}

SharpenedClaws::SharpenedClaws(const Sprite& sprite, const Vector2D& position) : PickUp(sprite, position) {

}

void SharpenedClaws::beginPlay() {
	PickUp::beginPlay();
}

void SharpenedClaws::update() {
	PickUp::update();
}

void SharpenedClaws::buff(Agent* agent) {
	agent->setAD(agent->getAD() + 50);
}