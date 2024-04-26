#include<iostream>
using namespace std;

class complex
{
  private:
 float r;
 float i;

  public:
  void getdata()
  {
      cout<<"real part:"<<endl;
      cin>>r;
      cout<<"imaginary part:"<<endl;
      cin>>i;
  }
  complex operator +(complex temp1)
  {
      complex temp2;
  temp2.r=r+temp1.r;
  temp2.i=i+temp1.i;
  return temp2;
  }

  complex operator -(complex temp1)
  {
  complex temp2;
  temp2.r=r-temp1.r;
  temp2.i=i-temp1.i;
  return temp2;
  }

    complex operator *(complex temp1)
  {
  complex temp2;
  temp2.r=(r + temp1.r)-(i - temp1.i);
  temp2.i=(r + temp1.r)+(i - temp1.i);
  return temp2;
  }

  complex operator /(complex temp1)
  {
  complex temp2;
  temp2.r=(r * temp1.r) + (i * temp1.r) /(i*i + temp1.i*temp1.i);
  temp2.i=(i * temp1.r) + (r * temp1.i) /(i*i + temp1.i*temp1.i);
  return temp2;
  }

  void putdata()
  {
      cout<< r << "+"<< i << "i"<<endl;
  }
};

int main()
{
    complex c1,c2,c3;
    c1.getdata();
    c2.getdata();
    char ch;
    cout << "choose operator :" << endl;
    cout << "(+)Addition" <<endl;
    cout << "(-)Subtraction" <<endl;
    cout << "(*)Multiplication" <<endl;
    cout <<"(/)Division"<< endl;

    cin >>ch;
switch(ch)
    {
case'+':
    c3=c1+c2;
    c3.putdata();
    break;

case'-':
    c3=c1-c2;
    c3.putdata();
    break;

case'*':
    c3=c1*c2;
    c3.putdata();
    break;

case'/':
    c3=c1/c2;
    c3.putdata();
    break;
default: ;
    }

    }

