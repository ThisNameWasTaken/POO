#include "Engine.h"
#include "Kitty.h"
#include "Dog.h"
#include "Cat.h"
#include "Ghost.h"
#include "HealthPack.h"
#include "Armor.h"
#include "SharpenedClaws.h"

int main() {
	Engine::start();

	Texture tileTexture("Textures/tile.txt");
	Sprite tileSprite(&tileTexture);

	InputController playerController;
	Ghost player(&playerController);

	AIController ghostController;
	Ghost ghost(&ghostController);

	AIController catController;
	Cat cat(&catController);

	AIController catController2;
	Cat cat2(&catController2);

	AIController dogController;
	Dog dog(&dogController);

	AIController dogController2;
	Dog dog2(&dogController2);

	AIController kittyController;
	Kitty kitty(&kittyController);

	SharpenedClaws claws[4];
	HealthPack healthPacks[4];
	Armor armors[4];
	
	Scene scene(19, 11, tileSprite, Actor::getWorldActors());
	while (true) {
		scene.render();
		Sleep(700);
	}

	system("pause");
	return 0;
}