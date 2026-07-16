#include "Creature.h"

Creature::Creature(EntityType type, const std::string& name, const std::string& description, int health, int damage, Room* location) : Entity( type, name, description), health(health), damage(damage), location(location)
{
}

void Creature::Update()
{
}

int Creature::GetHealth() const
{
	return health;
}

int Creature::GetDamage() const
{
	return damage;
}

Room* Creature::GetLocation() const
{
	return location;
}

void Creature::SetLocation(Room* newLocation)
{
	location = newLocation;
}
