#include "NPC.h"

NPC::NPC(const std::string& name, const std::string& description, int health, int damage, Room* location): Creature(EntityType::Npc, name, description, health, damage, location)
{
}

void NPC::Update()
{
}
