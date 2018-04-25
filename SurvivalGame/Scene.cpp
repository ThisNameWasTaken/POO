#include <iostream>
#include <windows.h>
#include "Scene.h"
#include "Actor.h"
#include <string>

HANDLE Scene::consoleHandle;
CONSOLE_SCREEN_BUFFER_INFO Scene::consoleInfo;

Scene::Scene() {

}

Scene::Scene(const int width, const int height, const Sprite& tile, const std::set<class Actor*> actors) {
	this->width = width;
	this->height = height;
	this->actors = actors;
	this->tile = tile;
	this->isFirstPaint = true;
}

Scene::~Scene() {

}

void Scene::render() {
	for (Actor* actor : this->actors) {
		actor->update();
	}

	if (this->isFirstPaint) {
		this->renderFirstPaint();
		this->isFirstPaint = false;
	}

	static COORD cursorPosition;

	for (const Actor* actor : this->actors) {
		if (!actor) {
			continue;
		}

		cursorPosition.X = actor->getPosition().x * this->tile.getWidth();
		cursorPosition.Y = actor->getPosition().y * this->tile.getHeight();
		SetConsoleCursorPosition(consoleHandle, cursorPosition);
		cout << actor->getSprite();
	}

	cursorPosition.X = 0;
	cursorPosition.Y = this->height * this->tile.getHeight();
	SetConsoleCursorPosition(consoleHandle, cursorPosition);
}

void Scene::renderFirstPaint() const {
	consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
	GetConsoleScreenBufferInfo(consoleHandle, &consoleInfo);
	static COORD& cursorPosition = consoleInfo.dwCursorPosition;

	for (int i = 0; i < this->height; i++) {
		for (int j = 0; j < this->width; j++) {
			cout << this->tile;
		}

		cursorPosition.Y = (i + 1) * this->tile.getHeight();
		cursorPosition.X = 0;
		SetConsoleCursorPosition(consoleHandle, cursorPosition);
	}
}

