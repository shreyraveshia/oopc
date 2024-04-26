#include<iostream>
#include<iomanip>
using namespace std;
class employee
{
    int emp_Id;
    string emp_name, quali;
    long int con_no;
    float exp ,Totexp=0,AvaExp;
    static float Tot_exp;
    static int cnt;
protected:
    employee()
    {
        cnt++;
    }
    void getdata()
        {
            cout << endl << "Enter Employee Id : ";
            cin >> emp_Id;
            fflush(stdin);
            cout << "Enter Employee Name : ";
            getline(cin,emp_name);
            cout << "Enter Employee Qualification : ";
            cin >> quali;
            cout << "Enter Number of Year of Employee Experience : ";
            cin >> exp;
            fflush(stdin);
            cout << "Enter Employee Contact number : ";
            cin >> con_no;
            Tot_exp+=exp;
        }
        int searchemp(int x)
        {
            if(x==emp_Id)
            {
                return 1;
            }
        }
        void displaydata()
        {
                cout << endl << "Employee Name" << setw(4) << " : " << emp_name;
                cout << endl << "Qualofication" << setw(4) << " : " << quali;
                cout << endl << "Exeperience" << setw(6) << " : " << exp;
                cout << endl << "Contact Number" << setw(3) << " : " << con_no;
        }
public:
     static void avaexp()
        {
            cout <<  float(Tot_exp)/float(cnt);
        }
};
class TeachingEmployee : public employee
{
    string designation,specialization,payscale;
public:
    int searchemp(int x)
    {
        int a;
        a=employee::searchemp(x);
        if(a==1)
        {
            displaydata();
            return 1;
        }
    }
    void getdata()
    {
        employee::getdata();
        fflush(stdin);
        cout << "Enter Designation : ";
        getline(cin,designation);
        cout << "Enter Specialization : ";
        getline(cin,specialization);
        cout << "Enter Pay Scale : ";
        getline(cin,payscale);
    }
    void displaydata()
    {
        employee::displaydata();
        fflush(stdin);
        cout << endl << "Designation" << setw(6) << " : " << designation << endl;
        cout << "Specialization" << setw(3) << " : "  << specialization << endl;
        cout << "Pay Scale" << setw(8) << " : "  << payscale << endl;
    }
};
class NonTeachingEmployee : public employee
{
    int salary;
public:
    void getdata()
    {
        employee::getdata();
        fflush(stdin);
        cout << "Enter Salary : ";
        cin >> salary;
    }
     int searchemp(int x)
    {
        int a;
        a=employee::searchemp(x);
        if(a==1){
                displaydata();
            return 1;
        }
    }
    void displaydata()
    {
        employee::displaydata();
        cout << endl << "Salary" << setw(11) << " : "  <<  salary << endl;
    }
};
int employee :: cnt=0;
float employee :: Tot_exp=0;
int main()
{
    char ch;
    int n1,n2,i,c,find_Id,a,choice;
    cout << "Enter Number of Teaching Employee : ";
    cin >> n1;
    class TeachingEmployee emp[n1];
    for (i=0;i<n1;i++)
    {
        emp[i].getdata();
    }
    cout << "\nEnter Number of Non Teaching Employee : ";
    cin >> n2;
    class NonTeachingEmployee emp1[n2];
    for (i=0;i<n2;i++)
    {
        emp1[i].getdata();
    }
    system("CLS");
    do{
    cout << "\n\nPress \n1.To Get Employee Data \n2.To Get Avarage Experience of Employee.\n3.exit\n";
    cin >> a;
    switch(a)
    {
    case 1:
        {
            fflush(stdin);
            cout << endl << "Enter Employee Id : ";
            cin >> find_Id;
            for(i=0;i<n1;i++)
            {
                c=emp[i].searchemp(find_Id);

                if(c==1)
                {
                    break;
                }
            }
            if(i==n1)
                {
                    for(i=0;i<n2;i++)
                    {
                        c=emp1[i].searchemp(find_Id);
                        if(c==1)
                        {
                            break;
                        }
                    }
                }
            break;
        }
    case 2:
        {
        cout << "Avarage Exeperience Of All Employee is : ";
        employee :: avaexp();
        break;
        }
    }
    }while(a!=3);
    return 0;
}

