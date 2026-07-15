#include <iostream>
#include "World.h"

int main()
{
	World world;
	world.CreateWorld();
	
    // temporal
    for (Entity* entity : world.GetEntities())
    {
        if (entity->GetType() == EntityType::Room)
        {
            entity->Look();
        }
    }

}