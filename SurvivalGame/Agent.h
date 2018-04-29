#pragma once
#include "Character.h"
#include <math.h>

class Agent : public Character {
public:
	Agent(const Vector2D& position = Vector2D(0, 0), const string& tagName = "");
	Agent(const Agent& agent);
	Agent(const Sprite& sprite, class Controller* controller = nullptr, const Vector2D& position = Vector2D(0, 0), const string& tagName = "");
	~Agent();

	virtual void beginPlay() override;
	virtual void update() override;

	inline string getTagName() const { return this->tagName; }
	inline void setTagName(const string& tagName) { this->tagName = tagName; }

	inline int getHP() const { return this->HP; }
	inline void setHP(int HP) { if (HP > maxHP) { this->HP = maxHP; } else { this->HP = HP; } }

	inline int getArmor() const { return this->armor; }
	inline void setArmor(int armor) { if (armor > maxArmor) { this->armor = maxArmor; } else { this->armor = armor; } }

	inline int getAD() const { return this->AD; }
	inline void setAD(int AD) { if (AD < 0) { this->AD = 0; } else { this->AD = AD; } }

	/**
	 * Damages a target Agent by this instance's attack damage (AD)
	 * @param target - the Agent to be damaged
	 */
	virtual void damage(Agent* target);

	/**
	 * Called when an Agent is attacked
	 * @param instigator - the Agent which attacks this instance
	 */
	virtual void onDamageTaken(Agent* instigator);

protected:
	int maxHP;
	int maxArmor;

private:
	string tagName;
	int HP;
	int armor;
	int AD;
};

