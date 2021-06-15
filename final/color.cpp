#include <bits/stdc++.h>
using namespace std;

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
#define BOLDWHITE "\033[1m\033[37m"

int main()
{
    cout << "Do you want to enter choices : " << endl;
    cout << "Y/y for entering the seat allocation process." << endl;
    cout << "N/n for withdrawing yourself from the process. (We suggest to atleast try one round to check where you stand." << endl;
    // cin >> c;
    cout << "----------------------------------------------------------------------------------------------------------" << endl;
    cout << "Let's look at the choices of each college and their respective branches :  " << endl;
    // cout << "\t\t\t\t=> Prefixes for colleges : " << endl;
    // cout << "IIT-Bombay (1)                 IIT-Roorkee (2)              DAIICT (3)" << endl;
    // cout << "NIT-Trichy (4)                 IIIT-Vadodara (5)            BITS-Pilani (6)" << endl;
    // cout << "VIT (7)                        SRM (8)                      IISc-Bangalore (9)" << endl;
    // cout << "PDPU (10)" << endl
    cout << BOLDYELLOW << "Prefixes" << WHITE << " for colleges: " << endl
         << endl;
    cout << BOLDMAGENTA << "(1) " << CYAN << "IIT-Bombay" << endl;
    cout << MAGENTA << "(2) " << CYAN << "IIT-Roorkee" << endl;
    cout << MAGENTA << "(3) " << CYAN << "DAIICT" << endl;
    cout << MAGENTA << "(4) " << CYAN << "IIIT-Vadodara" << endl;
    cout << MAGENTA << "(5) " << CYAN << "BITS-Pilani" << endl;
    cout << MAGENTA << "(6) " << CYAN << "IISc-Bangalore" << endl;
    cout << MAGENTA << "(7) " << CYAN << "NIT-Trichy" << endl;
    cout << MAGENTA << "(8) " << CYAN << "VIT" << endl;
    cout << MAGENTA << "(9) " << CYAN << "SRM" << endl;
    cout << MAGENTA << "(10) " << CYAN << "PDPU" << RESET << endl
         << endl;

    cout << WHITE;

    cout << BOLDYELLOW << "Suffixes" << WHITE << " for Branches: " << endl
         << endl;
    cout << BOLDGREEN << "(1) " << CYAN << "Computer-Science" << endl;
    cout << GREEN << "(2) " << CYAN << "Mechanical" << endl;
    cout << GREEN << "(3) " << CYAN << "Electrical" << endl;
    cout << WHITE << endl;

    cout << "For ex :" << endl
         << endl;
    cout << "For " << BOLDMAGENTA << "in IIT Bombay" << WHITE << "-" << GREEN << "Electrical " << MAGENTA << " 1" << GREEN << "3 " << RESET << endl;
    cout << RESET << endl;
    return 0;
}