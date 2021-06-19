#include <bits/stdc++.h>
#include <windows.h>
#include <unistd.h>
using namespace std;

// these are colour codes
#define RESET "\033[0m"
#define BLACK "\033[30m"              /* Black */
#define RED "\033[31m"                /* Red */
#define GREEN "\033[32m"              /* Green */
#define YELLOW "\033[33m"             /* Yellow */
#define BLUE "\033[34m"               /* Blue */
#define MAGENTA "\033[35m"            /* Magenta */
#define CYAN "\033[36m"               /* Cyan */
#define WHITE "\033[37m"              /* White */
#define BOLDBLACK "\033[1m\033[30m"   /* Bold Black */
#define BOLDRED "\033[1m\033[31m"     /* Bold Red */
#define BOLDGREEN "\033[1m\033[32m"   /* Bold Green */
#define BOLDYELLOW "\033[1m\033[33m"  /* Bold Yellow */
#define BOLDBLUE "\033[1m\033[34m"    /* Bold Blue */
#define BOLDMAGENTA "\033[1m\033[35m" /* Bold Magenta */
#define BOLDCYAN "\033[1m\033[36m"    /* Bold Cyan */
#define BOLDWHITE "\033[1m\033[37m"   /* Bold White */

// here are some global declarations
int color = 0;
vector<pair<int, int>> phy, che, mat;

vector<pair<int, pair<int, pair<int, pair<int, pair<int, int>>>>>> myvec;
vector<string> student_name, colleges;
vector<pair<pair<int, int>, pair<int, int>>> bday;

// Macro functions
#define E1(i) myvec[i].first
#define E2(i) myvec[i].second.first
#define E3(i) myvec[i].second.second.first
#define E4(i) myvec[i].second.second.second.first
#define E5(i) myvec[i].second.second.second.second.first
#define E6(i) myvec[i].second.second.second.second.second

int cnt = 0, belowequal, rnd = 1;
void collegewrite(int clg1, int rank, vector<int> &choices);
int countdays(int day, int month, int year);

// Class that initially stores all data for the purpose of sorting.
class Database
{

public:
    // Function to write user's result in a HTML tag
    void writeraw()
    {
        int x = 0, day, month, year, a = 2;

        ofstream write2;
        write2.open("Entries.html");
        write2 << "<!DOCTYPE html>" << endl
               << "<html lang=\"en\">" << endl
               << "<head>" << endl
               << "<meta charset = \"UTF-8\">" << endl
               << "<meta http - equiv = \"X-UA-Compatible\" content = \"IE=edge\">" << endl
               << "<meta name = \"viewport\" content = \"width=device-width, initial-scale=1.0\">" << endl
               << "</head>" << endl
               << "<body>" << endl
               << "<a href = \"YourResult.html\" class=\"button\">MAIN PAGE</a><br>" << endl
               << "<title>ALL ENTRIES</title>" << endl
               << "<h1>ALL ENTRIES</h1>" << endl
               << "<style>" << endl
               << ".demo1 {" << endl
               << "background-color: #F6A9A7;" << endl
               << "border-radius: 15px;" << endl
               << "padding-left: 25px;" << endl
               << "padding-top: 1px;" << endl
               << "padding-bottom: 1px;" << endl
               << "}" << endl
               << ".demo2 {" << endl
               << "background-color: #E4F6A7;" << endl
               << "border-radius: 15px;" << endl
               << "padding-left: 25px;" << endl
               << "padding-top: 1px;" << endl
               << "padding-bottom: 1px;" << endl
               << "}" << endl
               << ".demo3 {" << endl
               << "background-color: #A7F4F6;" << endl
               << "border-radius: 15px;" << endl
               << "padding-left: 25px;" << endl
               << "padding-top: 1px;" << endl
               << "padding-bottom: 1px;" << endl
               << "}" << endl
               << ".demo4 {" << endl
               << "background-color: #A7A9F6;" << endl
               << "border-radius: 15px;" << endl
               << "padding-left: 25px;" << endl
               << "padding-top: 1px;" << endl
               << "padding-bottom: 1px;" << endl
               << "}" << endl
               << ".demo5 {" << endl
               << "background-color: #E6A7F6;" << endl
               << "border-radius: 15px;" << endl
               << "padding-left: 25px;" << endl
               << "padding-top: 1px;" << endl
               << "padding-bottom: 1px;" << endl
               << "}" << endl
               << ".button{" << endl
               << "background-color : #6be8f8;" << endl
               << "border: none;" << endl
               << "border-radius: 7px;" << endl
               << "color: black;" << endl
               << "padding: 15px 32px;" << endl
               << "text-align: center;" << endl
               << "text-decoration: none;" << endl
               << "display: inline-block;" << endl
               << "font-size: 10px;" << endl
               << "}" << endl
               << "</style>" << endl;

        while (x != cnt)
        {
            day = bday[x].first.second;
            month = bday[x].second.first;
            year = bday[x].second.second;
            write2 << "<div class=\"demo" << (a % 5) + 1 << "\">" << endl;
            write2 << "<p>" << endl
                   << "Sr. No: " << std::fixed << std::setprecision(0) << E6(x) << "<br>" << endl;

            write2 << "Name: " << student_name[x] << "<br>" << endl;
            if (day < 10)
                write2 << "Birthdate: "
                       << "0" << day << "/";
            else
                write2 << "Birthdate: " << day << "/";

            if (month < 10)
                write2 << "0" << month << "/" << year << "<br><br>" << endl;
            else
                write2 << month << "/" << year << "<br><br>" << endl;

            write2 << "Physics: " << E3(x) << "<br>" << endl;
            write2 << "Chemistry: " << E4(x) << "<br>" << endl;
            write2 << "Maths: " << E2(x) << "<br>" << endl;
            write2 << "<strong>"
                   << "Total: " << E1(x) << "</strong><br><br>" << endl;
            write2 << "<br>" << endl;
            write2 << "</p>" << endl;
            write2 << "</div>" << endl
                   << endl;
            x++;
            a++;
        }
        write2.close();
    }

    // Function to sort main vector with all marks and birthdate
    void oursort()
    {
        sort(myvec.rbegin(), myvec.rend());
    }

    // constructor
    Database()
    {
        // pushing the college names into vector
        colleges.push_back("IIT-Bombay");
        colleges.push_back("IIT-Roorkee");
        colleges.push_back("DAIICT");
        colleges.push_back("NIT-Trichy");
        colleges.push_back("IIIT-Vadodara");
        colleges.push_back("BITS-Pilani");
        colleges.push_back("VIT");
        colleges.push_back("SRM");
        colleges.push_back("IISc-Bangalore");
        colleges.push_back("PDPU");

        int p, c, m, date, month, year, total, serialno;
        string temp, s;

        cout << BOLDWHITE << "Do you want to generate a set of random data?" << endl
             << "Enter Y for YES, N for NO: ";
        cin >> s;
        cout << endl;

        // Generating random data set
        if (s == "Y" || s == "y" || s == "yes")
        {
            ifstream read1;
            ofstream writedata;
            string temp;

            read1.open("NameData.dat");
            writedata.open("Alldata.dat");
            srand(time(0));

            while (read1 >> temp)
            {
                p = ((rand() % 50) + 51);
                c = ((rand() % 50) + 51);
                m = ((rand() % 50) + 51);
                date = (rand() % 28) + 1;
                month = (rand() % 12) + 1;
                year = (rand() % 3) + 2001;

                writedata << cnt + 1 << " "
                          << temp << " "
                          << p << " "
                          << c << " "
                          << m << " "
                          << (rand() % 28) + 1 << " "
                          << (rand() % 12) + 1 << " "
                          << (rand() % 3) + 2001 << " "
                          << endl;

                cnt++;
            }
            read1.close();
            writedata.close();

            ifstream readall;
            readall.open("Alldata.dat");

            while (readall >> serialno >> temp >> p >> c >> m >> date >> month >> year)
            {
                student_name.push_back(temp);
                bday.push_back(make_pair(make_pair(serialno, date), make_pair(month, year)));
                myvec.push_back(make_pair(p + c + m, make_pair(m, make_pair(p, make_pair(c, make_pair(countdays(date, month, year), serialno))))));
            }

            belowequal = cnt;
        }

        //  Reading data from the file Alldata.dat
        else
        {
            ifstream readall;
            readall.open("Alldata.dat");

            while (readall >> serialno >> temp >> p >> c >> m >> date >> month >> year)
            {
                student_name.push_back(temp);
                bday.push_back(make_pair(make_pair(serialno, date), make_pair(month, year)));
                myvec.push_back(make_pair(p + c + m, make_pair(m, make_pair(p, make_pair(c, make_pair(countdays(date, month, year), serialno))))));
            }
            cnt = serialno;
        }
    }

    // Function to call writeraw and oursort
    void callall()
    {
        this->writeraw();
        this->oursort();
    }
};

// College class for storing individual ranks inside vector of branches of each college
// and generating random amount of seats in a branch in a college
class college
{
public:
    vector<int> branch1, branch2, branch3;
    int b[3];

    void defineseats()
    {
        // storing number of seats in array b[]
        b[0] = rand() % (cnt / 25);
        b[1] = rand() % (cnt / 25);
        b[2] = rand() % (cnt / 25);
        b[rand() % 3] = cnt * 0.05;
    }
};

// declaring clg
college clg[10];

// Defined the class individual which deals with the assignment of data to individual object of person
class individual
{
    string name;
    int total, physics, maths, chemistry, rank;

public:
    float phyper, cheper, matper, totper, clg1 = -1, srno;
    vector<int> choices;
    // constructor to generate choices of students(excluding that of user)
    individual()
    {
        int a, b;
        for (int i = 0; i < 3; i++)
        {
            a = rand() % 10 + 1;
            b = rand() % 3 + 1;
            choices.push_back(a * 10 + b);
        }
    }
    // Function to print html code for your result page (main page)
    void resulthtml()
    {
        int newsr = srno;
        int day = bday[newsr - 1].first.second;
        int month = bday[newsr - 1].second.first;
        int year = bday[newsr - 1].second.second;

        ofstream writehtml2;
        writehtml2.open("YourResult.html");
        writehtml2 << "<!DOCTYPE html>" << endl
                   << "<html lang=\"en\">" << endl
                   << "<head>" << endl
                   << "<meta charset = \"UTF-8\">" << endl
                   << "<meta http - equiv = \"X-UA-Compatible\" content = \"IE=edge\">" << endl
                   << "<meta name = \"viewport\" content = \"width=device-width, initial-scale=1.0\">" << endl
                   << "<title>RESULT!</title>" << endl
                   << "</head>" << endl
                   << "<body>" << endl
                   << "<div class=\"wholepage\">" << endl
                   << "<p style=\"text-align: center;\"> " << endl
                   << "<div class=\"heading\">" << endl
                   << "<h1>YOUR RESULT</h1></p>" << endl
                   << "<a href = \"Entries.html\" class=\"button\">ALL ENTRIES</a>&nbsp" << endl
                   << "<a href = \"CollegeData.html\" class=\"button\">COLLEGE DATA</a>&nbsp" << endl
                   << "<a href = \"Ranks.html\" class=\"button\">OVERALL RESULT</a>&nbsp" << endl
                   << "<a href = \"Round1.html\" class=\"button\">ROUND 1</a>&nbsp" << endl
                   << "<a href = \"Round2.html\" class=\"button\">ROUND 2</a>&nbsp" << endl
                   << "<a href = \"Round3.html\" class=\"button\">ROUND 3</a>&nbsp" << endl
                   << "<a href = \"Final_Round.html\" class=\"button\">FINAL ROUND</a>&nbsp</div>" << endl
                   << "<div class=\"inside\">"
                   << "<br>"
                   << "Rank: " << rank << "<br" << endl
                   << "Sr.No: " << srno << "<br>" << endl
                   << "Name: " << name << "<br>" << endl;

        if (day < 10)
        {
            writehtml2 << "Birthdate: "
                       << "0" << day << "/";
        }
        else
        {
            writehtml2 << "Birthdate: " << day << "/";
        }

        if (month < 10)
        {
            writehtml2 << "0" << month << "/" << year << "<br>" << endl
                       << endl;
        }
        else
        {
            writehtml2 << month << "/" << year << "<br>" << endl
                       << endl;
        }

        writehtml2 << "Physics: " << physics << "<br>"
                   << "Chemistry: " << chemistry << "<br>"
                   << "Maths: " << maths << "<br>"
                   << "<strong>Total: " << total << "</strong><br><br>"
                   << "Physics PR: " << phyper << "<br>"
                   << "Chemistry PR: " << cheper << "<br>"
                   << "Maths PR: " << matper << "<br>"
                   << "<strong>Total PR: " << totper << "</strong><br><br>"
                   << "</div>";

        if (clg1 == -1)
        {
            writehtml2 << "<p style=\" text-align: center; vertical-align: middle; line-height: 20px; background-color: #EBFE00\">"
                       << "You have not been alloted any seat in any college of your preferrence</p>";
        }
        else if (clg1 == -2)
        {
            writehtml2 << "<p style=\" text-align: center; vertical-align: middle; line-height: 20px; background-color: #FE0000\">"
                       << "You have withdrawn your seat</p>";
        }
        else if (clg1 == -3)
        {
            writehtml2 << "<p style=\" text-align: center; vertical-align: middle; line-height: 20px; background-color: #FE0000\">"
                       << "You did not participate in the allocation process</p>";
        }
        else
        {
            int one, two;
            one = (int)clg1 / 10;
            two = (int)clg1 % 10;

            switch (two)
            {
            case 1:
                writehtml2 << "<p style=\" text-align: center; vertical-align: middle; line-height: 20px; background-color: #28FE00\">"
                           << "You have been alloted a seat in Computer Science&nbsp;";
                break;
            case 2:
                writehtml2 << "<p style=\" text-align: center; vertical-align: middle; line-height: 20px; background-color: #28FE00\">"
                           << "You have been alloted a seat in Mechanical&nbsp;";
                break;
            case 3:
                writehtml2 << "<p style=\" text-align: center; vertical-align: middle; line-height: 20px; background-color: #28FE00\">"
                           << "You have been alloted a seat in Electrical&nbsp;";
                break;
            default:
                break;
            }
            writehtml2 << "in " << colleges[one - 1]
                       << "</p>";
        }

        writehtml2 << "</div>" << endl
                   << "<style>" << endl
                   << ".heading{" << endl
                   << "text-align: center;" << endl
                   << "}" << endl
                   << ".inside{" << endl
                   << "padding-left: 40px;" << endl
                   << "}" << endl
                   << ".wholepage{" << endl
                   << "background-color: #b8f2fc;" << endl
                   << "border-radius: 15px;" << endl
                   << "padding-top: 1px;" << endl
                   << "padding-bottom: 1px;" << endl
                   << "}" << endl
                   << ".button{" << endl
                   << "background-color : #6be8f8;" << endl
                   << "border: none;" << endl
                   << "border-radius: 7px;" << endl
                   << "color: black;" << endl
                   << "padding: 15px 32px;" << endl
                   << "text-align: center;" << endl
                   << "text-decoration: none;" << endl
                   << "display: inline-block;" << endl
                   << "font-size: 10px;" << endl
                   << "}" << endl
                   << "</style>" << endl;
        writehtml2.close();
    }

    /*Function to ask user whether he/she wants to enter the allocation process, if he wants to
  then function will input the choices of colleges*/
    void userchoices()
    {
        choices.clear();
        char c;
        int ch;

        cout << WHITE;
        cout << "Do you want to enter the seat allocation process." << endl;
        cout << "Enter" << GREEN << " 'Y' " << WHITE << "or" << GREEN << " 'y' " << WHITE << "for YES" << endl
             << endl;
        cout << "\t\t OR" << endl
             << endl;
        cout << "Enter" << RED << " 'N' " << WHITE << "or" << RED << " 'n' " << WHITE << "for NO" << endl;
        cout << "(We suggest to atleast try one round to check where you stand)" << endl;
        while (1)
        {
            cout << "Enter here: ";
            cin >> c;
            if (!(c == 'Y' || c == 'y' || c == 'N' || c == 'n'))
                cout << RED << "Invalid Choice!" << WHITE << endl;
            else
                break;
        }

        cout << endl
             << endl;
        if (c == 'Y' || c == 'y')
        {
            cout << "Let's look at the choices of each college and their respective branches :  " << endl;

            cout << YELLOW << "Prefixes" << WHITE << " for colleges: " << endl
                 << endl;
            cout << MAGENTA << "(1) " << CYAN << "IIT-Bombay" << endl;
            cout << MAGENTA << "(2) " << CYAN << "IIT-Roorkee" << endl;
            cout << MAGENTA << "(3) " << CYAN << "DAIICT" << endl;
            cout << MAGENTA << "(4) " << CYAN << "IIIT-Vadodara" << endl;
            cout << MAGENTA << "(5) " << CYAN << "BITS-Pilani" << endl;
            cout << MAGENTA << "(6) " << CYAN << "IISc-Bangalore" << endl;
            cout << MAGENTA << "(7) " << CYAN << "NIT-Trichy" << endl;
            cout << MAGENTA << "(8) " << CYAN << "VIT" << endl;
            cout << MAGENTA << "(9) " << CYAN << "SRM" << endl;
            cout << MAGENTA << "(10) " << CYAN << "PDPU" << WHITE << endl
                 << endl;

            cout << WHITE;

            cout << YELLOW << "Suffixes" << WHITE << " for Branches: " << endl
                 << endl;
            cout << GREEN << "(1) " << CYAN << "Computer-Science" << endl;
            cout << GREEN << "(2) " << CYAN << "Mechanical" << endl;
            cout << GREEN << "(3) " << CYAN << "Electrical" << endl;
            cout << WHITE << endl;

            cout << "For ex :" << endl
                 << endl;
            cout << "For " << MAGENTA << "in IIT Bombay" << WHITE << "-" << GREEN << "Electrical " << MAGENTA << " 1" << GREEN << "3 " << WHITE << endl;
            cout << endl;
            cout << RED << " NOTE: The first digit represents the college" << endl;
            cout << RED << "       The second digit represents the branch" << WHITE << endl;
            cout << endl;
        }
        else
        {
            this->clg1 = -3;
            return;
        }

        while (c == 'y' || c == 'Y')
        {
            cout << "Enter choice(Please enter a number) : ";
            cin >> ch;
            if (ch / 10 > 0 && ch / 10 < 11 && ch % 10 < 4 && ch % 10 > 0)
                choices.push_back(ch);
            else
            {
                cout << RED << "Oops! Ambiguous choice. Please enter again." << WHITE << endl;
                continue;
            }
            cout << endl
                 << endl;
            cout << "Do you want to enter another choice?" << endl;
            cout << "Enter" << GREEN << " 'Y' " << WHITE << "or" << GREEN << " 'y' " << WHITE << "for YES" << endl;
            cout << "Enter" << RED << " 'N' " << WHITE << "or" << RED << " 'n' " << WHITE << "for  NO" << endl;
            while (1)
            {
                cout << "Enter here: ";
                cin >> c;
                if (!(c == 'Y' || c == 'y' || c == 'N' || c == 'n'))
                    cout << RED << "Invalid Choice!" << WHITE << endl;
                else
                    break;
            }
            cout << endl;
        }
    }
    //this function will assign physics,chemistry,maths to separate vector for providing their separate percentile
    void assign(int i)
    {
        this->name = student_name[E6(i) - 1];
        this->total = E1(i);
        this->maths = E2(i);
        this->physics = E3(i);
        this->chemistry = E4(i);
        this->srno = E6(i);
        this->rank = i + 1;

        phy.push_back(make_pair(E3(i), rank));
        che.push_back(make_pair(E4(i), rank));
        mat.push_back(make_pair(E2(i), rank));
    }
    //this function will print html code for ranks.html file
    void sorteddata(ofstream &write1, ofstream &writehtml)
    {
        int x = 0;
        int newsr = srno;
        int day = bday[newsr - 1].first.second;
        int month = bday[newsr - 1].second.first;
        int year = bday[newsr - 1].second.second;

        write1 << "Rank " << rank << endl;
        write1 << "Sr. No: " << srno << std::fixed << std::setprecision(0) << "\t"
               << "Name: " << name << " ";
        if (day < 10)
            write1 << "Birthdate: "
                   << "0" << day << "/";
        else
            write1 << "Birthdate: " << day << "/";

        if (month < 10)
            write1 << "0" << month << "/" << year << endl;
        else
            write1 << month << "/" << year << endl;

        write1 << "Total: " << total << " ";
        write1 << "Physics: " << physics << " ";
        write1 << "Chemistry: " << chemistry << " ";
        write1 << "Maths: " << maths << endl;
        write1 << "Physics PR: " << std::fixed << std::setprecision(2) << phyper << " ";
        write1 << "Chemistry PR: " << std::fixed << std::setprecision(2) << cheper << " ";
        write1 << "Maths PR: " << std::fixed << std::setprecision(2) << matper << endl;
        write1 << "Total PR: " << std::fixed << std::setprecision(2) << totper << endl;
        write1 << "Choices entered: ";
        for (int i = 0; i < choices.size(); i++)
        {
            write1 << choices[i] << " ";
        }
        write1 << "------------------------------------------------------------------------------------" << endl;

        writehtml << "<div class=\"demo" << (color % 5) + 1 << "\">" << endl;
        color++;
        writehtml << "<p>" << endl;
        writehtml << "<div><h2>Rank: " << rank << "</h2></div>" << endl;

        writehtml << "Name: " << name << "<br>" << endl
                  << "Sr. No: " << std::fixed << std::setprecision(0) << srno << "<br>" << endl;

        if (day < 10)
            writehtml << "Birthdate: "
                      << "0" << day << "/";
        else
            writehtml << "Birthdate: " << day << "/";

        if (month < 10)
            writehtml << "0" << month << "/" << year << "<br><br>" << endl;
        else
            writehtml << month << "/" << year << "<br><br>" << endl;

        writehtml << "Physics: " << physics << "<br>" << endl;
        writehtml << "Chemistry: " << chemistry << "<br>" << endl;
        writehtml << "Maths: " << maths << "<br>" << endl;
        writehtml << "<strong>"
                  << "Total: " << total << "</strong><br><br>" << endl;
        writehtml << "Physics PR: " << std::fixed << std::setprecision(2) << phyper << "<br>" << endl;
        writehtml << "Chemistry PR: " << std::fixed << std::setprecision(2) << cheper << "<br>" << endl;
        writehtml << "Maths PR: " << std::fixed << std::setprecision(2) << matper << "<br>" << endl;
        writehtml << "<strong>"
                  << "Total PR: " << std::fixed << std::setprecision(2) << totper << "</strong><br><br>" << endl;
        writehtml << "Choices entered: ";
        for (int i = 0; i < choices.size(); i++)
        {
            writehtml << choices[i] << " ";
        }
        writehtml << "<br>" << endl;
        writehtml << "</p>" << endl;
        writehtml << "</div>" << endl
                  << endl;
    }
    //this assign the choice integer if college is allocated to the variable clg1 to use it further
    void check(int x)
    {
        if (clg1 == -3)
        {
            collegewrite(clg1, x + 1, choices);
            return;
        }
        if (clg1 == -2)
        {
            collegewrite(clg1, x + 1, choices);
            return;
        }

        int size = choices.size();
        int one, two;
        for (int i = 0; i < size; i++)
        {
            one = choices[i] / 10;
            two = choices[i] % 10;

            if (two == 1)
            {
                if (clg[one - 1].branch1.size() < clg[one - 1].b[0])
                {
                    clg1 = choices[i];
                    clg[one - 1].branch1.push_back(this->rank);
                    break;
                }
                else
                    continue;
            }
            else if (two == 2)
            {
                if (clg[one - 1].branch2.size() < clg[one - 1].b[1])
                {
                    clg1 = choices[i];
                    clg[one - 1].branch2.push_back(rank);
                    break;
                }
                else
                    continue;
            }
            else
            {
                if (clg[one - 1].branch3.size() < clg[one - 1].b[2])
                {
                    clg1 = choices[i];
                    clg[one - 1].branch3.push_back(rank);
                    break;
                }
                else
                    continue;
            }
        }
        collegewrite(clg1, x + 1, choices);
    }
    //this function will display your resukt on the console
    void display()
    {
        int newsr = srno;
        int day = bday[newsr - 1].first.second;
        int month = bday[newsr - 1].second.first;
        int year = bday[newsr - 1].second.second;

        cout << endl
             << endl
             << endl
             << endl
             << endl;
        cout << WHITE;
        cout << "         /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////" << endl;
        cout << "        ///                                                                                                               ///" << endl;
        cout << "       ///" << YELLOW << "                                                 Rank - " << setw(3) << setfill(' ') << rank << " "
             << "                                                   " << WHITE << "///" << endl;
        cout << "      ///                                                                                                               ///" << endl;
        cout << "     /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////" << endl;

        cout << endl
             << endl;

        cout << "     "
             << MAGENTA
             << "Sr. No: " << WHITE << srno << endl
             << endl;
        cout << "     "
             << MAGENTA
             << "Name: " << WHITE << name << endl;

        if (day < 10)
            cout << "     "
                 << MAGENTA
                 << "Birthdate: "
                 << WHITE
                 << "0" << day << "/";
        else
            cout << "     "
                 << MAGENTA
                 << "Birthdate: "
                 << WHITE << day << "/";

        if (month < 10)
            cout << "0" << month << "/" << year << endl
                 << endl;
        else
            cout << month << "/" << year << endl
                 << endl;

        cout << "     "
             << "<-----"
             << YELLOW
             << "  Marks  "
             << WHITE
             << "----->" << endl
             << endl;
        cout << "     "
             << BLUE << "Physics: " << WHITE << physics << CYAN << "\tPhysics PR: " << std::fixed << std::setprecision(2) << WHITE << phyper << endl;
        cout << "     "
             << BLUE << "Chemistry: " << WHITE << chemistry << CYAN << "\tChemistry PR: " << std::fixed << std::setprecision(2) << WHITE << cheper << endl;
        cout << "     "
             << BLUE << "Maths: " << WHITE << maths << CYAN << "\t\tMaths PR: " << std::fixed << std::setprecision(2) << WHITE << matper << endl
             << endl;
        cout << "     "
             << BLUE << "Total: " << WHITE << total << CYAN << "\t\tTotal PR: " << std::fixed << std::setprecision(2) << WHITE << totper << endl;
        cout << endl
             << endl
             << endl
             << endl
             << endl
             << endl;
    }
};

individual *person;

// The function randomly makes some student withdraw their seats because we are dealing with random data here and not actual students
void withdraw()
{
    for (int i = 0; i < 10; i++)
    {
        int a, b;
        if (cnt < 250)
        {
            a = rand() % 2;
        }
        else if (cnt > 250)
        {
            a = rand() % (cnt / 150);
        }
        if (rand() % 2)
        {
            for (int j = 0; j < a; j++)
            {
                if (clg[i].branch1.size() == 0)
                {
                    break;
                }
                b = rand() % clg[i].branch1.size();
                if (person[clg[i].branch1[b] - 1].srno == cnt)
                {
                    continue;
                }
                person[clg[i].branch1[b] - 1].clg1 = -2;
                clg[i].branch1.erase(clg[i].branch1.begin() + b);
            }
        }
        if (cnt < 250)
        {
            a = rand() % 2;
        }
        else if (cnt > 250)
        {
            a = rand() % (cnt / 150);
        }
        if (rand() % 2)
        {

            for (int j = 0; j < a; j++)
            {
                if (clg[i].branch2.size() == 0)
                {
                    break;
                }
                b = rand() % clg[i].branch2.size();
                if (person[clg[i].branch2[b] - 1].srno == cnt)
                {
                    continue;
                }
                person[clg[i].branch2[b] - 1].clg1 = -2;
                clg[i].branch2.erase(clg[i].branch2.begin() + b);
            }
        }
        if (cnt < 250)
        {
            a = rand() % 2;
        }
        else if (cnt > 250)
        {
            a = rand() % (cnt / 150);
        }
        if (rand() % 2)
        {

            for (int j = 0; j < a; j++)
            {
                if (clg[i].branch3.size() == 0)
                {
                    break;
                }
                b = rand() % clg[i].branch3.size();
                if (person[clg[i].branch3[b] - 1].srno == cnt)
                {
                    continue;
                }
                person[clg[i].branch3[b] - 1].clg1 = -2;
                clg[i].branch3.erase(clg[i].branch3.begin() + b);
            }
        }
    }
}

// Function to calculate percentile of each student
void percentile()
{
    belowequal = cnt;
    for (int i = 0; i < cnt; i++)
    {
        if (i != 0)
        {
            if (phy[i].first != phy[i - 1].first)
                belowequal = cnt - i;

            person[phy[i].second - 1].phyper = ((float)(belowequal * 100) / (float)cnt);
        }
        else
        {
            person[phy[0].second - 1].phyper = 100;
        }
    }
    belowequal = cnt;
    for (int i = 0; i < cnt; i++)
    {
        if (i != 0)
        {
            if (che[i].first != che[i - 1].first)
                belowequal = cnt - i;

            person[che[i].second - 1].cheper = ((float)(belowequal * 100) / (float)cnt);
        }
        else
        {
            person[che[0].second - 1].cheper = 100;
        }
    }
    belowequal = cnt;
    for (int i = 0; i < cnt; i++)
    {
        if (i != 0)
        {
            if (mat[i].first != mat[i - 1].first)
                belowequal = cnt - i;

            person[mat[i].second - 1].matper = ((float)(belowequal * 100) / (float)cnt);
        }
        else
        {
            person[mat[0].second - 1].matper = 100;
        }
    }
    belowequal = cnt;
    for (int i = 0; i < cnt; i++)
    {
        if (i != 0)
        {
            if (E1(i) != E1(i - 1))
                belowequal = cnt - i;

            person[i].totper = ((float)(belowequal * 100) / (float)cnt);
        }
        else
        {
            person[0].totper = 100;
        }
    }
}

// Function to take user input (i.e. name, marks, birthdate, etc..)
void userinput()
{
    int date = 1, month = 1, year = 2000;
    string name;
    int p = 10, c = 10, m = 10;

    cout << "Enter name: ";
    getchar();
    getline(cin, name);
    student_name.push_back(name);

    while (1)
    {
        cout << "Enter Physics Marks: ";
        cin >> p;
        if (p > 100 || p < 0)
            cout << RED << "Oops! You entered ambiguous marks!" << WHITE << endl;
        else
            break;
    }
    while (1)
    {
        cout << "Enter Chemistry Marks: ";
        cin >> c;
        if (c > 100 || c < 0)
            cout << RED << "Oops! You entered ambiguous marks!" << WHITE << endl;
        else
            break;
    }
    while (1)
    {
        cout << "Enter Maths Marks: ";
        cin >> m;
        if (m > 100 || m < 0)
            cout << RED << "Oops! You entered ambiguous marks!" << WHITE << endl;
        else
            break;
    }
    while (1)
    {
        cout << "Enter Your date of birth: ";
        cin >> date;
        if (date > 31 || date <= 0)
            cout << RED << "Oops! You entered ambiguous date!" << WHITE << endl
                 << endl;
        else
            break;
    }
    while (1)
    {
        cout << "Enter Your month of birth: ";
        cin >> month;
        if (month > 12 || month <= 0)
            cout << RED << "Oops! You entered ambiguous month!" << WHITE << endl;
        else
            break;
    }
    while (1)
    {
        cout << "Enter Your year of birth: ";
        cin >> year;
        if (year > 2003 || year < 2000)
            cout << RED << "Oops! You entered ambiguous year!" << WHITE << endl
                 << endl;
        else
            break;
    }

    bday.push_back(make_pair(make_pair(cnt + 1, date), make_pair(month, year)));

    myvec.push_back(make_pair(p + c + m, make_pair(m, make_pair(p, make_pair(c, make_pair(countdays(date, month, year), cnt + 1))))));

    sleep(1);
    system("CLS");
    cout << endl;
    cout << YELLOW << "Uploading your data to the database ";
    sleep(1);
    cout << ".";
    sleep(1);
    cout << ".";
    sleep(1);
    cout << ".";
    sleep(1);
    cout << endl;
    cout << WHITE;

    cout << GREEN << "Succesfully Uploaded!!" << WHITE << endl;
    sleep(0.5);

    ofstream insideuserinput;
    insideuserinput.open("Alldata.dat", ios::app);
    insideuserinput << cnt + 1 << " "
                    << name << " "
                    << p << " "
                    << c << " "
                    << m << " "
                    << date << " "
                    << month << " "
                    << year << " "
                    << endl;
    insideuserinput.close();
    cnt++;
}

// Function to sort individual subject's marks
void sortsubjects()
{
    sort(phy.rbegin(), phy.rend());
    sort(che.rbegin(), che.rend());
    sort(mat.rbegin(), mat.rend());
}

// Function to generate HTML code for files-
// Round1.html
// Round2.html
// Round3.html
// Final_Round.html
// The HTML code prints the status of seat allotement of all students in the above mentioned web pages
void collegewrite(int clg1, int rank, vector<int> &choices)
{

    ofstream writehtml1;
    if (rnd == 1)
    {
        writehtml1.open("Round1.html", ios::app);
    }
    else if (rnd == 2)
    {
        writehtml1.open("Round2.html", ios::app);
    }
    else if (rnd == 3)
    {
        writehtml1.open("Round3.html", ios::app);
    }
    else if (rnd == 4)
    {
        writehtml1.open("Final_Round.html", ios::app);
    }

    if (rank == 1)
    {

        writehtml1 << "<!DOCTYPE html>" << endl
                   << "<html lang=\"en\">" << endl
                   << "<head>" << endl
                   << "<meta charset = \"UTF-8\">" << endl
                   << "<meta http - equiv = \"X-UA-Compatible\" content = \"IE=edge\">" << endl
                   << "<meta name = \"viewport\" content = \"width=device-width, initial-scale=1.0\">" << endl
                   << "<a href = \"YourResult.html\" class=\"button\">MAIN PAGE</a><br>" << endl;
        if (rnd < 4)
        {
            writehtml1 << "<title>ROUND - " << rnd << "</title>" << endl;
        }
        else
        {
            writehtml1 << "<title>FINAL ROUND</title>" << endl;
        }

        writehtml1 << "</head>" << endl
                   << "<body>" << endl;
        if (rnd < 4)
        {
            writehtml1 << "<h1>ROUND - " << rnd << "</h1>" << endl;
        }
        else
        {
            writehtml1 << "<h1>FINAL ROUND</h1>" << endl;
        }
        writehtml1 << "<style>" << endl
                   << ".withdraw {" << endl
                   << "background-color: #FF4641;" << endl
                   << "border-radius: 15px;" << endl
                   << "padding-left: 25px;" << endl
                   << "padding-top: 1px;" << endl
                   << "padding-bottom: 1px;" << endl
                   << "}" << endl
                   << ".not_allocated {" << endl
                   << "background-color: #FFE841;" << endl
                   << "border-radius: 15px;" << endl
                   << "padding-left: 25px;" << endl
                   << "padding-top: 1px;" << endl
                   << "padding-bottom: 1px;" << endl
                   << "}" << endl
                   << ".allocated {" << endl
                   << "background-color: #6AFF41;" << endl
                   << "border-radius: 15px;" << endl
                   << "padding-left: 25px;" << endl
                   << "padding-top: 1px;" << endl
                   << "padding-bottom: 1px;" << endl
                   << "}" << endl
                   << ".button{" << endl
                   << "background-color : #6be8f8;" << endl
                   << "border: none;" << endl
                   << "border-radius: 7px;" << endl
                   << "color: black;" << endl
                   << "padding: 15px 32px;" << endl
                   << "text-align: center;" << endl
                   << "text-decoration: none;" << endl
                   << "display: inline-block;" << endl
                   << "font-size: 10px;" << endl
                   << "}" << endl
                   << "</style>" << endl;
    }
    if (clg1 == -3)
        return;

    if (clg1 == -2)
    {
        writehtml1 << "<div class = \"withdraw\"><p>Rank : " << rank << "<br>" << endl;
        writehtml1 << "You have withdrawn your seat"
                   << "<br>";
        writehtml1 << "</p></div>";
        writehtml1 << endl
                   << endl;
    }
    else if (clg1 == -1)
    {
        writehtml1 << "<div class = \"not_allocated\"><p>Rank : " << rank << "<br>" << endl;
        writehtml1 << "You have not been alloted any seat in any college of your preferrence"
                   << "<br>";
        writehtml1 << "</p></div>";
        writehtml1 << endl
                   << endl;
    }
    else
    {

        writehtml1 << "<div class = \"allocated\"><p>Rank : " << rank << "<br>" << endl;

        int one, two;
        one = clg1 / 10;
        two = clg1 % 10;

        switch (two)
        {
        case 1:
            writehtml1 << "You have been alloted a seat in Computer Science&nbsp;";
            break;
        case 2:
            writehtml1 << "You have been alloted a seat in Mechanical&nbsp;";
            break;
        case 3:
            writehtml1 << "You have been alloted a seat in Electrical&nbsp;";
            break;
        default:
            break;
        }
        writehtml1 << "in " << colleges[one - 1];
        writehtml1 << "</p></div>";
        writehtml1 << endl
                   << endl;
    }
}

// Function to store value in a variable days, which is then pushed inside myvec vector
// the function generates a value inversely proportional to how old the candidate is.
int countdays(int day, int month, int year)
{
    int arr[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    int days;
    int a = 0;
    if (year == 2000)
    {
        arr[1]++;

        for (int i = 0; i < month - 1; i++)
            a += arr[i];
        a += day;
        return -1 * a;
    }
    a += 366;
    for (int i = 2001; i < year; i++)
    {
        a += 365;
    }
    for (int i = 0; i < month - 1; i++)
        a += arr[i];
    a += day;
    return -1 * a;
}

// Function to Generate HTML code to show the number of available seats in different branches of different colleges
// the available seats are shown for each round conducted
// RED - alloted
// GREEN - available (not alloted)
void collegedata(int round)
{
    int i, m, n;
    ofstream writehtml3;
    writehtml3.open("CollegeData.html", ios::app);
    if (round == 1)
    {
        writehtml3 << "<!DOCTYPE html>" << endl
                   << "<html lang=\"en\">" << endl
                   << "<head>" << endl
                   << "<meta charset = \"UTF-8\">" << endl
                   << "<meta http - equiv = \"X-UA-Compatible\" content = \"IE=edge\">" << endl
                   << "<meta name = \"viewport\" content = \"width=device-width, initial-scale=1.0\">" << endl
                   << "<title>RESULT!</title>" << endl
                   << "</head>" << endl
                   << "<body>" << endl
                   << "<div class=\"button\">" << endl
                   << "<a href = \"YourResult.html\" class=\"button\">MAIN PAGE</a>" << endl
                   << "</div>&nbsp&nbsp"
                   << "<div class=\"button\">"
                   << "<a href = \"#finalround\" class=\"button\">FINAL ROUND</a><br>" << endl
                   << "</div>"
                   << "<h1>RESULT</h1>" << endl
                   << "<style>" << endl
                   << "html {" << endl
                   << "scroll-behavior: smooth;" << endl
                   << "}" << endl
                   << ".demo1 {" << endl
                   << "background-color: #F6A9A7;" << endl
                   << "border-radius: 15px;" << endl
                   << "padding-left: 25px;" << endl
                   << "padding-top: 1px;" << endl
                   << "padding-bottom: 1px;" << endl
                   << "}" << endl
                   << ".demo2 {" << endl
                   << "background-color: #E4F6A7;" << endl
                   << "border-radius: 15px;" << endl
                   << "padding-left: 25px;" << endl
                   << "padding-top: 1px;" << endl
                   << "padding-bottom: 1px;" << endl
                   << "}" << endl
                   << ".demo3 {" << endl
                   << "background-color: #A7F4F6;" << endl
                   << "border-radius: 15px;" << endl
                   << "padding-left: 25px;" << endl
                   << "padding-top: 1px;" << endl
                   << "padding-bottom: 1px;" << endl
                   << "}" << endl
                   << ".demo4 {" << endl
                   << "background-color: #A7A9F6;" << endl
                   << "border-radius: 15px;" << endl
                   << "padding-left: 25px;" << endl
                   << "padding-top: 1px;" << endl
                   << "padding-bottom: 1px;" << endl
                   << "}" << endl
                   << ".demo5 {" << endl
                   << "background-color: #E6A7F6;" << endl
                   << "border-radius: 15px;" << endl
                   << "padding-left: 25px;" << endl
                   << "padding-top: 1px;" << endl
                   << "padding-bottom: 1px;" << endl
                   << "}" << endl
                   << ".button{" << endl
                   << "background-color : #6be8f8;" << endl
                   << "border: none;" << endl
                   << "border-radius: 7px;" << endl
                   << "color: black;" << endl
                   << "padding: 8px 15px;" << endl
                   << "text-align: center;" << endl
                   << "text-decoration: none;" << endl
                   << "display: inline-block;" << endl
                   << "font-size: 10px;" << endl
                   << "}" << endl
                   << ".dotred {"
                   << "padding: 7px;" << endl
                   << "color: white;" << endl
                   << "width: 22px;" << endl
                   << "height: 22px;" << endl
                   << "background-color: red;" << endl
                   << "border-radius: 20%;" << endl
                   << "display: inline-block;" << endl
                   << "}" << endl
                   << ".dotgreen {"
                   << "padding: 7px;"
                   << "width: 22px;" << endl
                   << "height: 22px;" << endl
                   << "background-color: green;" << endl
                   << "border-radius: 20%;" << endl
                   << "display: inline-block;" << endl
                   << "}" << endl
                   << "</style>";
    }
    if (round < 4)
    {
        writehtml3 << "<p style=\" text-align: center; vertical-align: middle; line-height: 20px; background-color: #EBFE00\">" << endl;
        writehtml3 << "<h2>ROUND - " << round << "</h2>" << endl
                   << "</p>" << endl;
    }
    else
    {
        writehtml3 << "<div class=\"finalround1\" id=\"finalround\"><p style=\" text-align: center; vertical-align: middle; line-height: 20px; background-color: #EBFE00\"></div>" << endl;
        writehtml3 << "<h2>FINAL ROUND</h2" << endl
                   << "</p>" << endl;
    }

    int a = 0;
    writehtml3 << "<div>" << endl;
    for (int x = 0; x < 10; x++)
    {
        writehtml3 << "<div class=\"demo" << a % 5 + 1 << "\">" << endl
                   << "<h3>" << colleges[x] << "</h3>" << endl;

        writehtml3 << "<span>Computer Science: " << clg[x].b[0] << "</span>" << endl;
        writehtml3 << "<div>" << endl;
        writehtml3 << "<br>" << endl;
        for (i = 0; i < clg[x].branch1.size(); i++)
        {
            writehtml3 << "<span class=\"dotred\">" << clg[x].branch1[i] << "</span>&nbsp&nbsp" << endl;
        }

        if (i != clg[x].b[0] - 1)
        {
            for (int j = i + 1; j < clg[x].b[0]; j++)
            {
                writehtml3 << "<span class=\"dotgreen\">&nbsp&nbsp</span> &nbsp&nbsp" << endl;
            }
        }
        writehtml3 << "</div>" << endl;
        writehtml3 << "<br>";
        writehtml3 << "<span>Mechanical: " << clg[x].b[1] << "</span>" << endl;
        writehtml3 << "<div>" << endl;
        writehtml3 << "<br>" << endl;
        for (m = 0; m < clg[x].branch2.size(); m++)
        {
            writehtml3 << "<span class=\"dotred\">" << clg[x].branch2[m] << "</span>&nbsp&nbsp" << endl;
        }
        if (m != clg[x].b[1] - 1)
        {
            for (int j = m + 1; j < clg[x].b[1]; j++)
            {
                writehtml3 << "<span class=\"dotgreen\">&nbsp&nbsp</span>&nbsp&nbsp" << endl;
            }
        }
        writehtml3 << "</div>" << endl;
        writehtml3 << "<br>";
        writehtml3 << "<span>Electrical: " << clg[x].b[2] << "</span>" << endl;
        writehtml3 << "<div>" << endl;
        writehtml3 << "<br>" << endl;
        for (n = 0; n < clg[x].branch3.size(); n++)
        {
            writehtml3 << "<span class=\"dotred\">" << clg[x].branch3[n] << "</span>&nbsp&nbsp" << endl;
        }
        if (n != clg[x].b[2] - 1)
        {
            for (int j = n + 1; j < clg[x].b[2]; j++)
            {
                writehtml3 << "<span class=\"dotgreen\">&nbsp&nbsp</span>&nbsp&nbsp" << endl;
            }
        }
        writehtml3 << "</div>" << endl;
        writehtml3 << "<br>";
        writehtml3 << "<br>";
        writehtml3 << "</div>" << endl
                   << endl;
        a++;
    }
    writehtml3 << "</div>" << endl;
    writehtml3.close();
}

// it clears the vector  1, branches2 and branches3
void branchclear()
{
    for (int i = 0; i < 10; i++)
    {
        clg[i].branch1.clear();
        clg[i].branch2.clear();
        clg[i].branch3.clear();
    }
}

// it opens and closes all files, so that all the data within them is cleared
// it is necessary because we used append in writing content in files
void streamopenclose()
{
    ofstream openclose;
    openclose.open("Ranks.dat");
    openclose.close();
    ofstream openclosehtml;
    openclosehtml.open("Ranks.html");
    openclosehtml.close();
    ofstream openclose1;
    openclose1.open("Round1.html");
    openclose1.close();
    ofstream openclose2;
    openclose2.open("Round2.html");
    openclose2.close();
    ofstream openclose3;
    openclose3.open("Round3.html");
    openclose3.close();
    ofstream openclose4;
    openclose3.open("Final_Round.html");
    openclose3.close();
    ofstream opencloseclg;
    opencloseclg.open("Collegedata.html");
    opencloseclg.close();
}

int main()
{
    system("CLS");
    Database student;
    //this will take input from user
    userinput();
    cout << YELLOW;
    cout << "Now Sorting the data to assign ranks ";
    sleep(1);
    cout << ".";
    sleep(1);
    cout << ".";
    sleep(1);
    cout << ".";
    cout << endl;
    sleep(1);
    cout << GREEN << "Process Complete!!" << endl;
    cout << endl;
    sleep(1);
    //this will sort the myvec vector to assign ranks
    student.callall();

    person = new individual[cnt];
    //we will assign the data of all candidates according to ranks to the array of objects of class Individual
    for (int i = 0; i < cnt; i++)
    {
        person[i].assign(i);
    }
    //this will sort the physics,maths and chemistry vectors to aasign percentile
    sortsubjects();
    //this will assign the calculated percentiles to variables
    percentile();
    streamopenclose();

    ofstream write1;
    write1.open("Ranks.dat", ios::app);

    ofstream writehtml;
    writehtml.open("Ranks.html", ios::app);

    srand(time(0));
    //this is randomly generate number of seats for each
    for (int i = 0; i < 10; i++)
    {
        clg[i].defineseats();
    }
    int a;

    for (a = 0; a < cnt; a++)
    {
        if (person[a].srno == cnt)
            break;
    }
    person[a].choices.clear();
    //this will print your data in console
    person[a].display();
    //this will take choices from you
    person[a].userchoices();
    cout << endl;
    char c;

    for (int j = 0; j < 3; j++)
    {
        branchclear();
        if (person[a].clg1 != -3)
        {
            cout << "Round " << j + 1 << " in progress ";
            sleep(1);
            cout << ".";
            sleep(1);
            cout << ".";
            sleep(1);
            cout << ".";
            sleep(1);
            cout << endl;
        }

        for (int i = 0; i < cnt; i++)
        {
            person[i].check(i);
        }
        collegedata(j + 1);
        if (person[a].clg1 != -3)
        {
            cout << "Round " << j + 1 << " Ended !!!" << endl
                 << endl;

            if (person[a].clg1 != -2)
            {
                cout << "Do you want to " << RED << "withdraw" << WHITE << " your seat?" << endl;
                cout << "Enter" << RED << " 'Y' " << WHITE << "or" << RED << " 'y' " << WHITE << "for YES" << endl;
                cout << "Enter" << GREEN << " 'N' " << WHITE << "or" << GREEN << " 'n' " << WHITE << "for  NO" << endl;
                cout << "Enter here: ";
                cin >> c;
                if (c == 'y' || c == 'Y')
                    person[a].clg1 = -2;
            }

            if (person[a].clg1 == -2)
            {
                cout << RED << "You have withdrawn your seat" << WHITE << endl;
                cout << endl;
            }
            else if (person[a].clg1 == -1)
            {
                cout << YELLOW << "You have not been assigned any seat in any college of your preferrence" << WHITE << endl;
                cout << endl;
            }
            else
            {
                int one, two;
                one = person[a].clg1 / 10;
                two = (int)person[a].clg1 % 10;

                switch (two)
                {
                case 1:
                    cout << GREEN << "You have been alloted a seat in Computer Science";
                    break;
                case 2:
                    cout << "You have been alloted a seat in Mechanical";
                    break;
                case 3:
                    cout << "You have been alloted a seat in Electrical";
                    break;
                default:
                    break;
                }
                cout << " in " << colleges[one - 1] << WHITE << endl
                     << endl;
            }
        }
        withdraw();
        rnd++;
    }

    for (int i = 0; i < cnt; i++)
    {
        person[i].check(i);
    }
    collegedata(4);
    person[a].resulthtml();

    if (person[a].clg1 == -3)
    {
        cout << RED << "You did not enter the seat allocation process. But we are displaying the allocation results of other students" << WHITE << endl;
        sleep(5);
    }
    //code to print html code for ranks.html file
    cout << "Open Ranks.html in your browser" << endl;

    writehtml << "<!DOCTYPE html>" << endl
              << "<html lang=\"en\">" << endl
              << "<head>" << endl
              << "<meta charset = \"UTF-8\">" << endl
              << "<meta http - equiv = \"X-UA-Compatible\" content = \"IE=edge\">" << endl
              << "<meta name = \"viewport\" content = \"width=device-width, initial-scale=1.0\">" << endl
              << "<title>RESULT!</title>" << endl
              << "</head>" << endl
              << "<body>" << endl
              << "<a href = \"YourResult.html\" class=\"button\">MAIN PAGE</a><br>" << endl
              << "<h1>RESULT</h1>" << endl
              << "<style>" << endl
              << ".demo1 {" << endl
              << "background-color: #F6A9A7;" << endl
              << "border-radius: 15px;" << endl
              << "padding-left: 25px;" << endl
              << "padding-top: 1px;" << endl
              << "padding-bottom: 1px;" << endl
              << "}" << endl
              << ".demo2 {" << endl
              << "background-color: #E4F6A7;" << endl
              << "border-radius: 15px;" << endl
              << "padding-left: 25px;" << endl
              << "padding-top: 1px;" << endl
              << "padding-bottom: 1px;" << endl
              << "}" << endl
              << ".demo3 {" << endl
              << "background-color: #A7F4F6;" << endl
              << "border-radius: 15px;" << endl
              << "padding-left: 25px;" << endl
              << "padding-top: 1px;" << endl
              << "padding-bottom: 1px;" << endl
              << "}" << endl
              << ".demo4 {" << endl
              << "background-color: #A7A9F6;" << endl
              << "border-radius: 15px;" << endl
              << "padding-left: 25px;" << endl
              << "padding-top: 1px;" << endl
              << "padding-bottom: 1px;" << endl
              << "}" << endl
              << ".demo5 {" << endl
              << "background-color: #E6A7F6;" << endl
              << "border-radius: 15px;" << endl
              << "padding-left: 25px;" << endl
              << "padding-top: 1px;" << endl
              << "padding-bottom: 1px;" << endl
              << "}" << endl
              << ".button{" << endl
              << "background-color : #6be8f8;" << endl
              << "border: none;" << endl
              << "border-radius: 7px;" << endl
              << "color: black;" << endl
              << "padding: 15px 32px;" << endl
              << "text-align: center;" << endl
              << "text-decoration: none;" << endl
              << "display: inline-block;" << endl
              << "font-size: 10px;" << endl
              << "}" << endl
              << "</style>" << endl;

    for (int i = 0; i < cnt; i++)
    {
        person[i].sorteddata(write1, writehtml);
    }

    writehtml << "</body>"
              << "</html>"
              << endl;

    sleep(2);
    ShellExecute(NULL, "open", "YourResult.html",
                 NULL, NULL, SW_SHOWNORMAL);

    write1.close();
    writehtml.close();
    cout << RESET;
    return 0;
}