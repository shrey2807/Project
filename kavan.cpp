#include <iostream>
// To change the background-colour as well as text colour:
#include <windows.h> //or #include <stdlib.h>
using namespace std;
void SetColor(int value)
{
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), value);
}

struct node
{
    string file_name;
    string file_extension;
    node *next;
};

class file_explorer
{
private:
    node *head, *tail;

public:
    file_explorer();
    void create_file(string, string);
    void remove_file(string, string);
    void print_files();
    void sort_ascending_order();
    void sort_descending_order();
};

file_explorer::file_explorer()
{
    head = NULL;
    tail = NULL;
}

void file_explorer::create_file(string file_name, string file_extension)
{
    node *temp = (node *)malloc(sizeof(node));
    temp->file_name = file_name;
    temp->file_extension = file_extension;
    temp->next = NULL;
    if (head == NULL)
    {
        head = temp;
        tail = temp;
    }
    else
    {
        tail->next = temp;
        tail = tail->next;
    }
}

void file_explorer::print_files()
{
    if (head != NULL)
    {
        node *p = head;
        cout << "\nFile Name\t\t\tFile Type(Entension)\n"
             << "__________________\n\n";
        while (p != NULL)
        {
            cout << p->file_name << "\t\t\t\t"
                 << p->file_extension << "\n";
            p = p->next;
        }
    }
}

void file_explorer::remove_file(string f_name, string f_extension)
{
    if (head == NULL)
    {
        cout << "No custom files exist.\n";
    }
    else if (head->file_name == f_name && head->file_extension == f_extension)
    {
        node *p = head;
        head = head->next;
        free(p);
        p = NULL;
    }

    // else
    // {
    //     node *p = head;
    //     while (p->next->file_name != f_name && p->next->file_extension != f_extension && p != NULL)
    //     {
    //         node *temp = p->next;
    //         p->next = temp->next;
    //         free(temp);
    //         temp = NULL;
    //         p = p->next;
    //     }
    //     if (p == NULL)
    //     {
    //         cout << "No such files or directories exist";
    //     }
    // }
}

int main()
{
    file_explorer fe;
    cout << "\n\n*****Welcome to the terminal*******\n\n";
    cout << "type \'help\' to get all the commmands and \'exit[]\' to close the terminal...\n\n";
    while (1)
    {
        cout << "rootdirectory:\\ ";
        string s, new_file, new_file_extension;
        cin >> s;
        if (s == "help")
        {
            SetColor(2);
            cout << "\n\'lis\'    ------------>to print the list of all the files\n"
                 << "\n\'pwdr\'   ------------>to print the working directory\n"
                 << "\n\'mkfile\' ------------>to make a new file\n"
                 << "\n\'remfile\'------------>to remove the directory\n"
                 << "\n\'sortac\' ------------>to sort in ascending order\n"
                 << "\n\'sortdc\' ------------>to sort in descending order\n\n";
            SetColor(7);
        }
        else if (s == "lis")
        {
            // Some default derectories
            cout << "Desktop\t\tDocuments\tDownloads\tMusic\t\tPictures\n";
            //Files created by user
            fe.print_files();
        }

        else if (s == "mkfile")
        {
            cout << "Enter the name of the file: ";
            cin >> new_file;
            cout << "Enter the extension of the file: ";
            cin >> new_file_extension;
            fe.create_file(new_file, new_file_extension);
        }

        else if (s == "remfile")
        {
            cout << "Enter the name of the file to be removed: ";
            cin >> new_file;
            cout << "Enter the extension of the file: ";
            cin >> new_file_extension;
            fe.remove_file(new_file, new_file_extension);
        }

        else if (s == "pwdr")
        {
            SetColor(10);
            cout << "Admin, you are inside :home\\rootdirectory\n";
            SetColor(7);
        }

        else if (s == "exit[]")
        {
            cout << endl;
            goto end;
        }
        else
        {
            SetColor(4);
            cout << "\nERROR!!!Command not found\n\n";
            SetColor(7);
        }
    }
end:
    return 0;
}