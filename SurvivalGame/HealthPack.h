#pragma once

#include "PickUp.h"

class HealthPack : public PickUp {
public:
	HealthPack(const Vector2D& position = Vector2D(0, 0));
	HealthPack(const HealthPack& pickup);
	HealthPack(const Sprite& sprite, const Vector2D& position = Vector2D(0, 0));

	virtual void beginPlay() override;
	virtual void update() override;

	virtual void buff(class Agent* agent) override;
};

