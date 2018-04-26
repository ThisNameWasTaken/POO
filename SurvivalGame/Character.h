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

	/**
	* Moves a character from its current position by a given value
	* @param value - the value to move the actor by
	*/
	inline virtual void Move(const Vector2D& value) { this->setPosition(this->getPosition() + value); }

protected:
	typedef Character Super;
};

