#include "Game.h"
#include <iostream>
#include <thread>


Game::Game()
{
	Init();
}


void Game::Init()
{
	std::cout << "Start game!" << std::endl;

	mTaskManager = new TaskManager();

	// Create Player and Add then to Player list;
	for (int i = 0; i < mPlayerCount; i++) {
		std::string PlayerName = "Player: ";
		PlayerName += std::to_string(i);
		Player* newPlayer = new Player(PlayerName);
		mPlayers.push_back(newPlayer);
	}
}

void Game::RunLoop()
{
	using namespace std::literals::chrono_literals;
	int count = 0;
	while (true) // Loop Until program closes.
	{
		// Calling any logic thats needs to run on a separate thread
		if (count == 7) {
			for (int i = 0; i < mPlayers.size(); i++) {
				mTaskManager->Functions.push_back(std::bind(&Player::Attack, *mPlayers[i]));
			}
			mTaskManager->Functions.push_back(std::bind(&Game::PrintPlayerList, *this));
		}

		if (mTaskManager->Functions.size() >= 1) {
			for (int i = 0; i < mTaskManager->Functions.size(); i++) {
				mTaskManager->CreateAndRunThread(mTaskManager->Functions[i]);
			}

			mTaskManager->Functions.clear();
			count = 0;
		}

		//  Any logic Game logic
		std::cout << "\nRunning...\n";
		std::this_thread::sleep_for(1s);

		count++;
	}
}

void Game::PrintPlayerList()
{
	for (int i = 0; i < mPlayers.size(); i++) {
		std::cout << mPlayers[i]->GetName() << ", ";
	}
	std::cout << std::endl;
}

void Game::Shutdown()
{
	// Garbage collection
	for (int i = 0; i < mPlayers.size(); i++) {
		delete mPlayers[i];
		mPlayers[i] = nullptr;
	}

	delete mTaskManager;
	mTaskManager = nullptr;
}
