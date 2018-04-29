#include "Cat.h"
#include "Controller.h"

Texture Cat::texture("Textures/cat.txt");

Cat::Cat(const Vector2D& position, const string& tagName) : Agent(position) {

}

Cat::Cat(Controller* controller, const Vector2D& position, const string& tagName) : Agent(Sprite(&texture), controller, position, tagName) {

}

Cat::~Cat() {

}

void Cat::beginPlay() {
	Super::beginPlay();

	this->maxHP = 75;
	this->maxArmor = 155;
	this->setHP(100);
	this->setArmor(0);
	this->setAD(50);
}

void Cat::update() {
	Super::update();
}
