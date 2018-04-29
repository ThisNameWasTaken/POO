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
	} else {
		for (Actor* actor : this->actors) {
			if (!actor) {
				continue;
			}

			if (!actor->shouldUpdate) {
				continue;
			}

			// Clear actor's previous appearance on the map
			cursorPosition.X = actor->getPosition().x * this->tile.getWidth();
			cursorPosition.Y = actor->getPosition().y * this->tile.getHeight();
			Console::setCursorPosition(cursorPosition);
			cout << this->tile;

			// Update Actor's position
			actor->update();
		}
	}

	for (const Actor* actor : this->actors) {
		if (!actor) {
			continue;
		}

		if (!actor->shouldUpdate && !this->isFirstPaint) {
			continue;
		}

		// Render actor's current possition
		cursorPosition.X = actor->getPosition().x * this->tile.getWidth();
		cursorPosition.Y = actor->getPosition().y * this->tile.getHeight();
		Console::setCursorPosition(cursorPosition);

		// 
		cout << actor->getSprite();
	}

	// place the cursor at the end
	cursorPosition.X = 0;
	cursorPosition.Y = this->height * this->tile.getHeight();
	Console::setCursorPosition(cursorPosition);

	this->isFirstPaint = false;
}

void Scene::renderFirstPaint() const {
	COORD& cursorPosition = Console::getCursorPosition();

	// Render background
	for (int i = 0; i < this->height; i++) {
		for (int j = 0; j < this->width; j++) {
			cout << this->tile;
		}

		cursorPosition.X = 0;
		cursorPosition.Y = (i + 1) * this->tile.getHeight();
		Console::setCursorPosition(cursorPosition);
	}

	// Call the begin play method
	for (Actor* actor : this->actors) {
		if (!actor) {
			continue;
		}

		actor->beginPlay();
	}
}

