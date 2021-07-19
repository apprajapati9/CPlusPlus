
#include<iostream>

using namespace std;


/*
This function uses pass by pointer which greatly reduces the code
since it can directly point to the variable by pointer, and removing the need to duplicate variables
*/
int gcdBySubstraction(int* num1, int* num2){
    int gcd = 0;

    if(*num1 == *num2){
        gcd = *num1;
    }

    while(*num1 != *num2){
        if(*num1 > *num2){
            *num1 = *num1 - *num2;
            gcd = *num1;
        }else{
            *num2 = *num2 - *num1;
            gcd = *num2;
        }
    }

    return gcd;
}

int passbyReferenceGCD(int& num1, int& num2){
    int gcd = 0;

    if(num1 == num2){
        gcd = num1;
    }

    while(num1 != num2){
        if(num1 > num2){
            num1 = num1 - num2;
            gcd = num1;
        }else{
            num2 = num2 - num1;
            gcd = num2;
        }
    }

    return gcd;
    
}

int gcdCalculator (int num1,int num2){
    int gcd = 0;
    int high, low;
    int remainder;

    if(num1 > num2){
        high = num1;
        low = num2;
    }else{
        high = num2;
        low = num1;
    }


    do{
        remainder = high % low;
        //rememember modulo sequence = high % low = high devided by low
        high = low;
        low = remainder;

        if(remainder != 0){
            gcd = remainder;
        }else{
            gcd = high;
        }

    }while(remainder != 0);

    return gcd;
}



int main(){

    int num1, num2;
    int gcd = 0;
    std::cout << "Enter num1" <<endl;
    std::cin >> num1;

    std::cout << "Enter num2" << endl; 
    std::cin >> num2;

    std::cout << "Entered " <<num1 << " and " << num2 <<endl;

    //gcd = gcd(num1, num2);

    std::cout << "GCD = " << gcdCalculator(num1, num2) << endl;
    std::cout << "GCD by Substraction = " << gcdBySubstraction(&num1, &num2) << endl;
    
    std::cout << "GCD by PassbyRefGCD = " << passbyReferenceGCD(num1, num2) << endl;

    
}



