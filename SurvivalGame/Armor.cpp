#include "Armor.h"
#include "Agent.h"
#include <limits.h>

Armor::Armor(const Vector2D& position) : PickUp(position) {

}

Armor::Armor(const Armor& pickup) : PickUp(pickup) {

}

Armor::Armor(const Sprite& sprite, const Vector2D& position) : PickUp(sprite, position) {

}

void Armor::beginPlay() {
	PickUp::beginPlay();
}

void Armor::update() {
	PickUp::update();
}

void Armor::buff(Agent* agent) {
	agent->setArmor(INT_MAX);
}