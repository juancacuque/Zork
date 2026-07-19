#pragma once
#include <string>
#include <list>

enum class EntityType
{
    Room,
    Exit,
    Item,
    Npc,
    Creature,
    Player
};
class Entity {
public:

    Entity(EntityType type, const std::string& name, const std::string& description);

    virtual ~Entity();

    virtual void Update();

    const std::string& GetName() const;
    const std::string& GetDescription() const;
    EntityType GetType() const;
    virtual void Look() const;

	const std::list<Entity*>& GetContains() const;

    Entity* Find(const std::string& name) const;

    void Add(Entity* entity);
    bool Remove(Entity* entity);

    Entity* GetParent() const;
protected:

    EntityType type;
    std::string name;
    std::string description;

private:

    std::list<Entity*> contains;

    Entity* parent = nullptr;
};