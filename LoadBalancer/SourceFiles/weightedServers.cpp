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

        // if (!serverList.empty()){
        //     serverList.push_back()
        //     server* temp= serverList.at(serverList.size()-1);
        //     temp->nextServer = server;
        // }

        std::cout << "Server "<< serverID << " created with perfromance: "<< performance << "\n";
    }
};

std::vector<server*> serverList;

int main(){

    // Spawn the servers
    server server1 = server(1, 1);
    server server2 = server(2, 0.1);
    server server3 = server(3, 1);
    server server4 = server(4, 1);
    server server5 = server(5, 1);
    server server6 = server(6, 1);
    server server7 = server(7, 1);
    server server8 = server(8, 1);

    serverList.push_back(&server1);
    serverList.push_back(&server2);
    serverList.push_back(&server3);
    serverList.push_back(&server4);
    serverList.push_back(&server5);
    serverList.push_back(&server6);
    serverList.push_back(&server7);
    serverList.push_back(&server8);
    
    float ratio;
    bool isAssigned = false; 

    // Create a while loop to run for fixed amount of time
    int i = 0;
    int j = 0;
    int serverRequests = 0;
    int serverSize = 0;
    while(i < 1E7){
        serverSize = serverList.size();
        if (j > serverSize-1){
            j = 0;
        }
        isAssigned = false;
        
        while (!isAssigned)
        {
            serverRequests = serverList[j]->serverRequests;
            if (serverRequests == 0){
                ratio = 0;
            }
            else{
                ratio = (float)serverRequests / (float)i;
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


