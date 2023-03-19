#include<iostream>
#include<math.h>
using namespace std;

class circle
{
public:
    circle();
    circle(double);
    circle(double, double, double);
    void show_circle();
    bool point_in (double, double);
    bool point_on (double, double);
    double square();
    double get_radius();
    void get_center (double* , double* );
private:
    double center_x;
    double center_y;
    double radius;
};

int main()
{
    circle A;
    A.show_circle();
    cout<< A.point_in(0.5,0)<<endl;
    cout<< A.point_on(1,0)<<endl;
    cout<< " square "<< A.square() <<endl;
    cout<< " radius "<< A.get_radius() <<endl;
    double x,y;
    A.get_center( &x, &y);
    circle B (A.get_radius(), x+2, y+3);
    B.show_circle();
    return 0;
}

circle::circle()
{
    radius = 1.;
    center_x = 0.;
    center_y = 0.;
}

circle::circle (double a)
{
    radius = a;
    center_x = 0.;
    center_y = 0.;
}

circle::circle (double a, double x, double y)
{
    radius = a;
    center_x = x;
    center_y = x;
}

void circle::show_circle(void)
{
    cout<< " radius = "<< radius <<endl;
    cout<< " center = "<< center_x <<" "<< center_y <<endl;
}

bool circle::point_in(double ax, double ay)
{
    if ((center_x -ax)*(center_x -ax)+(center_y -ay)*(center_y -ay)<= radius*radius)
        return true;
    return false;
}

double circle::square()
{
    return 3.1415926 * radius * radius;
}

double circle::get_radius()
{ return radius;}

void circle::get_center(double* ox, double * oy)
{
    *ox = center_x; *oy = center_y;
}

bool circle::point_on(double ax, double ay)
{
    if (fabs((center_x -ax)*(center_x -ax)+(center_y -ay)*(center_y -ay) - radius*radius) < 0.001)
        return true;
    return false;
}
