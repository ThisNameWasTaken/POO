#include "Ghost.h"
#include "Controller.h"

Texture Ghost::texture("Textures/ghost.txt");

Ghost::Ghost(const Vector2D& position, const string& tagName) : Agent(position) {

}

Ghost::Ghost(Controller* controller, const Vector2D& position, const string& tagName) : Agent(Sprite(&texture), controller, position, tagName) {

}

Ghost::~Ghost() {

}

void Ghost::beginPlay() {
	Agent::beginPlay();

	this->maxHP = 100;
	this->maxArmor = 100;
	this->setHP(100);
	this->setArmor(0);
	this->setAD(35);
}

void Ghost::update() {
	Agent::update();
}
