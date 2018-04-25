#pragma once

#include <iostream>

using namespace std;

class Sprite {
public:
	Sprite(class Texture* texture = nullptr);
	Sprite(const Sprite& sprite);
	~Sprite();

	inline void setTexture(class Texture* texture) { this->texture = texture; }
	inline class Texture* getTexture() const { return this->texture; }

	friend ostream& operator<< (ostream& out, const Sprite& sprite);

	inline const int getWidth() const { return this->width; }
	inline const int getHeight() const { return this->height; }

private:
	class Texture* texture;
	int width;
	int height;
};

