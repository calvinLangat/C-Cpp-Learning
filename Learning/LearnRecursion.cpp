#include <iostream>

int sum(int x);


int main(){
    std::cout << sum(100) << std::endl;
    return 0;
}

int sum(int x){
    if (x > 0){
        return x + sum(x - 1);
    }
    else{
        return 0;
    }
}