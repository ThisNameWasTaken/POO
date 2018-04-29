#pragma once

#include "Vector2D.h"
#include "Sprite.h"
#include <set>

using namespace std;

class Actor {
  public:
	Actor(const Vector2D& position = Vector2D(0, 0));
	Actor(const Actor& actor);
	Actor(const Sprite& sprite, const Vector2D& position = Vector2D(0, 0));
	~Actor();

	const Actor& operator=(const Actor& actor);

	/**
	 * Called when the game starts
	 */
	virtual void beginPlay() = 0;
	/**
	 * Called each turn
	 */
	virtual void update() = 0;

	inline Vector2D getPosition() const { return this->position; }
	void setPosition(const Vector2D& position);

	inline Sprite getSprite() const { return this->sprite; }
	inline void setSprite(Sprite sprite) { this->sprite = sprite; }

	/** 
	 * @returns - All the actors that have been spawned so far.
	 */
	static inline set<Actor*> getWorldActors() { return worldActors; }

	/**
	 * @param range - How far from the current actor's instance can the other actors be.
	 * @returns - All the actors that are in a given range of the current actor's instance.
	 */
	set<Actor*> getActorsInRange(int range) const;

	/**
	 * @returns - All actors that have the same position as the current actor's instance.
	 */
	set<Actor*> getOverlappingActors() const;

	/**
	 * A boolean value which asserts whether the actor should be updated every turn or not
	 */
	bool shouldUpdate;

	/**
	 * Destroys the current instance
	 */
	void Destroy();

  protected:
	typedef Actor Super;

	Vector2D position;
	Sprite sprite;

private:
	// All the actors that have been spawned so far
	static set<Actor*> worldActors;
};
