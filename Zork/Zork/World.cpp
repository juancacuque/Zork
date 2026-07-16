#include "World.h"
#include "Room.h"
#include "Exit.h"
#include "Player.h"
#include "InputReader.h"
#include <iostream>

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

void World::CreateWorld()
{
	Room* room1 = new Room("Room 1", "This is the cave entrance.");
	Room* room2 = new Room("Room 2", "This room seems empty.");
	Room* room3 = new Room("Room 3", "This room has been inhabited by that monster for long time, seems like he fighted to protect something or someone...");
	Room* room4 = new Room("Room 4", "There is a vibe like if there was something hidden in this room.");
	Room* room5 = new Room("Room 5", "You see a bright light just in the center of the room.");
	Room* room6 = new Room("Room 6", "Boss room.");

	Exit* exit1 = new Exit("Exit 1", "You see a path in the NORTH direction.", ExitDirection::North, room1, room2, false);
	Exit* exit2 = new Exit("Exit 2", "You see a path in the SOUTH direction.", ExitDirection::South, room2, room1, false);
	Exit* exit3 = new Exit("Exit 3", "You see a path in the NORTH direction.", ExitDirection::North, room2, room3, false);
	Exit* exit4 = new Exit("Exit 4", "You see a path in the EAST direction.", ExitDirection::East, room2, room5, false);
	Exit* exit5 = new Exit("Exit 5", "You see a path in the WEST direction.", ExitDirection::West, room2, room4, false);
	Exit* exit6 = new Exit("Exit 6", "You see a path in the WEST direction.", ExitDirection::West, room5, room2, false);
	Exit* exit7 = new Exit("Exit 7", "You see a path in the EAST direction.", ExitDirection::East, room4, room2, false);
	Exit* exit8 = new Exit("Exit 8", "You see a path in the SOUTH direction.", ExitDirection::South, room3, room2, false);
	Exit* exit9 = new Exit("Exit 9", "You see a path in the NORTH direction.", ExitDirection::North, room3, room6, true);
	Exit* exit10 = new Exit("Exit 10", "You see a path in the SOUTH direction.", ExitDirection::South, room6, room3, false);
	
	player = new Player ("Player", "This is you.", 100, 10, room1);

	room1->Add(exit1);
	room2->Add(exit2);
	room2->Add(exit3);
	room2->Add(exit4);
	room2->Add(exit5);
	room3->Add(exit8);
	room3->Add(exit9);
	room4->Add(exit7);
	room5->Add(exit6);
	room6->Add(exit10);

	AddEntity(room1);
	AddEntity(room2);
	AddEntity(room3);
	AddEntity(room4);
	AddEntity(room5);
	AddEntity(room6);

	AddEntity(exit1);
	AddEntity(exit2);
	AddEntity(exit3);
	AddEntity(exit4);
	AddEntity(exit5);
	AddEntity(exit6);
	AddEntity(exit7);
	AddEntity(exit8);
	AddEntity(exit9);
	AddEntity(exit10);

	AddEntity(player);
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

void World::Play()
{
	bool canPlay = true;

	while (canPlay)
	{
		std::cout << "> ";

		std::string line;
		std::getline(std::cin, line);

		auto tokens = InputReader::Tokenize(line);

		if (tokens.empty())
		{
			continue;
		}

		if (tokens[0] == "quit")
		{
			canPlay = false;
		}
		else
		{
			std::cout << "Unknown command. Type help for a list of commands.";
		}

		std::cout << std::endl;
	}
}



