#include "Player.h"
#include "Item.h"
#include <iostream>
Player::Player(const std::string& name, const std::string& description, int health, int damage, Room* location) : Creature(EntityType::Player, name, description, health, damage, location)
{
    
}

void Player::Equip(Item* item)
{
    switch (item->GetItemType()) {

    case ItemType::Weapon:
        if (weapon != nullptr)
        {
            std::cout << "You unequip " << weapon->GetName() << "." << std::endl;
        }

        weapon = item;

        std::cout << "You equip " << weapon->GetName() << "." << std::endl;
        break;

    case ItemType::Armor:
        if (armor != nullptr)
        {
            std::cout << "You unequip " << armor->GetName() << "." << std::endl;
        }

        armor = item;

        std::cout << "You equip " << armor->GetName() << "." << std::endl;
        break;
    default: 
        std::cout << "You can't equip this item." << std::endl;
        break;
    }

}


void Player::UnequipWeapon()
{
    weapon = nullptr;
}

void Player::UnequipArmor()
{
    armor = nullptr;
}

Item* Player::GetWeapon() const
{
	return weapon;
}

Item* Player::GetArmor() const
{
	return armor;
}

int Player::GetAttackDamage() const
{
	if (weapon != nullptr)
	{
		return 30;
	}

	return GetDamage();
}

int Player::GetReciveDamage(int damage) const
{
	if (armor != nullptr)
	{
		damage = damage - damage * 20 / 100;
	}

	return damage;
}



