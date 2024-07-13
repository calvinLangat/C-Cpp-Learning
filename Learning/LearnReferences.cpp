#include <iostream>
#include <string>

// Function declaration
void myFunction(std::string country = "Norway");
int plusFunc(int x, int y);
float plusFunc(float x, float y);   // Overloading a function. Same name, different return type AS WELL AS different parameter types or numbers.


std::string food = "Pizza";
std::string &meal = food;   // meal references the address of food
std::string* ptr = &meal;   // pointer variable that stores the address of meal. (Will be the same as the address of food)


int main(){

    // std::cout << food << std::endl;
    // std::cout << &food << std::endl;
    // std::cout << meal << std::endl;
    // std::cout << &meal << std::endl;
    std::cout << food << std::endl;
    std::cout << &food << std::endl;// Address of food
    std::cout << meal << std::endl;
    std::cout << &meal<< std::endl; // Address of meal
    std::cout << ptr << std::endl;  // Pointer variable holding the address of meal
    std::cout << &ptr << std::endl; // Address of the pointer
    std::cout << *ptr << std::endl; // Dereferencing the pointer to get the value stored in the address

    *ptr = "Burger";
    std::cout << food << std::endl; // The original value changes when you change the value of the pointer


    myFunction();
    
    return 0;
}

void myFunction(std::string country){    // Default parameter is Normay
    std::cout << country << std::endl;
}

int plusFunc(int x, int y)
{
    return x + y;
}

float plusFunc(float x, float y)
{
    return x + y;
}