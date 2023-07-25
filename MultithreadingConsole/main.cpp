#include <iostream>
#include <vector>
#include <thread>
#include <functional>

using namespace std::literals::chrono_literals;
std::vector<std::function<void()>> Functions;
std::vector<std::thread> Threads;

void perfromAction() {
    std::this_thread::sleep_for(3s);
    std::cout << "Perfrom action" << std::endl;
}

void printSomeThings() {
    std::vector<const char*> things = {"Cat", "dog", "float", "boat"};

    for (int i = 0; i < things.size(); i++) {
        std::cout << things[i] << ", ";
    }
    std::cout << std::endl;
}

void CreateAndRunThread(std::function<void()> func) {
    Threads.push_back(std::thread(func));
}

int main()
{
    int count = 0;
    while (true)
    {
        if (count == 10) {
            Functions.push_back(perfromAction);
            Functions.push_back(printSomeThings);
        }
        if (Functions.size() >= 1) {
            for (int i = 0; i < Functions.size(); i++) {
                CreateAndRunThread(Functions[i]);
            }
            Functions.clear();
        }
        std::cout << "\nMain Loop\n";
        std::this_thread::sleep_for(1s);

        count++;
    }
}
