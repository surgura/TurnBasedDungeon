#pragma once
#include <SFML/Network.hpp>
#include <string>
#include <iostream>
#include <thread>
#include <map>
#include "DungeonObject.hpp"
#include "PositionUpdate.hpp"

class Client
{
	sf::TcpSocket server;
	std::map<sf::Uint32, DungeonObject> dObjects;

	template <typename PacketType>
	PacketType ReceivePacket()
	{
		sf::Packet packet;
		server.receive(packet);
		PacketType data;
		packet >> data;
		return data;
	}
public:
	Client() {};
	int connect(std::string = "127.0.0.1", size_t = 1);

};

