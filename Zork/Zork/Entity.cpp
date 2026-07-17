#include "Entity.h"
#include <iostream>
Entity::Entity(EntityType type, const std::string& name, const std::string& description) : type(type), name(name), description(description)
{
}

Entity::~Entity()
{
}

void Entity::Update()
{
}

const std::string& Entity::GetName() const
{
    return name;
}

const std::string& Entity::GetDescription() const
{
	return description;
}

EntityType Entity::GetType() const
{
    return type;
}

void Entity::Look() const
{
    std::cout << GetName() << std::endl;
	std::cout << GetDescription() << std::endl;
}


const std::list<Entity*>& Entity::GetContains() const
{
    return contains;
}

Entity* Entity::Find(const std::string& name) const
{
    for (Entity* entity : GetContains())
    {
        if (entity->GetName() == name)
        {
            return entity;
        }
    }
    return nullptr;
}

void Entity::Add(Entity* entity)
{
    contains.push_back(entity);
}

bool Entity::Remove(Entity* entity)
{
    auto before = contains.size();
    contains.remove(entity);

    if (contains.size() < before)
    {
        return true;
    }

    else 
    {
        return false;
    }
    
}
