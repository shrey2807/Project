void display()
{
    int newsr = srno;
    int day = bday[newsr - 1].first.second;
    int month = bday[newsr - 1].second.first;
    int year = bday[newsr - 1].second.second;
    cout << "         /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////" << endl;
    cout << "        ///                                                                                                               ///" << endl;
    cout << "       ///                                                 Rank - " << setw(3) << setfill(' ') << rank << " "
         << "                                                   ///" << endl;
    cout << "      ///                                                                                                               ///" << endl;
    cout << "     /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////" << endl;
    cout << "Sr. No: " << srno << "\t"
         << "Name: " << name << " ";
    if (day < 10)
        cout << "Birthdate: "
             << "0" << day << "/";
    else
        cout << "Birthdate: " << day << "/";

    if (month < 10)
        cout << "0" << month << "/" << year << endl;
    else
        cout << month << "/" << year << endl;

    cout << "Total: " << total << " ";
    cout << "Physics: " << physics << " ";
    cout << "Chemistry: " << chemistry << " ";
    cout << "Maths: " << maths << endl;
    cout << "Physics PR: " << std::fixed << std::setprecision(2) << phyper << " ";
    cout << "Chemistry PR: " << std::fixed << std::setprecision(2) << cheper << " ";
    cout << "Maths PR: " << std::fixed << std::setprecision(2) << matper << endl;
    cout << "Total PR: " << std::fixed << std::setprecision(2) << totper << endl
         << endl
         << endl;
}