#include <iostream>
#include <string>
#include <vector>
class server{
public:
    // Members
    int serverID;
    int serverRequests = 0;

public:
    // Constructor
    server(int serverID){
        this->serverID= serverID;
        std::cout << "Server "<< serverID << " created\n";
    }
};

int main(){

    // Spawn the servers
    server server1 = server(1);
    server server2 = server(2);
    server server3 = server(3);
    server server4 = server(4);

    std::vector<server*> serverNum;
    serverNum.push_back(&server1);
    serverNum.push_back(&server2);
    serverNum.push_back(&server3);
    serverNum.push_back(&server4);
    
    
    // Create a while loop to run for fixed amount of time
    int j = 0;
    int i = 0;
    while(i < 1E6){
        // assign increment counters to servers to simulate allocated tasks
       
        if (i%4 == 0){
            j = 0;
        }

        serverNum[j]->serverRequests +=1;
        
        j++;
        i++;
    }

    for (auto k:serverNum){
        std::cout << "Server "<< k->serverID << " requests: "<< k->serverRequests << "\n";
    }

    return 0;
}