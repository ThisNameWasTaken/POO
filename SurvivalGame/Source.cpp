#include "Engine.h"
#include <conio.h>

int main() {
	Engine::start();

	Texture tileTexture("Textures/tile.txt");
	Texture catTexture("Textures/cat_2.txt");
	Texture dogTexture("Textures/dog.txt");
	Texture owlTexture("Textures/owl.txt");
	Texture ghostTexture("Textures/ghost.txt");
	Texture brickTexture("Textures/brick.txt");

	Sprite tileSprite(&tileTexture);
	Sprite catSprite(&catTexture);
	Sprite dogSprite(&dogTexture);
	Sprite owlSprite(&owlTexture);
	Sprite ghostSprite(&ghostTexture);
	Sprite brickSprite(&brickTexture);

	InputController playerController;
	Character player(catSprite, &playerController);
	
	Scene scene(10, 10, tileSprite, Actor::getWorldActors());
	while (true) {
		scene.render();
		cout << "Waiting on the other players...";
		Sleep(1000);
	}

	// cout << catSprite << " " << dogSprite << "  " << catSprite << " " << owlSprite << " " << ghostSprite << " "  << endl << endl << endl << endl << endl << endl;
	// cout << endl << endl << endl << endl << endl;

	system("pause");
	return 0;
}