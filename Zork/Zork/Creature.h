#pragma once
#include "Entity.h"
class Room;
class Creature : public Entity {
public:
	Creature(EntityType type, const std::string& name, const std::string& description, int health, int damage, Room* location);
	void Update() override;

	int GetHealth() const;
	int GetDamage() const;
	Room* GetLocation() const;
	void SetLocation(Room* newLocation);
private:
	int health;
	int damage;
	Room* location;
};