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
};

