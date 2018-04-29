#include "Agent.h"
#include "Controller.h"
#include "Console.h"
#include "Random.h"
#include "Scene.h"
#include "PickUp.h"
#include <string>

Agent::Agent(const Vector2D& position, const string& tagName) : Character(position) {
	this->tagName = tagName;
}

Agent::Agent(const Agent& agent) : Character(agent) {
	this->tagName = agent.getTagName();
}

Agent::Agent(const Sprite& sprite, Controller* controller, const Vector2D& position, const string& tagName) : Character(sprite, controller, position) {
	this->tagName = tagName;
}

Agent::~Agent() {

}

void Agent::beginPlay() {
	Super::beginPlay();
	const Scene* scene = Scene::getActiveScene();
	if (scene) {
		this->setPosition(Vector2D(random(scene->getHeight()), random(scene->getWidth())));
	}
}

void Agent::update() {
	Super::update();

	const Scene* activeScene = Scene::getActiveScene();
	if (activeScene) {
		Console::setCursorPosition(0, 56);
	}

	set<Actor*> overlappingActors = this->getOverlappingActors();
	for (Actor* actor : overlappingActors) {
		Agent* agent = dynamic_cast<Agent*>(actor);
		if (agent) {
			this->damage(agent);

			if (this->getHP() > 0) {
				cout << this->getTagName() << " eliminated " << agent->getTagName() << "\n";
				agent->Destroy();
			}
			else if (agent->getHP() > 0) {
				cout << agent->getTagName() << " eliminated " << this->getTagName() << "\n";
				this->Destroy();
			}
			else {
				cout << this->getTagName() << " and " << agent->getTagName() << " eliminated each other\n";
				this->Destroy();
				agent->Destroy();
			}
		}

		PickUp* pickUp = dynamic_cast<PickUp*>(actor);
		if (pickUp) {
			pickUp->buff(this);
		}
	}
}

void Agent::damage(Agent* target) {
	if (target->getHP() <= 0) {
		return;
	}
	// The amout of damage which remains to be dealt
	// after the target's armor is broken
	int damageToBeDealt = this->getAD();

	int targetArmor = target->getArmor();
	target->setArmor(targetArmor - damageToBeDealt);

	damageToBeDealt -= targetArmor;
	target->setHP(target->getHP() - damageToBeDealt);

	target->onDamageTaken(this);
}

void Agent::onDamageTaken(Agent* instigator) {
	this->damage(instigator);
}
