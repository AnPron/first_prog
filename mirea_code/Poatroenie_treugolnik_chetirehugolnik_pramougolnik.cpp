#include<iostream>
#include<math.h>
using namespace std;

class triangle
{
public:
    triangle(double, double, double, double, double, double);
    void show_triangle();
    bool point_in (double, double);
    double square();
    void get_apexes (double [2], double [2], double [2]);
private:
    double apex_A[2];
    double apex_B[2];
    double apex_C[2];
};

class quadri
{
public:
    quadri();
    quadri(double, double, double, double, double, double, double, double);
    void assign_quadri (double, double, double, double, double, double, double, double);
    void show_quadri();
    double square();
protected:
    double apex_A[2];
    double apex_B[2];
    double apex_C[2];
    double apex_D[2];
};

class rectangle:public quadri
{
public:
    rectangle(double, double, double, double, double, double);
    void show_rectangle();
    void cricre_out(double *, double *, double *);
private:
    double dlina_AB;
    double dlina_BC;
};

int main()
{
     triangle A (0.,0.,1.,0.,0.,1.);
     A.show_triangle();
     cout<<"point in is"<<A.point_in(0.2,0.2)<<endl;
     cout<<"square: "<<A.square()<<endl;
     quadri B;
     B.show_quadri();
     B.assign_quadri(0.,0.,1.,1.,2.,1.,1.,0.);
     B.show_quadri();
     cout<<"!!!!!!!!! "<<B.square()<<endl;
     rectangle C(0.,0.,0.,2.,2.,2.);
     C.show_rectangle();
     double R,Ox,Oy;
     C.cricre_out(&R,&Ox,&Oy);
     cout<<"circle R "<<R<<"centre "<<Ox<<""<<Oy<<endl;
     return 0;
}

triangle::triangle(double ax, double ay, double bx, double by, double cx, double cy)
{
    apex_A[0] = ax;
    apex_A[1] = ay;
    apex_B[0] = bx;
    apex_B[1] = by;
    apex_C[1] = cy;
    apex_C[0] = cx;
}

void triangle::show_triangle(void)
{
    cout<<"triangle"<<endl;
    cout<<"apex_A"<<apex_A[0]<<" "<<apex_A[1]<<endl;
    cout<<"apex_B"<<apex_B[0]<<" "<<apex_B[1]<<endl;
    cout<<"apex_C"<<apex_C[0]<<" "<<apex_C[1]<<endl;
}

double triangle::square()
{
    double I1,I2,I3,p;
    I1=sqrt((apex_A[0] - apex_B[0])*(apex_A[0] - apex_B[0])+(apex_A[1] - apex_B[1])*(apex_A[1] - apex_B[1]));
    // cout<<I1<<endl;
    I2=sqrt((apex_A[0] - apex_C[0])*(apex_A[0] - apex_C[0])+(apex_A[1] - apex_C[1])*(apex_A[1] - apex_C[1]));
    // cout<<I2<<endl;
    I3=sqrt((apex_B[0] - apex_C[0])*(apex_B[0] - apex_C[0])+(apex_B[1] - apex_C[1])*(apex_B[1] - apex_C[1]));
    // cout<<I3<<endl;
    p = (I1+I2+I3)/2.;
    double S = sqrt(p * (p-I1) * (p-I2) * (p-I3));
    return S;
}

void triangle::get_apexes (double a[2], double b[2], double c[2])
{
    a[0] = apex_A[0];
    a[1] = apex_A[1];
    b[0] = apex_B[0];
    b[1] = apex_B[1];
    c[0] = apex_C[0];
    c[1] = apex_C[1];
}

bool triangle::point_in(double x, double y)
{
    triangle T1 (apex_A[0],apex_A[1],apex_B[0],apex_B[1],x,y);
    // T1.show_triangle();
    triangle T2 (apex_A[0],apex_A[1],apex_C[0],apex_C[1],x,y);
    // T2.show_triangle();
    triangle T3 (apex_B[0],apex_B[1],apex_C[0],apex_C[1],x,y);
    // T3.show_triangle();
    double S = square();
    double S1 = T1.square() + T2.square() + T3.square();
    // cout<<S<<" "<<S1<<endl;
    if (fabs(S-S1) < 0.001) return true;
    return false;
}


quadri::quadri(double ax, double ay, double bx, double by, double cx, double cy, double dx, double dy)
{
    apex_A[0] = ax;
    apex_A[1] = ay;
    apex_B[0] = bx;
    apex_B[1] = by;
    apex_C[0] = cy;
    apex_C[1] = cx;
    apex_D[0] = dx;
    apex_D[1] = dy;
}

quadri::quadri()
{
    apex_A[0] = 0.;
    apex_A[1] = 0.;
    apex_B[0] = 0.;
    apex_B[1] = 1.;
    apex_C[0] = 1.;
    apex_C[1] = 1.;
    apex_D[0] = 1.;
    apex_D[1] = 0.;
}

void quadri::assign_quadri(double ax, double ay, double bx, double by, double cx, double cy, double dx, double dy)
{
    apex_A[0] = ax;
    apex_A[1] = ay;
    apex_B[0] = bx;
    apex_B[1] = by;
    apex_C[0] = cy;
    apex_C[1] = cx;
    apex_D[0] = dx;
    apex_D[1] = dy;
}

void quadri::show_quadri(void)
{
    cout<<"triangle"<<endl;
    cout<<"apex_A"<<apex_A[0]<<" "<<apex_A[1]<<endl;
    cout<<"apex_B"<<apex_B[0]<<" "<<apex_B[1]<<endl;
    cout<<"apex_C"<<apex_C[0]<<" "<<apex_C[1]<<endl;
    cout<<"apex_D"<<apex_D[0]<<" "<<apex_D[1]<<endl;
}

double quadri::square()
{
    double mid_x = (apex_A[0] + apex_C[0])/2.;
    double mid_y = (apex_A[1] + apex_C[1])/2.;
    cout<< mid_x << " "<< mid_y << endl;
    triangle T1 (apex_A[0],apex_A[1],apex_B[0],apex_B[1],mid_x,mid_y);
    // T1.show_triangle();
    triangle T2 (apex_B[0],apex_B[1],apex_C[0],apex_C[1],mid_x,mid_y);
    // T2.show_triangle();
    triangle T3 (apex_C[0],apex_C[1],apex_D[0],apex_D[1],mid_x,mid_y);
    // T3.show_triangle();
    triangle T4 (apex_A[0],apex_A[1],apex_D[0],apex_D[1],mid_x,mid_y);
    // T4.show_triangle();
    double S = T1.square() + T2.square() + T3.square() + T4.square();
    // cout<<"!!!!"<<S<<endl;
    return S;
}

rectangle::rectangle(double ax, double ay, double bx, double by, double cx, double cy):
quadri()
{
    assign_quadri(ax,ay,bx,by,cx,cy,cx,ay);
    dlina_AB = fabs(by-ay);
    dlina_BC = fabs(cx=bx);
    cout<<"dlina_AB"<< dlina_AB<<endl;
}

void rectangle::show_rectangle()
{
    cout<<" rectangle "<<endl;
    show_quadri();
}

void rectangle::cricre_out(double* r,double* ox, double* oy)
{
    *ox = apex_A[0] + dlina_BC/2.;
    *oy = apex_A[1] + dlina_AB/2.;
    *r = sqrt((apex_A[0] - *ox)*(apex_A[0] - *ox)+(apex_A[1] - *oy)*(apex_A[1] - *oy));
    cout<< "$$$$$$$"<<*r<<endl;
}
