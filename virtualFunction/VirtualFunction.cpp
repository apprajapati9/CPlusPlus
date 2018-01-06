#include <iostream>

using namespace std;

class Polygon{

    protected :
        int w, h; //width , height
    
    public : 
        void set_values(int a , int b){
            w = a;
            h = b;
        }
        virtual int area(){
            return 0;
        }
};

class Rectangle : public Polygon{
    public :
        int area(){
            return w*h;
        }

};

class Traingle : public Polygon{
    public :
        int area(){
            return (w*h/2);
        }
};

int main(){
    Rectangle rect;
    Traingle tri;

    Polygon poly;
    
    Polygon *p1 = &rect;
    Polygon *p2 = &tri;
    Polygon *p3 = &poly;

    p1->set_values(4, 5);
    p2->set_values(4, 5);
    p3->set_values(4, 5);

    cout << p1->area() << endl;
    cout << p2->area() << endl;
    cout << p3->area() << endl;

    return 0;
}

/*
In this example, all three classes (Polygon, Rectangle and Triangle) 
have the same members: width, height,
 and functions set_values and area.

The member function area has been declared as virtual
 in the base class because it is later redefined in each
of the derived classes. Non-virtual members can also be
redefined in derived classes, but non-virtual members
of derived classes cannot be accessed through a reference of the base class: 

i.e., if virtual is removed from the declaration of area in the example above, 
all three calls to area would return zero, because in all cases, the version of the base class would have been called instead.

Therefore, essentially, what the virtual keyword does is to allow a member of a
 derived class with the same name as one in the base class to be appropriately called 
 from a pointer, and more precisely when the type of the pointer is a pointer
  to the base class that is pointing to an object of the derived class, as in the above example.

A class that declares or inherits a virtual function is called a polymorphic class.

Note that despite of the virtuality of one of its members, Polygon was a regular class, 
of which even an object was instantiated (poly), with its own definition of member area that always returns 0.
*/