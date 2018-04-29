#pragma once

#include "Actor.h"

class PickUp : public Actor {
public:
	PickUp(const Vector2D& position = Vector2D(0, 0));
	PickUp(const PickUp& pickup);
	PickUp(const Sprite& sprite, const Vector2D& position = Vector2D(0, 0));

	virtual void beginPlay() override;
	virtual void update() override;

	/**
	 * Buffs a given agent
	 */
	virtual void buff(class Agent* agent) = 0;

protected:
	typedef Super Pickup;
};

