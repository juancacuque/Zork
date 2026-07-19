#include "Exit.h"
#include <iostream>

Exit::Exit(const std::string& name, const std::string& description, ExitDirection direction, Room* source, Room* destination, bool lock): Entity(EntityType::Exit, name, description), direction(direction), source(source), destination(destination), key(nullptr), lock(lock)
{
}
void Exit::Update()
{

}
void Exit::SetKey(Item* key)
{
	this->key = key;
}
void Exit::Unlock()
{
	lock = false;
}

bool Exit::GetLockStatus() const
{
	return lock;
}

Item* Exit::GetKey() const
{
	return key;
}


Room* Exit::GetDestination() const
{
	return destination;
}

ExitDirection Exit::GetDirection() const
{
	return direction;
}
