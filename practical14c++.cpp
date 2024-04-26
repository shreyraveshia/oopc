
#include<iostream>
#include<iomanip>
using namespace std;
class literature
{
    int id;
    string title;
public:
    void getdata()
    {
        cout << "\nEnter ID : ";
        cin >> id;
        fflush(stdin);
        cout << "Enter Title : ";
        getline(cin,title);
    }
    void putdata()
    {
        cout << endl << (left) << setw(7) << id << "   ";
        cout << (left) << setw(20) << title;
    }
};
class e_literature : public virtual literature
{
    string DOI;
public:
    void getdata()
    {
        cout << "Enter DOI : ";
        cin >> DOI;
    }
    void putdata()
    {
        cout << setw(3) << DOI;
    }
};
class hb_literature : public virtual literature
{
    int copies;
public:
    void getdata()
    {
        cout << "Enter In Stock copies : ";
        cin >> copies;
    }
    void putdata()
    {
        cout  << setw(2) << copies << " copies  ";
    }
};
class book : public e_literature, public hb_literature
{
    int ISBN;
    char c;
public:
    void getdata()
    {
        literature :: getdata();
        cout << "Enter ISBN : ";
        cin >> ISBN;
        fflush(stdin);
        cout << "(E)copy or (H)ardbound : ";
        cin >> c;
        switch(c)
        {
        case 'E':
            {
                e_literature :: getdata();
                break;
            }
        case 'H':
            {
                hb_literature :: getdata();
                break;
            }
        }
    }
    void putdata()
    {
        literature :: putdata();
        cout << (left) << setw(7) << ISBN;
        if(c=='E'){
        e_literature :: putdata();
        }
        else{
        hb_literature :: putdata();
        }
    }
};
class magazine : public e_literature, public hb_literature
{
    int ISSN;
    char c;
public:
    void getdata()
    {
        literature :: getdata();
        cout << "Enter ISSN : ";
        cin >> ISSN;
        cout << "(E)copy or (H)ardbound : ";
        cin >> c;
        switch(c)
        {
        case 'E':
            {
                e_literature :: getdata();
                break;
            }
        case 'H':
            {
                hb_literature :: getdata();
                break;
            }
        }
    }
    void putdata()
    {
        literature :: putdata();
        cout << (left) << setw(7) <<  ISSN;
        if(c=='E'){
        e_literature :: putdata();
        }
        else{
        hb_literature :: putdata();
        }
    }
};
int main()
{
    int c,i,nb=0,nm=0;
    char choice;
    class book b[20];
    class magazine m[20];
    do{
    cout << "\nEnter 1 : Add book data\nEnter 2 : Add magazine data\nEnter 3 : List all books\nEnter 4 : List all magazines";
    cout << "\nEnter your choice : ";
    cin >> c;
    switch(c)
    {
    case 1:
        {
            cout << endl << "Enter Book Data :" << endl;
            nb++;
            b[nb].getdata();
            break;
        }
    case 2:
        {
            cout << endl << "Enter Magazine Data :" << endl;
            nm++;
            m[nm].getdata();
            break;
        }
    case 3:
        {
            cout << endl << "List all Books :" << endl;
            if(nb==0)
            {
                cout << "\nNo Data Found..!\n";
            }
            else
            {
                for(i=1;i<=nb;i++)
                {
                    b[i].putdata();
                }
            }
            break;
        }
    case 4:
        {
            cout << endl << "List all magazines :" << endl;
            if(nm==0)
            {
                cout << "\nNo Data Found..!\n";
            }
            else
            {
                for(i=1;i<=nm;i++)
                {
                    m[i].putdata();
                }
            }
            break;
        }
    }
    cout << "\nPress M for Main menu or Press any key to exit : ";
    cin >> choice;
    }while(choice=='M');
    return 0;
}
