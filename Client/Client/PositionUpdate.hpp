#pragma once
#include <SFML/Network.hpp>

struct PositionUpdate
{
	std::uint32_t InstanceID;
	std::uint32_t X;
	std::uint32_t Y;
};

sf::Packet& operator >> (sf::Packet& packet, PositionUpdate& d)
{
	return packet >> d.InstanceID >> d.X >> d.Y;
}

sf::Packet& operator << (sf::Packet& packet, PositionUpdate& d)
{
	return packet << d.InstanceID << d.X << d.Y;
}