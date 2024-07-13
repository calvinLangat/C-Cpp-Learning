#include <iostream>
#include <string>

void declareStruct(void){
    struct {
        int myNum;
        std::string myString;
    } myStructure1, myStructure2, myStructure3;

    myStructure1.myNum = 10;
    myStructure1.myString = "Ten";

    //std::cout << myStructure1.myNum << std::endl;
    //std::cout << myStructure1.myString << std::endl;

    struct car{
        std::string Make;
        std::string Model;
        int Year;
    };

    car myCar;
    myCar.Make = "Mitsubishi";
    myCar.Model = "Lancer";
    myCar.Year = 2004;

    std::cout << myCar.Make << std::endl;

}

void createEnum(void){
    enum level {
        LOW,
        MEDIUM,
        HIGH
    };

    enum level myVar = MEDIUM;
    std::cout << myVar << std::endl;
}

int main(){
    //declareStruct();
    createEnum();
    return 0;
}