#pragma once
#include "Creature.h"
class NPC : public Creature
{
public :
	NPC(const std::string& name, const std::string& description, int health, int damage, Room* location);
	void Update() override;
};
