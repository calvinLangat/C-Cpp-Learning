#include <iostream>
#include <string>
#include <vector>

void createServer();

std::vector<server*> serverList;

class server{
public:
    // Members
    int serverID;
    int serverRequests = 0;
    float performance = 1;
    server* nextServer = nullptr;

public:
    // Constructor
    server(int serverID, int performance){
        this->serverID = serverID;
        this->performance = performance;

        // if (!serverList.empty()){
        //     serverList.push_back()
        //     server* temp= serverList.at(serverList.size()-1);
        //     temp->nextServer = server;
        // }

        std::cout << "Server "<< serverID << " created with perfromance: "<< performance << "\n";
    }
};

int main(){

    // Spawn the servers
    
    
    
    // Create a while loop to run for fixed amount of time
    int i = 0;
    while(i < 1E6){
        

        i++;
    }

    for (const auto& k:serverList){
        //std::cout << "Server "<< k << " requests: "<< k << "\n";
    }

    return 0;
}


