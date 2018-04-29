#include "Armor.h"
#include "Agent.h"
#include <limits.h>

Texture Armor::texture("Textures/Armor.txt");

Armor::Armor(const Vector2D& position) : PickUp(Sprite(&texture), position) {

}

Armor::Armor(const Armor& pickup) : PickUp(pickup) {

}

void Armor::beginPlay() {
	PickUp::beginPlay();
}

void Armor::update() {
	PickUp::update();
}

void Armor::buff(Agent* agent) {
	agent->setArmor(INT_MAX);
	this->Destroy();
}