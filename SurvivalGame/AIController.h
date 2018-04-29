#pragma once

#include "Controller.h"

class AIController : public Controller {
public:
	AIController();
	~AIController();

	virtual void onBeginPlay() override;
	virtual void onUpdate() override;

	
};

