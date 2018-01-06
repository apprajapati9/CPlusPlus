#include <iostream> 

using namespace std;

class Person {

    public :
        //Person();
        //Person(string n, int a);
        virtual void getdata()=0; // always remember to have blank function body for virutal functions
        virtual void putdata()=0; // =0 or {} empty bracket both works
    
    protected : 
        string name;
        int age;
        //static int id;

};

class Professor : public Person{

    public : 
    
        Professor() {
            //id++;
        }    
        void getdata() {
            cin >> name;
            cin >> age;
            cin >> publications;
        } 

        void putdata(){
            cout << name << endl;
            cout << age << endl;
            cout << publications << endl;
            cout << cur_id;
        }

    private :
        int publications;
        int cur_id;
};

class Student : public Person{

    public :
        Student(){
            //id++;
        }
        int sum; 
        void getdata(){
            cin >> name;
            cin >> age;

            int size = sizeof(marks)/sizeof(marks[0]);
            
            for ( int i =0 ; i < size; i++){
                sum += marks[i];
            }
        }

        void putdata(){
            cout << name;
            cout << age;
            int size = sizeof(marks)/sizeof(marks[0]);
            //cout << "size" << size;
            for ( int i =0 ; i < size; i++){
                sum += marks[i];
            }
            cout << sum;
            cout << cur_id;
        
        }

    private: 
        int marks[6];
        int cur_id;

};


int main(){
    int n, val;

    cin >> n ; // the number of objects that is going to be created.

    Person *per[n]; //memory address of n objects of Person

    for( int i = 0; i < n; i++ ) {
        cin >> val;

        if( val == 1){
            //if val is 1 current object is type Professor
              per[i] = new Professor;
        }else{
             per[i] = new Student;
        }

        per[i]->getdata(); //get the data from the user
    }

    for(int i =0; i < n; i++){
        per[i]->putdata(); // print the required output for each object
    }

    return 0;

}