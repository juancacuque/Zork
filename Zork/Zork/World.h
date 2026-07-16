#pragma once
#include <vector>
#include "Entity.h"

class World {
public :
    World();
	~World();

	void CreateWorld();

	void AddEntity(Entity* entity);
	bool RemoveEntity(Entity* entity);
	const std::vector<Entity*>& GetEntities() const;

	void Play();

	
private: 
	std::vector<Entity*> entities;
};

