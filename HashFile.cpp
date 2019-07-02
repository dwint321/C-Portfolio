// ------------------------------------------------------------------
// File name:   HashFile.cpp
//
// Assign ID:   PROG1
// Due Date:    9/20/2017 at 12pm
//
// Purpose:     Hash content of text file into single double value.
//
// Formula:     hash = Sum over char c { freq(c)*c}
//
// Author:      dwint David Wint
//
// ------------------------------------------------------------------

    #include <iostream>
    #include <fstream>
    #include <iomanip>
    using namespace std;

    // ----------------------------------------------------------------------
    // Compute hash value.
    // ----------------------------------------------------------------------
    long SymbolHash(int Freq[])
    {
       long hashVal = 0;
       for (int i=0; i< 256; i++)
       {
          hashVal = hashVal + i * Freq[i];
       }

       return hashVal;
    }//SymbolHash

    // ----------------------------------------------------------------------
    // Display non-zero symbol frequencies.
    // ----------------------------------------------------------------------
    void Show_Frequencies(int Freq[])
    {
       int outCount = 0;  // #values on output line.

       cout << "\n\nSYMBOL FREQUENCIES: \n";
       for (int i=0; i< 256; i++)
       {
          if (Freq[i] > 0)
          {
             outCount = outCount % 10;
             if (outCount++ == 0) cout << endl;
             cout << setw(3)  << Freq[i] << (char) i << "  ";
          }
       }
    }//Show_Frequencies



    int main(int argc, char * argv[])
    {
       char symbol;      // Non-whitespace character from input file.
       int Freq[256];    // #times each symbol occurs in file.

       long hashVal;   // Resulting hash value.
       int i, j, k;      // Loop variables.

       char inFileName[80];  // Name of input file.
       ifstream inF;         // Input file stream.


        //-| ----------------------------------------------------------------------
     //-| 0. Print copyright.
     //-| ----------------------------------------------------------------------
     cout << "\n\n(c) 2014, cop3330joe Dr. Jones \n\n";


     //-| ----------------------------------------------------------------------
     //-| 1. Initialize frequencies to zero.
     //-| ----------------------------------------------------------------------
     for (i=0; i< 256; i++)
        Freq[i] = 0;

     //-| ----------------------------------------------------------------------
     //-| 2. Verify that file name has been passed; if not, read file name.
     //-| ----------------------------------------------------------------------
     if (argc >= 2)
        strcpy(inFileName, argv[1]);
     else
     {
        cout << "\n\nEnter name of input file: ";
        cin >> inFileName;
     }


     //-| ----------------------------------------------------------------------
     //-| 3. Open input file. Exit if file not foundt found.
     //-| ----------------------------------------------------------------------
     inF.open(inFileName);
    if (inF.fail())
     {
       cout << "\n\nFATAL ERROR: Can not open file " << inFileName << endl;
       return 0;
    }


    //-| ----------------------------------------------------------------------
    //-| 4. Repeat until end of file is reached.
    //-|    4.1 Read character.
   //-|    4.2 Increment character frequency.
   //-| ----------------------------------------------------------------------
   while (inF >> symbol)
   {
      Freq[symbol]++;
   }


   //-| ----------------------------------------------------------------------
   //-| 5. Display non-zero symbol frequencies.
   //-| ----------------------------------------------------------------------
   Show_Frequencies(Freq);

   //-| ----------------------------------------------------------------------
   //-| 6. Calculate file has value.
   //-| ----------------------------------------------------------------------
   hashVal = SymbolHash(Freq);
   cout << "\n\n" << inFileName << " HASH VALUE = " << hashVal << endl;


   //-| ----------------------------------------------------------------------
  //-| ------------------------------------------------------
   //-| 0. Print copyright.
   //-| ------------------------------------------------------
   //-| ----------------------------------------------------------------------
cout << "\n\n(c) 2017, dwint David Wint \n\n";

    return 0;
}//main
