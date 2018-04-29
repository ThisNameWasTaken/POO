#pragma once

#include "Agent.h"
#include "Texture.h"

class Kitty : public Agent {
public:
	Kitty(const Vector2D& position = Vector2D(0, 0), const string& tagName = "kitty");
	Kitty(class Controller* controller, const Vector2D& position = Vector2D(0, 0), const string& tagName = "kitty");
	~Kitty();

	virtual void beginPlay() override;
	virtual void update() override;

protected:
	typedef Agent Super;

private:
	class Controller* controller;
	static Texture texture;
};

