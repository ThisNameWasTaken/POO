#include "Dog.h"
#include "Controller.h"

Texture Dog::texture("Textures/dog.txt");

Dog::Dog(const Vector2D& position, const string& tagName) : Agent(position) {

}

Dog::Dog(Controller* controller, const Vector2D& position, const string& tagName) : Agent(Sprite(&texture), controller, position, tagName) {

}

Dog::~Dog() {

}

void Dog::beginPlay() {
	Super::beginPlay();

	this->maxHP = 125;
	this->maxArmor = 125;
	this->setHP(125);
	this->setArmor(100);
	this->setAD(55);
}

void Dog::update() {
	Super::update();
}
