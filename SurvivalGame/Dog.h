#pragma once

#include "Agent.h"
#include "Texture.h"

class Dog : public Agent {
public:
	Dog(const Vector2D& position = Vector2D(0, 0), const string& tagName = "dog");
	Dog(class Controller* controller, const Vector2D& position = Vector2D(0, 0), const string& tagName = "dog");
	~Dog();

	virtual void beginPlay() override;
	virtual void update() override;

protected:
	typedef Agent Super;

private:
	class Controller* controller;
	static Texture texture;
};

