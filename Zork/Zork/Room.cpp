#include <iostream>
#include "Room.h"

Room::Room(const std::string& name, const std::string& description) : Entity(EntityType::Room, name, description)
{

}

void Room::Update()
{
}

void Room::Look() const
{
    Entity::Look();

    bool printedItems = false;

    for (Entity* entity : GetContains())
    {
        if (entity->GetType() != EntityType::Exit)
        {
            if (!printedItems)
            {
                std::cout << "You can see in the room: " << std::endl;
                printedItems = true;
            }

            std::cout << entity->GetName() << std::endl;
            
        }
    }

    std::cout << "There are some possible open paths: " << std::endl;

    for (Entity* entity : GetContains())
    {
        if (entity->GetType() == EntityType::Exit)
        {
            std::cout << entity->GetName() << std::endl;
            std::cout << entity->GetDescription() << std::endl;
        }
    }
}

Exit* Room::GetExit(ExitDirection direction) const
{
    for (Entity* entity : GetContains())
    {
        if (entity->GetType() == EntityType::Exit)
        {
            Exit* exit = static_cast<Exit*>(entity);

            if (exit->GetDirection() == direction)
            {
                return exit;
            }
        }
    }
    return nullptr;
}
