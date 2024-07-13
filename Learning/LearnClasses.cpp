#include <iostream>

class MyClass {         // The class
    public:             // Access Specifier
        int myNum;      // Attribute
        std::string myString;
        MyClass(){      // Constructor - the same name as the class with parenthesis ( It is always public and it does not have any return value).
            std::cout << "Class Created!" << std::endl;
        }
        void myMethod(){               // Inside class method definition
            std::cout << "Hello World!" << std::endl;
        }
        void myMethodOutside();
};
void MyClass::myMethodOutside(){
    std::cout << "Hello Outside World!" << std::endl;
}

class vehice {
    public:
        std::string Make;
        std::string Model;
        int Year;

        vehice(std::string x, std::string y, int z);
};

vehice::vehice(std::string x, std::string y, int z){
            Make = x;
            Model = y;
            Year = z;
            std::cout << "Vehicle: \"" << Make << "\" Created"<<std::endl;
        }

class animals {
    private:
    // Cannot be accessed outside the class
        std::string classification;
        std::string foodChainType;
    
    protected:
    // Only accessible from inherited class
        std::string foodType;
    
    public:
    // Setter
        void setClassification(std::string x){
            classification = x;
        }
        void setFoodChainType(std::string x){
            foodChainType = x;
        }
        void setfoodType(std::string x){
            foodType = x;
        }

    // Getter
        std::string getClassification(){
            return classification;
        }
        std::string getFoodChainType(){
            return foodChainType;
        }
        std::string getFoodType(){
            return foodType;
        }
};

int main(){

    MyClass myObj;  // Create an oobject of MyClass

    // Access attributes and set values
    myObj.myNum = 10;
    myObj.myString = "Ten";

    std::cout << myObj.myNum << std::endl;
    std::cout << myObj.myString << "\n";

    vehice car1("Mitsubishi","Lancer",2004), car2("Subaru","Impreza",2005);

    std::cout << car1.Model << std::endl;
    std::cout << car2.Model << std::endl;
    
    myObj.myMethod();
    myObj.myMethodOutside();

    animals dog;
    dog.setClassification("Mammal");
    dog.setClassification("Predator");
    std::cout << dog.getClassification() << std::endl;

    // Inheritance
    class improvedAnimal: public animals{
        private:
            std::string sound;
        public:
            void setSound(std::string x){
                sound = x;
            }
            std::string getSound(){
                return sound;
            }
    };

    improvedAnimal dog2;
    dog2.setSound("Bark!");
    dog2.setfoodType("Meat & Bones");
    std::cout << dog2.getSound() << std::endl;
    std::cout << dog2.getFoodType() << std::endl;

    // Multilevel inheritance
    class abomination: public animals, public vehice{
    };

    //abomination frankenstein;
    return 0;
}