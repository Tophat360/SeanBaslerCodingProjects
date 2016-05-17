//----------------------------------------------------------------------------
//Programmer: Sean Basler    Student ID: 12366509
//Lab: 15, "gdb"             Filename: reverse.cpp
//Due Date: 05/06/14         Class: CSc54, Section C
//----------------------------------------------------------------------------
#include <iostream>
using namespace std;
void readArray(char a[], int &size );
void printArray(char a[], int size);
void printRArray(char a[], int size);

int main ()
{
  char a[5];
  int size;
  char cAgain;
  
  do
  {  
    readArray(a, size);
    printArray(a, size);
    cout << "The Reversed array " << endl;
    printRArray(a, size);    
    
    cout << endl;

    cout << "Repeat?? " ;
    cin >> cAgain;
  } while(cAgain == 'y');
  return 0;
  

}
void readArray(char a[], int &size )
{
  cout << "what is the size "  ;
  cin >> size;
  cout << "Enter the array  "<< endl;
  for (int i=0; i< size ; i++)
  {
    cin >> a[i];
  }
}

void printArray(char a[], int size)

{
  for (int i = 0; i < size ; i++)
  {
    cout << a[i] << " " ;
 
  }
  cout << endl;
  return ;
}
void printRArray(char a[], int size)
{
  for (int i = (size-1); i >= 0 ; i--)
  {
    cout << a[i] << " " ;
  }
  cout << endl;
  return ;
}
