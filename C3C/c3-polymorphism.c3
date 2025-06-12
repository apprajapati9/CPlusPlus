import std::io;
import std::collections::list;

interface Shape {
	fn String name();
}

struct Circle(Shape){
float rad;
}

struct Rect(Shape){
float w,h;
}

fn String Rect.name(&self) @dynamic {
return "rect from ajay";
}

fn String Circle.name(&self) @dynamic {
        return "ajay from name";
}

fn void main(){
   //io::print("ajay");

Circle c = (Circle){.rad = 99};
Rect r = (Rect){.w = 99, .h = 99};
List{Shape} shapes;
shapes.push(&c);
shapes.push(&r);

foreach (Shape s : shapes){
io::printfn("%s", s.name());
}
 
}

// c3c compile-run FILENAME -o FILENAME 
