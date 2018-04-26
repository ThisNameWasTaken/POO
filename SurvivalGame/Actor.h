#pragma once

#include "Vector2D.h"
#include "Sprite.h"
#include <set>

using namespace std;

class Actor {
  public:
	Actor();
	Actor(Sprite sprite);
	~Actor();

	virtual void beginPlay() = 0;
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

  protected:
	typedef Actor Super;

  private:
	Vector2D position;
	Sprite sprite;
	// All the actors that have been spawned so far
	static set<Actor*> worldActors;
};
