#pragma once

#include "Agent.h"
#include "Texture.h"

class Cat : public Agent {
public:
	Cat(const Vector2D& position = Vector2D(0, 0), const string& tagName = "cat");
	Cat(class Controller* controller, const Vector2D& position = Vector2D(0, 0), const string& tagName = "cat");
	~Cat();

	virtual void beginPlay() override;
	virtual void update() override;

private:
	class Controller* controller;
	static Texture texture;
};

