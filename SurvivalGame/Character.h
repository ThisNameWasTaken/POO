#include "Actor.h"
#include "Sprite.h"

#pragma once
class Character : public Actor {
public:
	Character();
	Character(Sprite sprite);
	~Character();

	void beginPlay() override;
	void update() override;

protected:
	typedef Character Super;
};

