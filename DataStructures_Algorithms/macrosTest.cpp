#include <iostream>
#include <string.h>

#define DEBUG 0
#define string std::string
#if DEBUG
    #define LOG(x) std::cout<<x<<"\n"
#else
    #define LOG(x) 
#endif


class Robot {
public:
   string name;
   string color;
   int weight;
   Robot* lookingAt;

   Robot(string name, string color, int weight, Robot* lookingAt){
    this->name = name;
    this->color = color;
    this->weight = weight;
    this->lookingAt = lookingAt;
   }

};

class Person{
public:
    string name;
    string personality;
    bool isSitting;
    Robot* robotOwned;
    void sitDown(){
        this->isSitting = true;

    }
    void standUp(){
        isSitting = false;
    }

    Person(string name, string personality, bool isSitting,Robot* robotOwned){
        this->name = name;
        this->personality = personality;
        this->isSitting = isSitting;
        this->robotOwned = robotOwned;
    }
};

int main(){

    LOG("Hi\n");
    Robot r1 = Robot("Tom","Red",50,NULL);               // Created in Stack, will be deleted automatically
    Robot* ptr_r1 = &r1;
    Robot* r2 = new Robot("Jerry","Blue",40,ptr_r1);       // Created in Heap, will need to be deleted manually

    std::cout << "My name is "<< r1.name<< "\n";
    std::cout << r2->name<<"'s color is "<< r2->color<< "\n";

    Person* p1 = new Person("Alice","aggressive",false,r2);
    //Person* p2 = new Person("Becky","talkative",true,r1);

    std::cout << p1->name <<" owns "<<p1->robotOwned->name << "\n";
    std::cout << "The size of class "<< r1.name << " is " << sizeof(r1.name) << "\n";
    std::cout << "The memory address of " << r1.name << " is " << &r1.name <<"\n";
    std::cout << "The memory address of " << r1.color << " is " << &r1.color <<"\n";
    std::cout << "The memory address of " << r2->name << " is " << &r2->name <<"\n";
    std::cout << r2->name << " is looking at " << r2->lookingAt->name << "\n";
    delete r2;              // Remove from Heap
    return 0;
}