/*
    1. Write a C++ program to insert the records into an order (single) linked list
    (ordered by account number in ascending order).

    2. Then print the reports starting at the head of the list
    and traversing to the end of the list.

    3. Produce both an inactive account report and active account report
    ordered by account number.

    4. Write both reports to a file that can be printed.
*/
#include<iostream>
#include<fstream>
#include<vector>
#include<algorithm>
#include<cctype>
#include<iomanip>

using namespace std;

struct NODE
{
int account_number ;
string last_name;
string first_name;
int month;   // date created
int day;
int year;
float balance;
char acct_type;  //    Note: may be enter in either upper or lower case  -c checking  s- savings other error
bool acct_status; // 1 – active  0 - inactive
NODE *Next;  //pointer to next node in list

};   // end structure listnode

void openFile(ifstream &inF, string infileName);

int main()
{
// opening the file streams

    ofstream SortedOutF, ActOutF, InactOutF;
    ifstream inF;
    string infileName = "Blokes.txt";
//Our vector containing the
    vector<string> Data;
    vector<string> SortedData;
    string checking = "CK";
    string savings = "SA";
    int AcctAge = 2018;
    float TotBal = 0;
    int Pumba = 0;
    int i = 0;

string Months[12] = {"Jan","Feb","Mar","Apr","May",
                        "June","July","Aug","Sep",
                        "Oct","Nov","Dec"};
    //The start of our list ta-dow
    NODE *Head = NULL;
    NODE *Curr = Head;
    NODE *N = Head;

    //Sorting initial file
    openFile(inF, infileName);

        N = new NODE;
        inF >> N -> account_number;
        inF >> N -> last_name;
        inF >> N -> first_name;
        inF >> N -> month;   // date created
        inF >> N -> day;
        inF >> N -> year;
        inF >> N -> balance;
        inF >> N -> acct_type; // Note: may be enter in either upper or lower case  -c checking  s- savings other error
        inF >> N -> acct_status; // 1 – active  0 - inactive

        TotBal = N->balance;

        // this is the new head
        Head = N;
        Curr = N;
        //new node
        while (!inF.eof())
        {
            // Inserting the data
            N = new NODE;
            inF >> N -> account_number
                    >> N -> last_name
                    >> N -> first_name
                    >> N -> month   // date created
                    >> N -> day
                    >> N -> year
                    >> N -> balance
                    >> N -> acct_type  // Note: may be enter in either upper or lower case  -c checking  s- savings other error
                    >> N -> acct_status; // 1 – active  0 - inactive

            TotBal += N -> balance;
            Curr->Next = N;
            Curr = N;

        }

                Curr = Head;
                        cout <<setw(55) << "Account Overview" << endl;
                        cout << "Last" << setw(17) << "First" << setw(15) << "Date of" << setw(33) << "Account" << setw(10) << "Account" << setw(10) <<  "Account" << endl;
                        cout << endl;
                        cout << "Name" << setw(16) << "Name" << setw(17) << "Creation" << setw(20) << "Balance" << setw(12)<< "type" << setw(10) << "Age" << setw(10) <<  "Number" << endl;
                        cout << endl;

                while(Curr != N)
                {
                       cout << setw(15) << left <<  Curr -> last_name << " "
                        << setw(0) << left << Curr -> first_name[0] << ". "
                        << setw(10) << right << Months[Curr -> month-1] << ". "// date created

                        << setw(2) << Curr -> day << ", "
                        << setw(4) << Curr -> year << " "
                        << setw(17) << fixed << setprecision(2) << Curr -> balance << " ";
                        if(tolower(Curr->acct_type) == 'c')
                            cout << setw(10) << checking;
                        else
                            cout << setw(10) << savings;
//                        << setw(10) << Curr -> acct_type << " " // Note: may be enter in either upper or lower case  -c checking  s- savings other error
                        cout << setw(10) << Curr -> acct_status << " "
                        << setw(9)<< Curr -> account_number << " " << endl;
                        Curr = Curr->Next;
                }
cout <<setprecision(2) << fixed << TotBal;
/*
        //outputs the vector
        for(int n = 0; n < SortedData.size(); n++)
        {
            cout << SortedData[n] << " ";
            cout << endl;
        }
*/


    return 0;
}

void openFile(ifstream &inF, string fileName)
{

inF.open(fileName.c_str());

       if(inF.fail())
        {
            cout << "Well you just done goof'd son... try again";
            exit (1);
        }
}



