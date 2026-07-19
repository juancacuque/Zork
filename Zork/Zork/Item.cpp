#include "Item.h"

Item::Item(const std::string& name,const std::string& description, bool isHidden, ItemType type) : Entity(EntityType::Item, name, description),isHidden(isHidden), itemType(type)
{
}

void Item::Update()
{
}

bool Item::GetHiddenStatus() const
{
    return isHidden;
}

ItemType Item::GetItemType() const
{
    return itemType;
}

void Item::Reveal()
{
    isHidden = false;
}

bool Item::IsOpen() const
{
    return opened;
}

void Item::Open()
{
	opened = true;
}
