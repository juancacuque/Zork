#include "World.h"
#include <algorithm>

World::World()
{
}

World::~World()
{
	for (auto entity : entities) 
	{
		delete entity;
	}

	entities.clear();
}

void World::AddEntity(Entity* entity)
{
	entities.push_back(entity);
}

bool World::RemoveEntity(Entity* entity)
{
	auto objective = std::remove(entities.begin(), entities.end(), entity);
	if (objective != entities.end())
	{
		entities.erase(objective, entities.end());
		return true;
	}
	return false;
}

const std::vector<Entity*>& World::GetEntities() const
{
	return entities;
}
