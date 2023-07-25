#include "Player.h"
#include <iostream>
#include <thread>

Player::Player(std::string name)
{
	mName = name;
}

void Player::Attack()
{
	using namespace std::literals::chrono_literals;
	std::this_thread::sleep_for(3s);
	std::cout << mName << ": Attack!" << std::endl;
}
