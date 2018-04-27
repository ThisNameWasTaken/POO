#include "Actor.h"
#include "Sprite.h"
#include "Controller.h"

#pragma once
class Character : public Actor {
public:
	Character();
	Character(const Character& character);
	Character(Sprite sprite, Controller* controller = nullptr);
	~Character();

	const Character& operator=(const Character& vector);

	void beginPlay() override;
	void update() override;

	/**
	 * Moves a character from its current position by a given value
	 * @param value - the value to move the actor by
	 */
	inline virtual void move(const Vector2D& value) { this->setPosition(this->getPosition() + value); }

	inline void setController(Controller* controller) { if (!controller) return; this->controller = controller; this->controller->attachTo(this); }
	inline Controller* getController() const { return this->controller; }

protected:
	typedef Character Super;

private:
	Controller* controller;
};

