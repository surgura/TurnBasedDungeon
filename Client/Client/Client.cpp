#include "client.hpp"

using namespace std;

int Client::connect(string ip, size_t maxAttempts)
{
	size_t attempts = 0;
	sf::Socket::Status status;
	do 
	{
		cout << "Attempting to connect..." << endl;
		status = server.connect(ip, 53000);
		if (status != sf::Socket::Done)
		{
			cout << "Connection failed";
			if (++attempts < maxAttempts)
			{
				cout << ", trying again in 5 seconds." << endl;
				this_thread::sleep_for(5s);
			}
			else
			{
				cout << "." << endl;
			}
		}
	} while (status != sf::Socket::Done && attempts < maxAttempts);

	if (status == sf::Socket::Done)
	{
		cout << "Connection established." << endl;
		return 1;
	}
	return 0;
}

/*uint8_t Client::ReceiveMsgID()
{
	sf::Packet packet;
	server.receive(packet);
	uint8_t msgID;
	packet >> msgID;
	return msgID;
}

DungeonObject Client::ReceiveDungeonObject()
{
	sf::Packet packet;
	server.receive(packet);
	DungeonObject d;
	packet >> d;
	return d;
}

PositionUpdate Client::ReceivePositionUpdate(typename T)
{
	sf::Packet packet;
	server.receive(packet);
	PositionUpdate p;
	packet >> p;
	return p;
}*/