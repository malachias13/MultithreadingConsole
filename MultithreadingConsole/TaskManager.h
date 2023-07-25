#pragma once
#include <functional>
#include <vector>
#include <thread>

class TaskManager
{
public:
	std::vector<std::function<void()>> Functions;
	std::vector<std::thread> Threads;

	void CreateAndRunThread(std::function<void()> func);

};

