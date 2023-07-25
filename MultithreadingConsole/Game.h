#pragma once
#include <vector>
#include "Player.h"
#include "TaskManager.h"

class Game
{
public:
	Game();

private:
	std::vector<Player*> mPlayers;
	int mPlayerCount = 2;

	TaskManager* mTaskManager;

private:
	void Init();

public:
	void RunLoop();
	void PrintPlayerList();
	void Shutdown();

};

