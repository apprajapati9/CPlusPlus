#include <iostream>

using namespace std;

class Polygon{

    protected : 
        int width, height;
    
    public:
        void set_values( int w, int h){
            width = w;
            height = h;
        }
};

class Rectangle : public Polygon {
    public : 
        int area(){
            return width*height;
        }
};

class Triangle : public Polygon {

    public : 
        int area(){
            return width*height/2;
        }
};

int main(){
    Rectangle rect;
    Triangle tri;
    Polygon * pp = &rect; // pointer to address of rect object
    Polygon * pp2 = &tri; // point to address of tri obj;

    pp->set_values(4,5);
    // equivalent to rect.set_values(4,5)
    pp2->set_values(4,5);
    /// equivalent to tri.set_values(4,5)
    
    cout << rect.area() << endl;
    cout << tri.area() << endl;

    return 0;
}

// news api key - 73a00cce6e954127b9de230c01f32125
// pass news4all