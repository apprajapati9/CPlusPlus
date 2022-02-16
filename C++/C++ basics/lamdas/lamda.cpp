#include<iostream>
#include <functional>

using namespace std;


class Ajay{
    int a = 5;
    int b = 10;
    
    public:
    int sum(){
        return [this](){
            return this->a + this->b;
        }();
    }
};

//also using template
template<int aVal, int bVal>
class Ajay2{
    int a = aVal;
    int b = bVal;
    
    public:
    int sum(){
        return [this](){
            return this->a + this->b;
        }();
    }
};

void classLamdaFun(){
    Ajay a1;
    cout <<a1.sum() << endl;
    
    //using template
    Ajay2<10, 10> a2;
    cout << a2.sum() <<endl;
}

void printValue(int val){
    cout << val << endl;
}

void basicsOfLamda(){
    // simples form of lamda function 
    [] () {
        std::cout << "Ajay" << endl;
    }(); 

    //to specify return type 
    int returnedValue = [] () -> int {
        return 100;
    }();
    cout << returnedValue << endl;

    //to feed parameter to lamda function
    returnedValue = [] (int value) ->int {
        return value * 100;
    }(2); 
    cout << returnedValue << endl;

    //function pointer to fetch results of lamda function
    //have to include header file <functional> in order to work

    //function <returnType(param_args_values)> fp = 
    std::function<int(int)> fp = [] (int value) -> int {
        return value * 200;
    };

    returnedValue = fp(2);
    cout << returnedValue << endl;

}

void lamdaFunctions() {
    //f(x) = x*x
    std::function<int(int)> fp = [] (int x) -> int {
        return x*x;
    };

    printValue(fp(22));


    //f(x, y) = x2 + y2 + 2xy;
    //using modular approach by nested lamda function 
    std::function<int(int, int)> fp2 = [] (int x, int y) -> int {
        int xsquare = [] (int x) ->int {
            return x*x;
        }(x); //calling with passed x of fp2

        int ysquare = [] (int y) -> int {
            return y*y;
        }(y);

        int twoxy = [] (int x, int y) -> int {
            return 2 * x * y;
        }(x, y);

        return xsquare + ysquare + twoxy; //x2 + y2 + 2xy
    };

    printValue(fp2(5,3));

}

// use of capture list is to pass variable value that existed outside of function
void lamdaCaptureList(){
    string localvar = "captureList";
    int localval = 3;
    std::function<int(int)> fp = [localvar, localval] (int x) -> int {
        cout << localvar << endl; //access var using [] of lamda
        
        //capture list also honors the immutability, so value cannot be changed inside.
        // doing localval++ would throw : error: increment of read-only variable ‘localval’
        //by default it is immutable and cannot be changed.
        cout << localval <<endl; 

        //if you want to change value of capture list, you can do so by passing address
        // [&localval]
        //after that localval++ will not throw error, but changes here will be applied to the variable within it's scope.
        return x*x;
    };

    printValue(fp(22));


    int x = 5, y = 3;
    std::function<int(void)> fp3 = [x, y] ()  {
        int xsquare = [x] () ->int {
            return x*x;
        }(); //no need to pass any value bcz of x gotten from []

        int ysquare = [y] () -> int {
            return y*y;
        }();

        int twoxy = [x,y] () -> int {
            return 2 * x * y;
        }();

        return xsquare + ysquare + twoxy; //x2 + y2 + 2xy
    };
    printValue(fp3()); //without passing value while calling due to values fetched by capture list.

    //PRO TIP: [=] - if you have many variable. = will enable access to all local variable in lamda function [] capture list.   
    // [=] - pass local variable by value
    // [&] - pass all local variable by reference
    // = is better because it will not allow change of variable outside of the scope. 
    
}


int main(){

    basicsOfLamda();
    
    lamdaFunctions();

    lamdaCaptureList();

    classLamdaFun();

    return 0;
}