#include "Player.h"

Player::Player(const std::string& name, const std::string& description, int health, int damage, Room* location) : Creature(EntityType::Player, name, description, health, damage, location)
{
}
