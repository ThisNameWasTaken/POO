#include "SharpenedClaws.h"
#include "Agent.h"

Texture SharpenedClaws::texture("Textures/SharpenedClaws.txt");

SharpenedClaws::SharpenedClaws(const Vector2D& position) : PickUp(Sprite(&texture), position) {

}

SharpenedClaws::SharpenedClaws(const SharpenedClaws& pickup) : PickUp(pickup) {

}

void SharpenedClaws::beginPlay() {
	PickUp::beginPlay();
}

void SharpenedClaws::update() {
	PickUp::update();
}

void SharpenedClaws::buff(Agent* agent) {
	agent->setAD(agent->getAD() + 50);
	this->Destroy();
}