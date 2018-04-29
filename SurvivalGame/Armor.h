#pragma once

#include "PickUp.h"

class Armor : public PickUp {
public:
	Armor(const Vector2D& position = Vector2D(0, 0));
	Armor(const Armor& pickup);
	Armor(const Sprite& sprite, const Vector2D& position = Vector2D(0, 0));

	virtual void beginPlay() override;
	virtual void update() override;

	virtual void buff(class Agent* agent) override;
};

