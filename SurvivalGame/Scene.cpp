#include <iostream>
#include <windows.h>
#include <string>
#include "Scene.h"
#include "Actor.h"
#include "Console.h"

Scene* Scene::activeScene = nullptr;

Scene::Scene() {
	activeScene = this;
}

Scene::Scene(const int width, const int height, const Sprite& tile, const std::set<class Actor*> actors) : Scene() {
	this->width = width;
	this->height = height;
	this->actors = actors;
	this->tile = tile;
	this->isFirstPaint = true;
}

Scene::~Scene() {

}

void Scene::render() {
	static COORD cursorPosition;

	if (this->isFirstPaint) {
		this->renderFirstPaint();
		this->isFirstPaint = false;
	} else {
		for (Actor* actor : this->actors) {
			if (!actor) {
				continue;
			}

			cursorPosition.X = actor->getPosition().x * this->tile.getWidth();
			cursorPosition.Y = actor->getPosition().y * this->tile.getHeight();
			SetConsoleCursorPosition(Console::getHandle(), cursorPosition);
			cout << this->tile;
			actor->update();
		}
	}

	for (const Actor* actor : this->actors) {
		if (!actor) {
			continue;
		}

		cursorPosition.X = actor->getPosition().x * this->tile.getWidth();
		cursorPosition.Y = actor->getPosition().y * this->tile.getHeight();
		Console::setCursorPosition(cursorPosition);
		cout << actor->getSprite();
	}

	cursorPosition.X = 0;
	cursorPosition.Y = this->height * this->tile.getHeight();
	Console::setCursorPosition(cursorPosition);
}

void Scene::renderFirstPaint() const {
	COORD& cursorPosition = Console::getCursorPosition();

	for (int i = 0; i < this->height; i++) {
		for (int j = 0; j < this->width; j++) {
			cout << this->tile;
		}

		cursorPosition.X = 0;
		cursorPosition.Y = (i + 1) * this->tile.getHeight();
		Console::setCursorPosition(cursorPosition);
	}
}

