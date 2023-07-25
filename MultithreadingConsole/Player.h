#pragma once
#include <string>

class Player
{
public:
	Player(std::string name);

private:
	std::string mName;

public:
	void Attack();

	// Getter
	std::string GetName() { return mName; }
};

