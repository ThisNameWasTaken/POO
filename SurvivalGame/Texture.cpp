#include <fstream>
#include <iostream>
#include <Windows.h>
#include "Texture.h"
#include "Console.h"

Texture::Texture(string fileName) {
	this->width = 0;
	this->height = 0;

	if (fileName.length()) {
		this->loadFromFile(fileName);
	}
}

Texture::~Texture() {
	this->width = 0;
	this->height = 0;
	this->texture.clear();
}

bool Texture::loadFromFile(string fileName) {
	ifstream fin(fileName);

	if (!fin.is_open()) {
		cout << "Could not open file at " << fileName << endl;
		return false;
	}

	this->width = 0;
	this->height = 0;
	string line;
	while (getline(fin, line)) {
		this->texture.push_back(line);
		if (this->width < line.length()) {
			this->width = line.length();
		}
		this->height++;
	}

	fin.close();
	return true;
}

ostream& operator<< (ostream& out, const Texture& texture) {
	static COORD cursorPos;
	cursorPos = Console::getCursorPosition();

	for (const string line : texture.getTexture()) {
		out << line;
		cursorPos.Y++;
		Console::setCursorPosition(cursorPos);
	}

	cursorPos.X += texture.getWidth();
	cursorPos.Y -= texture.getHeight();
	Console::setCursorPosition(cursorPos);

	return out;
}