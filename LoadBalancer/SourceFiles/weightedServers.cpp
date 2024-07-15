#include <iostream>
#include <string>
#include <vector>

void createServer();


class server{
public:
    // Members
    int serverID;
    int serverRequests = 0;
    float performance = 1;
    server* nextServer = nullptr;

public:
    // Constructor
    server(int serverID, float performance){
        this->serverID = serverID;
        this->performance = performance;
        std::cout << "Server "<< serverID << " created with perfromance: "<< performance << "\n";
    }
};

std::vector<server*> serverList;

int main(){

    // Spawn the servers
    server server1 = server(1, 0.35);
    server server2 = server(2, 0.5);
    server server3 = server(3, 0.15);
    server server4 = server(4, 0.4);
    server server5 = server(5, 0.3);
    server server6 = server(6, 0.05);
    server server7 = server(7, 0.8);
    server server8 = server(8, 0.2);

    serverList.push_back(&server1);
    serverList.push_back(&server2);
    serverList.push_back(&server3);
    // serverList.push_back(&server4);
    // serverList.push_back(&server5);
    // serverList.push_back(&server6);
    // serverList.push_back(&server7);
    // serverList.push_back(&server8);
    
    float ratio;
    bool isAssigned = false; 

    // Create a while loop to run for fixed amount of time
    int i = 0;
    int j = 0;
    int serverRequests = 0;
    int serverSize = 0;
    while(i < 1E8){
        isAssigned = false;
        serverSize = serverList.size();
        
        if (j > serverSize-1){
            j = 0;
        }
        
        while (!isAssigned)
        {
            serverRequests = serverList[j]->serverRequests;
            
            if (serverRequests == 0){
                ratio = 0;
            }
            else{
                ratio = (float)serverRequests / i;   // Cast from integer to float
            }
            
            if (ratio - serverList[j]->performance <= 0){
                serverList[j]->serverRequests += 1;
                isAssigned = true;
                break;
            }
            else{
                j++;
                if (j>serverSize-1){
                    j = 0;
                }

            }
        }

        j++;
        i++;
    }

    for (const auto& k:serverList){
        std::cout << "Server "<< k->serverID << " requests: "<< k->serverRequests << "\n";
    }

    return 0;
}


