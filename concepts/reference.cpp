#include <iostream>
using namespace std;

void swap(int &x, int &y)
{
    int temp = y;
    y = x;
    x = temp;
    return;
}

int main()
{
    int a = 5, b = 10;
    swap(a, b);
    cout << a << " " << b << endl;
    return 0;
}