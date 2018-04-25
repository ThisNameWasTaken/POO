#pragma once

#include <string>
#include <vector>

using namespace std;

class Texture {
public:
	Texture(string fileName = "");
	~Texture();

	bool loadFromFile(string fileName);
	inline const vector<string> getTexture() const { return this->texture; }

	friend ostream& operator<< (ostream& out, const Texture& texture);

	inline const int getWidth() const { return this->width; }
	inline const int getHeight() const { return this->height; }

private:
	vector<string> texture;
	int width;
	int height;
};