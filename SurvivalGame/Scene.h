#pragma once

#include <set>
#include <Windows.h>
#include "Sprite.h"

class Scene {
public:
	Scene();
	Scene(const int width, const int height, const Sprite& tile, const std::set<class Actor*> actors);
	~Scene();

	void render();

private:
	void renderFirstPaint() const;

	set<class Actor*> actors;
	Sprite tile;
	int width;
	int height;
	bool isFirstPaint;

	static HANDLE consoleHandle;
	static CONSOLE_SCREEN_BUFFER_INFO consoleInfo;
};

