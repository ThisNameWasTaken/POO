#pragma once
class Controller {
public:
	Controller();
	~Controller();

	virtual void update() = 0;
};

