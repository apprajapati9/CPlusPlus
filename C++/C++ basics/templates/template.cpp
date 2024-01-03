#include <iostream>

using namespace std;

template<class T>
class Math{
    private:
        T a;
        T b;
    public:
        Math(T a, T b);
        T add();
        T sub();
};

template<class T>
Math<T>::Math(T a, T b){
    this->a = a;
    this->b = b;
}

template<class T>
T Math<T>::add(){
    return this->a + this->b;
}

template<class T>
T Math<T>::sub(){
    return a - b;
}

int main(){
    Math<float> m(10.0, 5);

    cout << "add - " << m.add() << endl;
    cout << "sub - " << m.sub() << endl;
    return 0;
}
