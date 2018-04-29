#include "HealthPack.h"
#include "Agent.h"
#include <limits.h>

Texture HealthPack::texture("Textures/HealthPack.txt");

HealthPack::HealthPack(const Vector2D& position) : PickUp(Sprite(&texture), position) {

}

HealthPack::HealthPack(const HealthPack& pickup) : PickUp(pickup) {

}

void HealthPack::beginPlay() {
	PickUp::beginPlay();
}

void HealthPack::update() {
	PickUp::update();
}

void HealthPack::buff(Agent* agent) {
	agent->setHP(INT_MAX);
	this->Destroy();
}