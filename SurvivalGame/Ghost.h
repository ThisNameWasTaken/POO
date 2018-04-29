#pragma once

#include "Agent.h"
#include "Texture.h"

class Ghost : public Agent {
public:
	Ghost(const Vector2D& position = Vector2D(0, 0), const string& tagName = "ghost");
	Ghost(class Controller* controller, const Vector2D& position = Vector2D(0, 0), const string& tagName = "ghost");
	~Ghost();

	virtual void beginPlay() override;
	virtual void update() override;

protected:
	typedef Agent Super;

private:
	class Controller* controller;
	static Texture texture;
};

