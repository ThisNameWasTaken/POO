#pragma once

#include "Controller.h"

class PlayerController : Controller {
public:
	PlayerController();
	~PlayerController();

	virtual void update() override;
};

