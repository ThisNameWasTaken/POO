#pragma once

#include "Controller.h"

class InputController : public Controller {
public:
	InputController();
	~InputController();

	virtual void onBeginPlay() override;
	virtual void onUpdate() override;
};

