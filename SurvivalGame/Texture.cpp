#include "Texture.h"
#include <fstream>
#include <iostream>
#include <Windows.h>

Texture::Texture(string fileName) {
	this->width = 0;
	this->height = 0;
	if(fileName.length())
		this->loadFromFile(fileName);
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
	static HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
	static CONSOLE_SCREEN_BUFFER_INFO consoleInfo;
	GetConsoleScreenBufferInfo(consoleHandle, &consoleInfo);
	static COORD& cursorPos = consoleInfo.dwCursorPosition;

	for (const string line : texture.getTexture()) {
		out << line;
		cursorPos.Y++;
		SetConsoleCursorPosition(consoleHandle, cursorPos);
	}

	cursorPos.X += texture.getWidth();
	cursorPos.Y -= texture.getHeight();
	SetConsoleCursorPosition(consoleHandle, cursorPos);

	return out;
}