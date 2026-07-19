#include "Creature.h"
#include <iostream>

Creature::Creature(EntityType type, const std::string& name, const std::string& description, int health, int damage, Room* location) : Entity( type, name, description), health(health), damage(damage), location(location)
{
	maxHealth = health;
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

void Creature::TakeDamage(int amount)
{
	health -= amount;
	if (!IsAlive()) {
		health = 0;
	}

}

bool Creature::IsAlive() const
{
	return health > 0;
}

int Creature::GetMaxHp() const
{
	return maxHealth;
}

void Creature::Heal(int amount)
{
	health += amount;

	if (health > maxHealth)
	{
		health = maxHealth;
		std::cout << "Hp healed up to: " << health <<".";
	}
}



