#pragma once

#include "PickUp.h"
#include "Texture.h"

class SharpenedClaws : public PickUp {
public:
	SharpenedClaws(const Vector2D& position = Vector2D(0, 0));
	SharpenedClaws(const SharpenedClaws& pickup);
	SharpenedClaws(const Sprite& sprite, const Vector2D& position = Vector2D(0, 0));

	virtual void beginPlay() override;
	virtual void update() override;

	virtual void buff(class Agent* agent) override;

private:
	static Texture texture;
};

