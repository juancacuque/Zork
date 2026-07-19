#pragma once
#include "Entity.h"
enum class ItemType
{
	None,
	Weapon,
	Armor,
	Consumable,
	Key,
	Openable
};
class Item : public Entity 
{
public:
	Item( const std::string& name, const std::string& description, bool isHidden=false, ItemType type = ItemType::None);
	void Update() override;

	bool GetHiddenStatus() const;
	ItemType GetItemType() const;

	void Reveal();

	bool IsOpen() const;
	void Open();
private:
	bool isHidden;
	ItemType itemType = ItemType::None;
	bool opened = false;
};
