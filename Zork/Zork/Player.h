#pragma once
#include "Creature.h"
class Player : public Creature {
public:
	Player(const std::string& name, const std::string& description, int health, int damage, Room* location);
};
