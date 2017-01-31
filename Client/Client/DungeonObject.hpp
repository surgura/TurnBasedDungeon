#pragma once
#include <SFML/Network.hpp>

struct DungeonObject
{
	std::uint32_t InstanceID;
	std::uint32_t TypeID;
	std::uint32_t X;
	std::uint32_t Y;
};

sf::Packet& operator >> (sf::Packet& packet, DungeonObject& d)
{
	return packet >> d.InstanceID >> d.TypeID >> d.X >> d.Y;
}

sf::Packet& operator << (sf::Packet& packet, DungeonObject& d)
{
	return packet << d.InstanceID << d.TypeID << d.X << d.Y;
}