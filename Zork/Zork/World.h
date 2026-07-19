#pragma once
#include <vector>
#include "Entity.h"

class Player;
class Room;
class NPC;
class World {
public :
    World();
	~World();

	void CreateWorld();

	void AddEntity(Entity* entity);
	bool RemoveEntity(Entity* entity);
	const std::vector<Entity*>& GetEntities() const;

	bool MoveEntity(Entity* entityToMove, Entity* from, Entity* to);

	void Play();

	
private: 
	std::vector<Entity*> entities;
	Player* player = nullptr;
	void Go(const std::vector<std::string>& tokens);
	void Take(const std::vector<std::string>& tokens);
	void Drop(const std::vector<std::string>& tokens);
	void Open(const std::vector<std::string>& tokens);
	void Put(const std::vector<std::string>& tokens);
	void Equip(const std::vector<std::string>& tokens);
	void Attack();
	void Use(const std::vector<std::string>& tokens);
	void Search();

	NPC* GetEnemy(Room* room) const;

	bool canPlay = true;
};

