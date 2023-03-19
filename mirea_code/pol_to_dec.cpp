#include <iostream>
#include <math.h>
using namespace std;
void decar (double, double, double*, double*);

int main ()
{
    double D = 1000, P = 3.1415/2., X, Y;
    decar(D, P, &X, &Y);
    cout<<"D= "<< D<<"P= "<< P;
    cout<<"X= "<< X<<"Y= "<< Y;
    return 0;
}
void decar (double p, double d, double* x, double* y);
{
    *x = d*cos(p); *y =  d*sin(p);
}


