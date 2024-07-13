#include <iostream>
#include <string>
#include <thread>

static bool isFinished = false;

int count(){
    while(!isFinished){
        std::cout << "Working...\n";
    }
}

int main(){
    std::thread worker(count);
    std::cin.get();
    isFinished = true;

    worker.join();

    return 0;
}