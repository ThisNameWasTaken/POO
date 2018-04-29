#include "Kitty.h"
#include "Controller.h"

Texture Kitty::texture("Textures/kitty.txt");

Kitty::Kitty(const Vector2D& position, const string& tagName) : Agent(position) {

}

Kitty::Kitty(Controller* controller, const Vector2D& position, const string& tagName) : Agent(Sprite(&texture), controller, tagName) {

}

Kitty::~Kitty() {

}

void Kitty::beginPlay() {
	Super::beginPlay();
	this->setPosition(Vector2D(5, 5));
}

void Kitty::update() {
	Super::update();
}
