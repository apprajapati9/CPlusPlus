#include <iostream>

using namespace std;

void printCharArray(char* str){ //*str = A, str pointer address passed here.
    
    //to understand what deref means, str = full string, pionter to *Str =  str[0]
    
    *str = str[1]; 
    // Assings AJAY,J to Str[0] which is what *str means. *str = str[0] = J J A Y
    
    str[0] = str[3]; 
    // would be same result  Y J A Y. 

    *str = 'A';  // A J A Y , means *Str always points to first element.

    *(str+1) = 'A'; // A A A Y

    *(str + 1) = 'M'; //A M A Y

    //above statements manipulates string/char provided in str.
    cout << "Final string in PrintCharArray() = " << str << endl;

    // Print statements to understand ref / deref.
    cout << "Just str = " << str << endl; // Full string...AJAY
    cout << "Deref str= *str = " << *str << endl; 
    cout << "str[1] = " << str[1] << endl;
    //cout << "*str[1] = " << *str[1] << endl; // ERROR: Deref on single char doesnt work.
    cout << "*(str+1) = " << *(str+1) << endl;
    cout << "*(str) = " << *(str) << endl; 
    cout << "str+1 = " << str+1 << endl; //str=[0] + 1 = 1 , so starts with 1 JAY, rather than AJAY
    cout << "str+3 = " << str + 3 << endl;
    /*
    //1st way
    int i = 0;
    while (str[i] != '\0'){ // *(str+i) != '\0' would work as well.
        cout << str[i] << endl;
        i++;
    }
    */
   int i = 0;
   while(str[i] != '\0' ){ 
        //while(str != "\0") 
        // str = AJAY, full string that's why need double quote.
        //str[i] becomes specific on char, so need single quote.
       
        //cout << str+i << endl; //AJAY+0=AJAY, AJAY+1=JAY, ... AY .. Y
       
        cout << *(str+i) << endl; // prints A, J, ... A.. Y
        str++; //str itself points to str[0], str+1 = JAY instead of AJAY
    }

    //works below example too. 
    // while (*str != '\0'){  //deref so A, J, A Y  will come 
    //     cout << *str << endl; 
    //     str++; // str has add value, so address++ will move on to next char address.
    // }
}

void pointer_to_p_str(char **str){

}

int main(){
    char c[5];
    c[0] = 'A';
    c[1] = 'J';
    c[2] = 'A';
    c[3] = 'Y';
    c[4] = '\0';
    cout << "C= " << c << endl; 
    /* when you don't end string with \0 null character, 
    it will print undesirable values in output for example mine was = AJAY▒@  chars,
    so always have string null terminated. */

    //below syntax already uses null termination automatically
    char c2[] = "AJAY";
    //cout << "C2= " << c2 << endl; //Null char isn't counted in length.

    //
    printCharArray(c2); // c2[0] address is passed, pass by ref by default for array
    /*
    when you do = char *c2 = "AJAY"; 
    throws below warning: 
    warning: ISO C++ forbids converting a string constant to 'char*' [-Wwrite-strings]
     char *c2 = "AJAY";
    
    warning can be ignored but they give you important information so follow that n remember.
    */
}