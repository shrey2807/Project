#include <bits/stdc++.h>
using namespace std;

vector<pair<int, int>> Marks_Vector;
vector<pair<int, int>> physics;
void Sort_two();
int SR_NO = 0;
int cnt = 7;

class Database
{
    vector<string> student_name;
    vector<int> sr_no;
    // vector<int> physics;
    vector<int> chemistry;
    vector<int> maths;
    vector<int> total;

public:
    // constructor
    // Database()
    // {
    //     string temp;
    //     char s;

    //     cout << "Do you want to generate a set of random data?" << endl
    //          << "Enter Y for yes" << endl;
    //     cin >> s;

    //     if (s == 'Y')
    //     {
    //         ofstream write;
    //         ifstream read1;

    //         write.open("Onlyone.dat");
    //         read1.open("NameData.dat");
    //         srand(time(0));

    //         while (read1 >> temp)
    //         {
    //             cnt++;
    //             write << ((rand() % 50) + 51) << " ";
    //             write << ((rand() % 50) + 51) << " ";
    //             write << ((rand() % 50) + 51) << " ";
    //             write << temp << endl;
    //         }
    //         write.close();
    //         read1.close();
    //         // string str;
};
// ifstream read2;
// int p, c, m, i = 0;
// string name;
// read2.open("Onlyone.dat");

// while (read2 >> p >> c >> m >> name)
// {
//     sr_no.push_back(SR_NO);
//     physics.push_back(p);
//     chemistry.push_back(c);
//     maths.push_back(m);
//     student_name.push_back(name);

//     // calculating the total marks
//     total.push_back(chemistry[i] + maths[i] + physics[i]);
//     Marks_Vector.push_back(make_pair(total[i], sr_no[i]));
//     SR_NO++;
//     i++;
//     }
//     read2.close();
// }

// void Sort_two();
// };

// void Database::Sort_two()
// void Sort_two()
// {

//     int pos = 0;
//     while (pos != cnt)
//     {
//         int comparethis = Marks_Vector[pos].first;

//         if (comparethis == Marks_Vector[pos + 1].first)
//         {
//             int count2 = 0;
//             while (Marks_Vector[pos].first == comparethis)
//             {
//                 count2++;
//                 pos++;
//             }

//             sort(&physics[cnt - 1] - count2 - 1 + pos, &physics[0] + pos - count2 - 1);
//         }
//         pos++;
//     }
//     for (int i = 0; i < 7; i++)
//     {
//         cout << Marks_Vector[i].first << " " << physics[i] << endl;
//     }
// }

void Sort_two()
{
    int pos = 0;
    while (pos < cnt)
    {
        int Count2 = 1;
        while (Marks_Vector[pos].first == Marks_Vector[pos + Count2].first)
        {
            Count2++;
        }
        if (Count2 != 1)
            sort(&physics[pos], &physics[pos] + Count2, greater<>());

        // for (int i = 0; i < Count2; i++)
        //     Marks_Vector[pos + i].second = physics[pos + i].second;

        pos = pos + Count2;
    }

    // for (int i = 0; i < 7; i++)
    // {
    //     cout << physics[i].first << " " << physics[i].second << endl;
    // }

    for (int i = 0; i < 7; i++)
    {
        cout << Marks_Vector[i].first << " "
             << " " << Marks_Vector[i].second << " " << endl;
    }
}

int main()
{
    Database student;
    Marks_Vector.push_back(make_pair(10, 0));
    Marks_Vector.push_back(make_pair(20, 3));
    Marks_Vector.push_back(make_pair(20, 2));
    Marks_Vector.push_back(make_pair(20, 6));
    Marks_Vector.push_back(make_pair(40, 4));
    Marks_Vector.push_back(make_pair(50, 5));
    Marks_Vector.push_back(make_pair(50, 6));

    physics.push_back(make_pair(10, 0));
    physics.push_back(make_pair(20, 1));
    physics.push_back(make_pair(30, 2));
    physics.push_back(make_pair(40, 3));
    physics.push_back(make_pair(50, 4));
    physics.push_back(make_pair(60, 5));
    physics.push_back(make_pair(70, 6));

    sort(Marks_Vector.rbegin(), Marks_Vector.rend());
    Sort_two();

    return 0;
}
