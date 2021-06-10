#include <bits/stdc++.h>
using namespace std;

int main()
{
    string temp;
    ofstream write;
    ifstream read;

    write.open("Onlyone.dat");
    read.open("NameData.dat");
    srand(time(0));
    for (int i = 0; i < 10; i++)
    {
        write << ((rand() % 50) + 50) << " ";
        write << ((rand() % 50) + 50) << " ";
        write << ((rand() % 50) + 50) << " ";
        read >> temp;
        write << temp << endl;
    }

    return 0;
}