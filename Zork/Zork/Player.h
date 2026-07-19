#pragma once
#include "Creature.h"
class Item;
class Player : public Creature {
public:
	Player(const std::string& name, const std::string& description, int health, int damage, Room* location);

	void Equip(Item* item);

	void UnequipWeapon();
	void UnequipArmor();

	Item* GetWeapon() const;
	Item* GetArmor() const;

	int GetAttackDamage() const;
	int GetReciveDamage(int damage) const;
private: 
	Item* weapon = nullptr;
	Item* armor = nullptr;

	
};
