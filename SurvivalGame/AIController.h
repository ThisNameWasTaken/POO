#pragma once

#include "Controller.h"

class AIController : public Controller {
public:
	AIController();
	~AIController();

	virtual void onBeginPlay() override;
	virtual void onUpdate() override;

	/**
	 * Chases a given Actor until it has been reached
	 * @param actor - the Actor to chase
	 */
	virtual void chase(const class Actor* actor);
};

