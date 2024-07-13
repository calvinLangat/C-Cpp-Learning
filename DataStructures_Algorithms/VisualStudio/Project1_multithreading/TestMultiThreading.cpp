#include <iostream>
#include <string>
#include <thread>

static bool isFinished = false;

void count() {

    using namespace std::literals::chrono_literals;
    std::cout << "spawning thread ID: " << std::this_thread::get_id() << "\n";
    while (!isFinished) {
        std::cout << "Working...\n";
        std::this_thread::sleep_for(1s);
    }
}

int main() {
    std::cout << "This is the main thread ID: " << std::this_thread::get_id() << "\n";
    std::thread worker(count);
    std::cin.get();
    isFinished = true;

    worker.join();
    std::cin.get();
    return 0;
}