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
        void insertItesm(int key, std::string value);
        void removeItem(int key);
        std::string searchTable(int key);
        void printTable();
};