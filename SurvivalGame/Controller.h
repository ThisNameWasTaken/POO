#pragma once
class Controller {
public:
	Controller();
	~Controller();

	/**
	 * Called when a Character begins playing
	 */
	virtual void onBeginPlay() = 0;
	/**
	 * Called each time a Character is updated
	 */
	virtual void onUpdate() = 0;

	/**
	 * Attaches the current instance to the given Charatcter
	 * @param character - the Character to attach the controller to
	 */
	inline void attachTo(class Character* character) { if (character) { this->character = character; } }

protected:
	class Character* character;
};

