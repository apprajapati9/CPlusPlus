#include <iostream>

using namespace std;

/*
Abstract base classes are something very similar to the Polygon class in the previous example.
 They are classes that can only be used as base classes, and thus are allowed to have virtual 
 member functions without definition (known as pure virtual functions). 
 The syntax is to replace their definition by =0 (an equal sign and a zero):
*/

// Classes that contain at least one pure virtual function are known as abstract base classes.

class Polygon{ //abstract base class
    protected :
        int w, h; 
    
    public: 
        void set_values (int a, int b){
            w = a;
            h = b;
        }

        virtual int area( void ) = 0;  // pure virtual function
        // this means that you have to implement this function if you derived from polygon class
};

class Rectangle: public Polygon {
  public:
    int area (void)
      { return (w * h); }
};

class Triangle: public Polygon {
  public:
    int area (void)
      { return (w * h / 2); }
};

int main () {
  Rectangle rect;
  Triangle trgl;
  Polygon * ppoly1 = &rect;
  Polygon * ppoly2 = &trgl;
  ppoly1->set_values (4,5);
  ppoly2->set_values (4,5);
  cout << ppoly1->area() << '\n';
  cout << ppoly2->area() << '\n';
  return 0;
}