#include <iostream>

using namespace std;

/*
lerp = a b 
diff between a and b is kinda like a distance and then interpolate value from 0 to 1
a=0, b = 1  l=0 ===> a-b * l  =  0-1= 1 * 0 = 0
a=0, b = 1, l=1 ===> a-b * l = 0-1 * 1 = 1

a=0, b = 1, l=0.5 ===> a-b * l = 0-1 * 0.5 = 0.5 

constraints here -> b > a 
*/

struct Vec2 {
    float x;
    float y;
};

Vec2* vec2(float x, float y){
    return new Vec2{x, y};
}

Vec2 vec2Stack(float x, float y){
    // Vec2 v2;
    // v2.x = x;
    // v2.y = y;
    // return v2;
    return Vec2{x, y};
}

//find the difference
Vec2 sub(Vec2 v1, Vec2 v2) {
    return vec2Stack (v2.x - v1.x, v2.y - v1.y); 
}

Vec2 add(Vec2 v1, Vec2 v2) {
    return vec2Stack(v1.x + v2.x, v1.y + v2.y);
}

Vec2 scale(Vec2 v1, float scale){
    return vec2Stack(v1.x * scale, v1.y * scale);
}

Vec2 lerpV(Vec2 begin, Vec2 end, float l)
{
    cout << "inside lerp" << endl;
    return add(begin, scale(sub(begin, end), l)); // lerp function for Vector 
}

float lerp(float a, float b, float l)
{
    return a + (b - a) * l;
}

int main(){

    //simple lerp function
    float lv = lerp(0, 1, 0.50);
    cout << "lerp of float " << lv << endl;

    // lerp for  X, Y coordinate Vector to interpolate between 2 points on a 2d space.
    Vec2 begin = vec2Stack(1, 2); //point begin
    Vec2 end = vec2Stack(2, 3); // point end

    Vec2 v2 = vec2Stack(1, 1);

    Vec2 distance = sub(begin, end);
    //cout << distance.x << " " << distance.y << endl;
    
    Vec2 lerpV2 = lerpV(begin, end, 0);
    cout << lerpV2.x << " " << lerpV2.y << endl;
    return 0;
}