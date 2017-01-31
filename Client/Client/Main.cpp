#include "Client.hpp"
#include <SFML/Network.hpp>

int main()
{
	Client client;
	client.connect("127.0.0.1", 10);

	return 0;
}