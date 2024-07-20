#include <iostream>
#include <string>
#include <vector>

void createServer(int ID, float performance);
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

std::vector<server> serverList;

int main(){

    // Spawn the servers
    createServer(1, 0.35);
    createServer(2, 0.5);
    createServer(3, 0.15);
    createServer(4, 0.4);
    createServer(5, 0.3);
    createServer(6, 0.05);
    createServer(7, 0.8);
    createServer(8, 0.2);
    
    float ratio;
    bool isAssigned = false; 

    // Create a while loop to run for fixed amount of time
    int i = 0;
    int j = 0;
    int serverRequests = 0;
    int serverSize = 0;

    while(i < 1E4){
        isAssigned = false;
        serverSize = serverList.size();
        
        if (j > serverSize-1){
            j = 0;
        }
        
        while (!isAssigned)
        {
            serverRequests = serverList[j].serverRequests;
            
            if (serverRequests == 0){
                ratio = 0;
            }
            else{
                ratio = (float)serverRequests / i;   // Cast from integer to float
            }
            
            if (ratio - serverList[j].performance <= 0){
                serverList[j].serverRequests += 1;
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
        std::cout << "Server "<< k.serverID << " requests: "<< k.serverRequests << "\n";
    }

    return 0;
}

void createServer(int ID, float performance)
{
    server server1 = server(ID, performance);
     serverList.push_back(server1);
}
