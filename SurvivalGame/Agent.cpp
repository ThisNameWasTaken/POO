#include "Agent.h"

Agent::Agent(const Vector2D& Position, const string& tagName) : Character(Position) {

}

Agent::Agent(const Agent& agent) : Character(agent) {
	this->tagName = agent.getTagName();
}

Agent::Agent(const Sprite& sprite, Controller* controller, const string& tagName) : Character(sprite, controller) {
	this->tagName = tagName;
}

Agent::~Agent() {

}
