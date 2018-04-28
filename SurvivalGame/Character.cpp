#include "Character.h"
#include "Controller.h"

Character::Character() {

}

Character::Character(const Character& character) {
	this->controller = character.getController();
}

Character::Character(Sprite sprite, Controller* controller) : Actor(sprite) {
	this->setController(controller);
}

Character::~Character() {

}

const Character& Character::operator=(const Character& character) {
	this->controller = character.getController();
	return *this;
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

void Character::setController(Controller* controller) {
	if (!controller) return; 
	this->controller = controller;
	this->controller->attachTo(this);
}
