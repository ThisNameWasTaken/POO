#include "Sprite.h"
#include "Texture.h"

Sprite::Sprite(Texture* texture) {
	this->texture = texture;
	if(this->texture) {
		this->width = texture->getWidth();
		this->height = texture->getHeight();
	} else {
		this->width = 0; 
		this->height = 0;
	}
}

Sprite::Sprite(const Sprite& sprite) : texture(sprite.getTexture()) {

}

Sprite::~Sprite() {
	this->texture = nullptr;
	this->width = 0;
	this->height = 0;
}

ostream& operator<<(ostream& out, const Sprite& sprite) {
	if(sprite.texture) {
		out << *sprite.texture;
	} else {
		out << "No texture!\n";
	}
	return out;
}
