#pragma once
#include "Entity.h"

class Item : public Entity 
{
public:
	Item( const std::string& name, const std::string& description, bool isHidden=false);
	void Update() override;
	bool GetHiddenStatus() const;

private:
	bool isHidden;
};
