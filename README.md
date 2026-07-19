# \#Zork

This is a text-based Zork-like game made in C++ for UPC AAA Master´s admission test.



\## Author: 

Juan Carlos Cuquerella Naves



\## How to play:

Use text commands to explore the cave, collect items, fight enemies and defeat the final boss.



\### Available commands:

\- go north/south/east/west

\- look

\- take <item>

\- drop <item>

\- open <item>

\- put <item> in <container>

\- equip <item>

\- use <item>

\- read <item>

\- search

\- attack

\- help

\- quit



\## Objective: 

Explore the cave, obtain the sword and the key, unlock the final path and defeat the boss.



\## How to finish the game:

Explore every room of the cave:

* Search Room 4 to discover the hidden bag containing the key.
* Defeat the monster to obtain the sword from the chest.
* Equip the sword.
* Unlock the final path using the key.
* Defeat the final boss.



\## Notes:

* The project was designed using an object-oriented approach where rooms, items, exits, the player and NPCs all inherit from the same base Entity class.
* The main extra features are an inventory system with containers, equipment, combat, hidden items, locked exits and a final boss encounter.
* One of the main challenges during development was implementing containers correctly. This was solved with a recursive search through the containers and parent tracking on every entity, allowing items to be moved correctly between rooms, containers and the player's inventory.



\## GitHub Repository: 

https://github.com/juancacuque/Zork

\## Download: 

https://github.com/juancacuque/Zork/releases/tag/v1



\## License: 

This project is distributed under the MIT License.

