#pragma once

#include "Controller.h"

class AIController : Controller {
public:
	AIController();
	~AIController();

	virtual void update() override;
};

