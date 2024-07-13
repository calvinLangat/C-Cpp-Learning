#include <iostream>
#include <string>
#include <vector>


class server{
public:
    // Members
    int serverID;
    int serverRequests = 0;
    float performance = 1;

public:
    // Constructor
    server(int serverID, int performance){
        this->serverID = serverID;
        this->performance = performance; 
        std::cout << "Server "<< serverID << " created with perfromance: "<< performance << "\n";
    }
};

int main(){

    // Spawn the servers
    server server1 = server(1,1);
    server server2 = server(2,0.5);
    server server3 = server(3,1);
    server server4 = server(4,1);


    std::vector<server*> serverList;
    serverList.push_back(&server1);
    serverList.push_back(&server2);
    serverList.push_back(&server3);
    serverList.push_back(&server4);
    
    
    // Create a while loop to run for fixed amount of time
    int j = 0;
    int i = 0;
    while(i < 1E6){
        
       // Restart the round robin loop
        if (i%4 == 0){
            j = 0;
        }

        // assign increment counters to servers to simulate allocated tasks
        else{
            i++;
            j++;
            continue;
        }
        
        j++;
        i++;
    }

    for (auto k:serverList){
        std::cout << "Server "<< k->serverID << " requests: "<< k->serverRequests << "\n";
    }

    return 0;
}