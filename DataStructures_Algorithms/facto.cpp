#include<iostream>

long factori(long n);
int fibonacci(int n);

int main(){
    int n = 4;
    std::cout << "Factorial: " << factori(10) << "\n";
    std::cout << "The " << n << "th number of fibonacci is " << fibonacci(n) << "\n"; 
    return 0;
}

long factori(long n){
    if (n>=1){
        return n * factori(n-1);
    }
    else{
        return 1;
    }
}

int fibonacci(int n){
    if (n>=3){
        return fibonacci(n-1) + fibonacci(n-2);
    }
    else{
        return 1;
    }
}