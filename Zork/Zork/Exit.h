#pragma once
#include "Entity.h"

class Room;
class Item;

enum class ExitDirection
{
	North,
	South,
	East,
	West
};

class Exit : public Entity
{
public:
	Exit(const std::string& name, const std::string& description, ExitDirection direction, Room* source, Room* destination, bool lock);
	void Update() override;
	void SetKey(Item* key);
	void Unlock();

	Room* GetDestination() const;
	ExitDirection GetDirection() const;
	bool GetLockStatus() const;
	
	Item* GetKey() const;
private:
	ExitDirection direction;
	Room* source;
	Room* destination;
	Item* key;

	bool lock;
};
