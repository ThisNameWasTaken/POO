#pragma once

#include <iostream>
#include <string>
#include "Vector2D.h"
#include "Texture.h"
#include "Sprite.h"
#include "Actor.h"
#include "Character.h"
#include "Scene.h"

using namespace std;

class Engine {
public:
	static void start();

private:
	Engine();
	Engine(const Engine&) = delete;
	Engine(Engine&&) = delete;
	void operator=(const Engine&) = delete;
	void operator=(Engine&&) = delete;
};

