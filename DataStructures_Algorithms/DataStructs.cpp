#include <iostream>
#include <math.h>

// Function declaration
void digitSum(int x);
int countDigit(int x);

int main(){
    int digits = 67899;
    digitSum(digits);
    return 0;
}

// Function definition
void digitSum(int x){
    
    int sum = 0;
    int len = countDigit(x);
    for(int i=0; i<len; ++i){
        sum += (x % 10);
        x /= 10;
    }
    printf("%d \n",sum);
}

int countDigit(int x){
    if (x == 0){
        return 1;
    }

    int count = 0;
    while (x > 1){
        x = x / 10;
        ++count;
    }
    return count;
}