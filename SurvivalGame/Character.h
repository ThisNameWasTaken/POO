#include "Actor.h"
#include "Sprite.h"

#pragma once
class Character : public Actor {
public:
	Character();
	Character(const Character& character);
	Character(Sprite sprite, class Controller* controller = nullptr);
	~Character();

	const Character& operator=(const Character& character);

	void beginPlay() override;
	void update() override;

	/**
	 * Moves a character from its current position by a given value
	 * @param value - the value to move the actor by
	 */
	inline virtual void move(const Vector2D& value) { this->setPosition(this->getPosition() + value); }

	void setController(class Controller* controller);
	inline class Controller* getController() const { return this->controller; }

protected:
	typedef Character Super;

private:
	class Controller* controller;
};

