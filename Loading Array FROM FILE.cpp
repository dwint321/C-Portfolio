// --------------------------------------------------------------------
//  0. Complete function LoadArray to read values into an array
//     from an open input file.
//  1. Declare an array NUM of capacity 6.
//  2. Read name of input file.
//  3. Open the input file.
//  4. Call the LoadArray function.
//  5. Display the array size, followed by the values in the array.
//
//  Example: input file: 2 4 2 4         ==> output 4  2 4 2 4
//           input file: 1 2 3 4 5 6 7 8 ==> output 6 1 2 3 4 5 6
//           empty input file:           ==> output 0
//
// --------------------------------------------------------------------
#include <iostream>
#include <fstream>
using namespace std;
void LoadArray(istream & inF, int A[], int CAPACITY, int & Asize)
{
int i = 0;

   while (inF >> A[i] && i < CAPACITY)
   {
      i++;
   }
   Asize = i;
}

int main()
{
    const int Cap = 6;
int NUM[Cap];
string Fname;
ifstream inF;
int Asize = 0;
cin >> Fname;

inF.open(Fname.c_str());

LoadArray(inF, NUM, Cap, Asize);

cout << Asize << " ";

for(int q = 0; q < Asize; q++)
    cout << NUM[q] << " ";



   cout << endl; //DO NOT DELETE.
   return 0;
}//main
