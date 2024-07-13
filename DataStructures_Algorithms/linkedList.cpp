#include <iostream>

class Node;
class linkedList;
int countNodes(Node Head);


int main(){
    Node nodeA = Node(6);
    Node nodeB = Node(3);
    Node nodeC = Node(4);
    Node nodeD = Node(2);
    Node nodeE = Node(1);

    nodeA.next = &nodeB;
    nodeB.next = &nodeC;
    nodeB.prev = &nodeA;
    nodeC.next = &nodeD;
    nodeC.prev = &nodeB;
    nodeD.next = &nodeE;
    nodeD.prev = &nodeC;
    nodeE.prev = &nodeD;

    std::cout << "The number of nodes is: " << countNodes(nodeA) << "\n";
    return 0;
}


class Node{
public:
    int data;
    Node* next;
    Node* prev;

    Node(int data){
        this->data = data;
        this->next = nullptr;
        this->prev = nullptr;
    }
};

class linkedList{
public:
};

int countNodes(Node Head){
    Node* j = &Head;
    int i = 1;
    while(j->next != nullptr){
        i++;
        j = j->next;
    }
    return i;
}