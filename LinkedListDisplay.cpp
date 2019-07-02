#include<iostream>

using namespace std;

struct NODE
{
int val;
NODE *next;

 NODE(int V, NODE *n)
 {
   val = V;
   next = n;
 }

};

int main()
{

NODE *Head = NULL;
NODE *Head2 = NULL;
Head = new NODE(9, NULL);
Head = new NODE(90, Head);
int Num;
int Sum = 0;
int Sum2 = 0;
int A[7] = {-1, 2, 3, -5, 6, 17, -3};

//Input num from key board
//update: add for loop to populate it with an array


for(int i = 0; i < 7; i++)
{
Head = new NODE(A[i], Head);
}


//inputs from keyboard
//update: it ends in 0 need to fix
/*
while(Num != -0)
{
    cin >> Num;
Head = new NODE(Num, Head);
}
*/
//displays the List
NODE *p = Head;

        while(p->next!=NULL)
        {
           cout << p -> val << " ";
           /*-Calculate Sum-*/
            Sum += p -> val;
           /*---------------*/
           p = p->next;
        }//end while
        cout << endl << endl;

cout << "Sum: " << Sum;

cout << endl << endl;

/*Display different List ex: List 2 */
cout << "This is the list populated by the Array." << endl;
cout << endl;

NODE *p2 = Head2;

Head2 = new NODE(2, NULL);

           for(int i = 0; i < 7; i++)
           {
                Head2 = new NODE(A[i], Head2);
           }

        while(p2!=NULL)
        {
           cout << p2 -> val << " ";
           /*-Calculate Sum-*/
            Sum2 += p2 -> val;
           /*---------------*/
           p2 = p2->next;
        }//end while

        cout << "Array Sum: " << Sum2;

cout << endl;
return 0;

}//main
/*  //-| ******* MAKE YOUR CHANGES BELOW ***********
  //-|----------------------------------------------------------------------------
  //-| Find the largest value in list L2. Then display that value.
  //-| Display -777 if the list is empty.
  //-|----------------------------------------------------------------------------
NODE *Head = L2;

int Max = *Head;

if(Head == NULL)
{
    cout << -777;
}

  else
  {
     while(Head != NULL)
     {
        if(Max < val)

        Max = val;

        Head = Head -> next;
     }

cout << Max;
   cout << " MAX" << endl; return 0; // DO NOT MOVE, MODIFY or DELETE.
}//main
~~~~~~~~~~~~~~~~~~~~~~Finding the k'th Value~~~~~~~~~~~~~~~~~~~~~~~~~
NODE *Head = L2;
NODE *ptr = Head;

int kounter = 1, k;

cin >> k;
     while(Head != NULL)
     {
       kounter++;
       Head = Head -> next;
     }

if(Head == NULL || k < 1 || k > kounter)
{
 return 0; // DO NOT MOVE, MODIFY or DELETE.
}
else

     while(Head != NULL &&)
     {
       kounter++;

         if(kounter == k)
         cout << Head -> val;

     }
   cout << " PICK" << endl; return 0; // DO NOT MOVE, MODIFY or DELETE.
}//main


*/

