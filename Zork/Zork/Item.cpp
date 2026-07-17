#include "Item.h"

Item::Item(const std::string& name, const std::string& description, bool isHidden) : Entity(EntityType::Item, name, description), isHidden(isHidden)
{
}

void Item::Update()
{
}

bool Item::GetHiddenStatus() const
{
	return isHidden;
}
