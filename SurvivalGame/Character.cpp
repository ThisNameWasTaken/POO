#include "Character.h"

Character::Character() {

}

Character::Character(Sprite sprite) : Actor(sprite) {}

Character::~Character() {
	
}

void Character::beginPlay() {

}

void Character::update() {
	this->setPosition(this->getPosition().x + 1);
}