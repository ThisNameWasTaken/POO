#include "HealthPack.h"
#include "Agent.h"
#include <limits.h>

HealthPack::HealthPack(const Vector2D& position) : PickUp(position) {

}

HealthPack::HealthPack(const HealthPack& pickup) : PickUp(pickup) {

}

HealthPack::HealthPack(const Sprite& sprite, const Vector2D& position) : PickUp(sprite, position) {

}

void HealthPack::beginPlay() {
	PickUp::beginPlay();
}

void HealthPack::update() {
	PickUp::update();
}

void HealthPack::buff(Agent* agent) {
	agent->setHP(INT_MAX);
}