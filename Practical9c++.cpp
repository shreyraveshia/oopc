
#include<iomanip>
#include<iostream>
using namespace std;
class centimeter;
class millimeter
{
    float a;
public:
    millimeter()
    {
        a=0;
    }
    void getdatamm()
    {
        cout<<"enter measurement in mm - ";
        cin>>a;
    }
    millimeter(centimeter &n);
    float getmm()
    {
        return a;
    }
    void putmm()
    {
        cout<<"measurement in mm = "<<a;
    }
};
class centimeter
{
    float a;
public:
    centimeter()
    {
        a=0;
    }
    void getdatacm()
    {
        cout<<"enter measurement in cm - ";
        cin>>a;
    }
    centimeter(millimeter &n);
    float getcm()
    {
        return a;
    }
    void putcm()
    {
        cout<<"measurement in mm = "<<a;
    }
};
centimeter::centimeter(millimeter &n)
    {
        a=n.getmm()/10;
    }
millimeter::millimeter(centimeter &n)
    {
        a=n.getcm()*10;
    }
int main()
{
    int i;
    do{
    class centimeter obj;
    class millimeter obj1;
    cout<<"\nenter 1 for cm to mm \nenter 2 for mm to cm\nenter 3 for exit\n";
    cin>>i;
    if(i==1)
    {
        obj.getdatacm();
        obj1=obj;
        obj1.putmm();
    }
    else if(i==2)
    {
        obj1.getdatamm();
        obj=obj1;
        obj.putcm();
    }
    }while(i==1 || i==2 );
    return 0;
}
