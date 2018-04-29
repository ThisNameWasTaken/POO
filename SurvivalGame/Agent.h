#pragma once
#include "Character.h"

class Agent : public Character {
public:
	Agent(const Vector2D& position = Vector2D(0, 0), const string& tagName = "");
	Agent(const Agent& agent);
	Agent(const Sprite& sprite, class Controller* controller = nullptr, const string& tagName = "");
	~Agent();

	inline string getTagName() const { return this->tagName; }
	inline void setTagName(const string& tagName) { this->tagName = tagName; }

protected:
	string tagName;
};

