
#include <iostream>
#include <string.h>
using namespace std;
class Stud_Data;
class Student
{
    string name;
    int roll_no;
    string cls;
    char *division;
    string dob;
    char *bloodgroup;
    static int count;

public:
    Student()
    {
        name = "";
        roll_no = 0;
        cls = "";
        division = new char;
        dob = "dd/mm/yyyy";
        bloodgroup = new char[4];
    }

    ~Student()
    {
        delete division;
        delete[] bloodgroup;
    }

    static int get_Count()
    {
        return count;
    }

    void get_Data(Stud_Data *);
    void disp_Data(Stud_Data *);
};

class Stud_Data
{
    string caddress;
    long int *telno;
    long int *dlno;
    friend class Student;

public:
    Stud_Data()
    {
        caddress = "";
        telno = new long;
        dlno = new long;
    }

    ~Stud_Data()
    {
        delete telno;
        delete dlno;
    }

    void getStud_Data()
    {
        cout << "Enter Contact Address : ";
        cin.get();
        getline(cin, caddress);
        cout << "Enter Telephone Number : ";
        cin >> *telno;
        cout << "Enter Driving License Number : ";
        cin >> *dlno;
    }

    void dispStud_Data()
    {
        cout << "Contact Address : " << caddress << endl;
        cout << "Telephone Number : " << *telno << endl;
        cout << "Driving License Number : " << *dlno << endl;
    }
};

inline void Student::get_Data(Stud_Data *st)
{
    cout << "Enter Student Name : ";
    getline(cin, name);
    cout << "Enter Roll Number : ";
    cin >> roll_no;
    cout << "Enter Class : ";
    cin.get();
    getline(cin, cls);
    cout << "Enter Division : ";
    cin >> division;
    cout << "Enter Date of Birth : ";
    cin.get();
    getline(cin, dob);
    cout << "Enter Blood Group : ";
    cin >> bloodgroup;
    st->getStud_Data();
    count++;
}

inline void Student::disp_Data(Stud_Data *st1)
{
    cout << "Student Name : " << name << endl;
    cout << "Roll Number : " << roll_no << endl;
    cout << "Class : " << cls << endl;
    cout << "Division : " << division << endl;
    cout << "Date of Birth : " << dob << endl;
    cout << "Blood Group : " << bloodgroup << endl;
    st1->dispStud_Data();
}

int Student::count;

int main()
{
    Student *stud1[100];
    Stud_Data *stud2[100];
    int n = 0;
    char ch;

    do
    {
        stud1[n] = new Student;
        stud2[n] = new Stud_Data;
        stud1[n]->get_Data(stud2[n]);
        n++;
        cout << "Do You want to add Another student (Yes/No) : " << endl;
        cin >> ch;
        cin.get();
    }

    while (ch == 'Y' || ch == 'y');

    for (int i = 0; i < n; i++)
    {
        cout << "*************************************************************" << endl;
        cout << "               STUDENT INFORMATION SYSTEM            " << endl;
        cout << "*************************************************************" << endl;
        stud1[i]->disp_Data(stud2[i]);
    }
    cout << "---------------------------------------------------------------" << endl;
    cout << "Total Students : " << Student::get_Count();
    cout << endl
         << "---------------------------------------------------------------" << endl;

    for (int i = 0; i < n; i++)
    {
        delete stud1[i];
        delete stud2[i];
    }
    return 0;
}










