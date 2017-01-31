#include "DungeonObject.hpp"

sf::Packet& operator >> (sf::Packet& packet, DungeonObject& d)
{
	return packet >> d.InstanceID >> d.TypeID >> d.X >> d.Y;
}