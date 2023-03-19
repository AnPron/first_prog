#include <iostream>
#include <math.h>
using namespace std;
void sfera (double, double, double*, double*);

int main ()
{
    double D, P, X = 1000., Y = -1000.0;
    sfera (X,Y, &D, &P);
    cout<<"X= "<< X<<"Y= "<< Y;
    cout<<"D= "<< D<<"P= "<< P;
    return 0;
}
void sfera (double x, double y, double* d, double* p)
{
    *d = sqrt(x*x+y*y); *p = atan2(x,y);
}


