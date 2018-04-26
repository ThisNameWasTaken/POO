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

	inline static const Scene* getActiveScene() { return activeScene; };
	inline int getWidth() const { return this->width; }
	inline int getHeight() const { return this->height; }

private:
	void renderFirstPaint() const;

	set<class Actor*> actors;
	Sprite tile;
	int width;
	int height;
	bool isFirstPaint;

	static Scene* activeScene;
};

