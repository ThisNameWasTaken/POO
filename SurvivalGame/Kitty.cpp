#include "Kitty.h"
#include "Controller.h"

Texture Kitty::texture("Textures/kitty.txt");

Kitty::Kitty(const Vector2D& position, const string& tagName) : Agent(position) {

}

Kitty::Kitty(Controller* controller, const Vector2D& position, const string& tagName) : Agent(Sprite(&texture), controller, position, tagName) {

}

Kitty::~Kitty() {

}

void Kitty::beginPlay() {
	Super::beginPlay();

	this->maxHP = 5000;
	this->maxArmor = 50;
	this->setHP(5000);
	this->setArmor(0);
	this->setAD(1550);
}

void Kitty::update() {
	Super::update();
}
