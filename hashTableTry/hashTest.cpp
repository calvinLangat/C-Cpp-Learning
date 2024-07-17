#include<iostream>
#include<string>
#include<list>

class HashTable{
    private:
        static const int hashGroups = 10;
        std::list<std::pair<int, std::string>> table[hashGroups];

    public:
        bool isEmpty() const;
        int hashFunction(int Key);
        void insertItem(int key, std::string value);
        void removeItem(int key);
        std::string searchTable(int key);
        void printTable();
};

bool HashTable::isEmpty() const {
    int sum{};
    for (int i{}; i < hashGroups; i++){
        sum += table[i].size();
    }

    if (!sum){
        return true;
    }
    return false;
}

int HashTable::hashFunction(int key){
    return key % hashGroups; // Key: 905, in return, this function will return 5.
}

void HashTable::insertItem(int key, std::string value){
    int hashValue = hashFunction(key);
    auto& cell = table[hashValue];
    auto bItr= begin(cell);
    bool keyExists = false;
    for (; bItr !=end(cell); bItr++){
        if (bItr->first == key){
            keyExists = true;
            bItr->second = value;
            std::cout << "[WARNING] Key exists. Value replaced.\n";
            break;
        }
    }

    if (!keyExists){
        cell.emplace_back(key, value);
    }

    return;
}

void HashTable::removeItem(int key){
    int hashValue = hashFunction(key);
    auto& cell = table[hashValue];
    auto bItr= begin(cell);
    bool keyExists = false;
    for (; bItr !=end(cell); bItr++){
        if (bItr->first == key){
            keyExists = true;
            bItr = cell.erase(bItr);
            std::cout << "[INFO] Item removed.\n";
            break;
        }
    }

    if (!keyExists){
        std::cout << "[WARNING] Key not found. Pair not removed.\n";
    }

    return;
}

void HashTable::printTable(){
    for(int i{};i<hashGroups;i++){
        if(table[i].size() == 0) continue;

        auto bItr = table[i].begin();
        for(; bItr != table[i].end(); bItr++){
            std::cout << "[INFO] Key: " << bItr->first << " Value: " << bItr->second << "\n";
        }
    }
    return;
}