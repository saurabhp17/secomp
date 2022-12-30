#include <iostream>
using namespace std;
class complex
{
    double re;
    double img;

public:
    complex() // default constructor
    {
        re = 0;
        img = 0;
    }
    
friend istream &operator>>(istream &input, complex &c)  // overloading >> 
    {
   
        cout << "\nEnter real part:\n";
        input >> c.re;
        cout << "Enter imaginary part:\n";
        input >> c.img;
        return input;
    }
    friend ostream &operator<<(ostream &output, complex &c)  // overloading << 
    {
        output << c.re << "+" << c.img << "i";
        return output;
    }
    complex operator+(complex c2)  //overloading + operator
    {
        complex c3;
        c3.re = re + c2.re;
        c3.img = img + c2.img;
        return c3;
    }
    complex operator*(complex c2)   // overloading * operator
    {
        complex c4;
        c4.re = (re * c2.re) - (img * c2.img);
        c4.img = (img * c2.re) + (re * c2.img);
        return c4;
    }
};

int main()
{
    complex c1, c2, c3, c4;
    cout << "Default constructor value=";
    cout << c1 << endl;
    cout << "\nEnter 1st Complex Number:\n" << endl;
    cin >> c1;
    cout << "\nEnter 2nd Complex Number:\n" << endl;
    cin >> c2;
    c3 = c1 + c2;
    c4 = c1 * c2;
    cout << "\nThe Addition is:" << c3 << endl;
    cout << "\nThe Multiplication is:" << c4 << endl;
    return 0;
}







 
     
