#pragma once
#include "Entity.h"
#include "Exit.h"

class Room : public Entity 
{
public:
	Room(const std::string& name, const std::string& description);
	void Update() override;
	virtual void Look() const override;
	
	Exit* GetExit(ExitDirection direction) const;
};