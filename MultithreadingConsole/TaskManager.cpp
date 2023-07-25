#include "TaskManager.h"

void TaskManager::CreateAndRunThread(std::function<void()> func)
{
	Threads.push_back(std::thread(func));
}
