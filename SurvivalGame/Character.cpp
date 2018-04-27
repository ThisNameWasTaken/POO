#include "Character.h"

Character::Character() {

}

Character::Character(Sprite sprite, Controller* controller) : Actor(sprite) {
	this->setController(controller);
}

Character::~Character() {
	
}

void Character::beginPlay() {
	if (this->controller) {
		this->controller->onBeginPlay();
	}
}

void Character::update() {
	if (this->controller) {
		this->controller->onUpdate();
	}
}
