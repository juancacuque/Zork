#include "World.h"
#include "Room.h"
#include "Exit.h"
#include "Player.h"
#include "InputReader.h"
#include "Item.h"
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

	Item* backpack = new Item("backpack", "Your backpack. You can save items or throw them from here.");
	Item* potion = new Item("potion", "A healing potion.");
	Item* sword = new Item("sword", "A large but old sword. Looks like it has gone through rough battles before.");
	Item* armor = new Item("armor", "A bit small armor for you, but will work to protect you frome reciving some damage.");
	Item* bag = new Item("bag", "A small bag. You grab it and seems to not be empty.", true);
	Item* key = new Item("key", "A small key, it might be usefull for your journey.");
	Item* map = new Item("map", "A map of the cave.");

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

	AddEntity(backpack);
	AddEntity(potion);
	AddEntity(sword);
	AddEntity(armor);
	AddEntity(bag);
	AddEntity(key);
	AddEntity(map);

	player->Add(backpack);

	room2->Add(potion);

	room3->Add(sword);

	room4->Add(armor);
	room4->Add(bag);

	bag->Add(key);

	room5->Add(map);
	
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

bool World::MoveEntity(Entity* entityToMove, Entity* from, Entity* to)
{
	if (from->Remove(entityToMove))
	{
		to->Add(entityToMove);
		return true;
	}

	return false;
}

void World::Play()
{
	bool canPlay = true;

	player->GetLocation()->Look();

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
		else if (tokens[0] == "go") 
		{

			Go(tokens);
		}
		else if (tokens[0]== "take") 
		{
			Take(tokens);
		}
		else if (tokens[0] == "drop")
		{
			Drop(tokens);
		}
		else if (tokens[0] == "look")
		{
			player->GetLocation()->Look();
		}
		else if (tokens[0] == "open")
		{
			Open(tokens);
		}
		else if (tokens[0] == "put")
		{
			Put(tokens);
		}
		else
		{
			std::cout << "Unknown command. Type help for a list of commands.";
		}
	}
}

void World::Go(const std::vector<std::string>& tokens)
{
	if (tokens.size() < 2) {
		std::cout << "You have to specify a direction (north, south, east, west).";
	}
	else {
		ExitDirection dir;
		if (tokens[1] == "north") {
			dir = ExitDirection::North;
		}
		else if (tokens[1] == "south") {
			dir = ExitDirection::South;
		}
		else if (tokens[1] == "east") {
			dir = ExitDirection::East;
		}
		else if (tokens[1] == "west") {
			dir = ExitDirection::West;
		}
		else {
			std::cout << "Not valid direction, try again or type help for a list of commands.";
			std::cout << std::endl;
			return;
		}

		Room* currentRoom = player->GetLocation();
		Exit* exit = currentRoom->GetExit(dir);
		if (exit == nullptr) {
			std::cout << "You can't go through this direction as you face a wall";
		}
		else if (exit->GetLockStatus()) {
			std::cout << "This path is blocked, you might need some object to open it.";
		}
		else {
			Room* nextRoom = exit->GetDestination();
			player->SetLocation(nextRoom);
			std::cout << "You go through " << exit->GetName() << " and you get to the " << nextRoom->GetName() << ".";
			std::cout << std::endl;
			nextRoom->Look();
		}
	}
}

void World::Take(const std::vector<std::string>& tokens)
{
	if (tokens.size() < 2)
	{
		std::cout << "Take what?";
		return;
	}

	Room* room = player->GetLocation();
	Entity* backpack = player->Find("backpack");
	Entity* entity = room->Find(tokens[1]);
	
	if (entity == nullptr)
	{
		std::cout << "There is no " << tokens[1] << " here.";
		return;
	}
	if (backpack == nullptr)
	{
		return;
	}

	if (entity->GetType() != EntityType::Item) 
	{
		std::cout << "You can't take that.";
		return;
	}

	if (entity->GetType() == EntityType::Item)
	{
		Item* item = static_cast<Item*>(entity);

		if (!item->GetHiddenStatus())
		{
			if (MoveEntity(item, room, backpack)) {
				std::cout << "You took the " << item->GetName() << " and put it in your backpack.";
			}
		}

		else
		{
			std::cout << "You can't see any " << tokens[1] << " here.";
		}
	}
}

void World::Drop(const std::vector<std::string>& tokens)
{
	if (tokens.size() < 2)
	{
		std::cout << "Drop what?";
		return;
	}
	Room* room = player->GetLocation();
	Entity* backpack = player->Find("backpack");
	if (backpack == nullptr)
	{
		return;
	}
	Entity* entity = backpack->Find(tokens[1]);
	

	if (entity == nullptr)
	{
		std::cout << "You don't have a " << tokens[1] << " in your backpack.";
		return;
	}
	

	if (MoveEntity(entity, backpack, room)) {
		std::cout << "You dropped the " << entity->GetName() << " in the " << room->GetName() << ".";
	}
}

void World::Open(const std::vector<std::string>& tokens)
{
	if (tokens.size() < 2)
	{
		std::cout << "Open what?";
		return;
	}

	Room* room = player->GetLocation();
	Entity* backpack = player->Find("backpack");
	if (backpack == nullptr)
	{
		return;
	}

	Entity* entity = room->Find(tokens[1]);

	if (entity == nullptr)
	{
		entity = backpack->Find(tokens[1]);
	}

	if (entity == nullptr)
	{
		entity = player->Find(tokens[1]);
	}

	if (entity == nullptr)
	{
		std::cout << "There is no " << tokens[1] << " here.";
		return;
	}

	if (entity->GetType() != EntityType::Item)
	{
		std::cout << "You can't open that.";
		return;
	}

	if (entity->GetType() == EntityType::Item)
	{
		Item* item = static_cast<Item*>(entity);

		if (item->GetHiddenStatus())
		{
			std::cout << "There is no " << tokens[1] << " here.";
			return;
		}

		if (item->GetContains().empty())
		{
			std::cout << "The " << item->GetName() << " is empty.";
			return;
		}

		std::cout << "The " << item->GetName() << " contains:" << std::endl;

		for (Entity* entity : item->GetContains())
		{
			std::cout << entity->GetName() << std::endl;
		}
	}
	
}

void World::Put(const std::vector<std::string>& tokens)
{
	if (tokens.size() < 4 || tokens[2] != "in")
	{
		std::cout << "Put what in what? Try: put [item] in [bag]";
		return;
	}

	Entity* backpack = player->Find("backpack");

	if (backpack == nullptr)
	{
		return;
	}

	Entity* itemEntity = backpack->Find(tokens[1]);

	if (itemEntity == nullptr)
	{
		std::cout << "There is no " << tokens[1] << ".";
		return;
	}

	Room* room = player->GetLocation();

	Entity* bag = room->Find(tokens[3]);

	if (bag == nullptr)
	{
		bag = backpack->Find(tokens[3]);
	}

	if (bag == nullptr)
	{
		bag = player->Find(tokens[3]);
	}

	if (bag == nullptr)
	{
		std::cout << "There is no " << tokens[3] << " here.";
		return;
	}

	if (bag->GetType() != EntityType::Item)
	{
		std::cout << "You can't put something in that.";
		return;
	}

	if (bag->GetType() == EntityType::Item)
	{
		Item* item = static_cast<Item*>(itemEntity);
		Item* destination = static_cast<Item*>(bag);

		if (destination->GetHiddenStatus())
		{
			std::cout << "There is no " << tokens[3] << " here.";
			return;
		}

		if (destination == backpack)
		{
			std::cout << "The item is already in your backpack.";
			return;
		}
		if (MoveEntity(item, backpack, destination))
		{
			std::cout << "You put the " << item->GetName() << " in " << destination->GetName() << ".";
		}
	}
	
}





