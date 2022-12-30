
#include <iostream>
using namespace std;
int n;
#define size 10
template <class T>

void Selection_sort(T A[size])
{
    int i, j, min;
    T temp;
    for (i = 0; i < n - 1; i++)
    {
        min = i;
        for (j = i + 1; j < n; j++)
        {
            if (A[j] < A[min])
                min = j;
        }
        temp = A[i];
        A[i] = A[min];
        A[min] = temp;
    }
    cout << "Sorted array order:";
    for (i = 0; i < n; i++)
    {
        cout << " " << A[i];
    }
}
int main()
{
    int A[size];
    float B[size];
    int i;

    cout << "Enter total no of int elements:" << endl;
    cin >> n;
    cout << "Enter int elements:" << endl;
    for (i = 0; i < n; i++)
    {
        cin >> A[i];
    }
    Selection_sort(A);

    cout << "\n**************************************************************";
    cout << "\nEnter total no of float elements:" << endl;
    cin >> n;
    cout << "Enter float elements:" << endl;
    for (i = 0; i < n; i++)
    {
        cin >> B[i];
    }
    Selection_sort(B);
    cout << "\n**************************************************************";
    cout << endl;
}


 
