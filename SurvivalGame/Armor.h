#pragma once

#include "PickUp.h"
#include "Texture.h"

class Armor : public PickUp {
public:
	Armor(const Vector2D& position = Vector2D(0, 0));
	Armor(const Armor& pickup);

	virtual void beginPlay() override;
	virtual void update() override;

	virtual void buff(class Agent* agent) override;


private:
	static Texture texture;
};

