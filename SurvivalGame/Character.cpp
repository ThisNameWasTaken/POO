#include "Character.h"
#include "Controller.h"

Character::Character(const Vector2D& Position) : Actor(Position) {

}

Character::Character(const Character& character) : Actor(character) {
	this->controller = character.getController();
}

Character::Character(const Sprite& sprite, Controller* controller, const Vector2D& Position) : Actor(sprite, position) {
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
