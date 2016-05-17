//-----------------------------------------------------------------------
// Programmer: Sean Basler           Student ID: 12366509 
// Lab: 10, "NTCA"                  Filename: Lab10.cpp
// Due Date: 04/01/14                 Class: CSc54, Section C
//------------------------------------------------------------------------
#include <iostream>
#include <cstring>
using namespace std;

//global variables
const unsigned int MAXLENGTH = 11;

//function declarations 

//Description: Shows password characters as asterisks
//        Pre: None
//       Post: Shows password characters as asterisks
void printPassword(const char password[]);

//Description: Greets user
//        Pre: None
//       Post: Outputs greeting
void greeting();

//Description: Gives result and says farwell to the user 
//        Pre: None
//       Post: Outputs the result
void Result(const char username[], const char firstname[], 
            const char lastname[], const char password[]);

//Description: Prompts for password and confirms it
//        Pre: None
//       Post: Creates password
void getPassword(char password1[]);

//Main program
int main()
{ 
  //local constants
  const unsigned int USERLENGTH = (MAXLENGTH * 2) - 1;
  //Null terminated array declarations 
  char firstName[MAXLENGTH];
  char lastName[MAXLENGTH];
  char userName[USERLENGTH];
  char passWord[MAXLENGTH];
   
  //function calls and application
  greeting();
  //Name manipulation
  cout<<"Enter first name: ";
  cin>>firstName;
  cout<<"Enter last name : ";
  cin>>lastName;
  cout<<endl;
  strcpy(userName, firstName);
  strcat(userName, lastName);  
  
  getPassword(passWord);
  Result(userName, firstName, lastName, passWord);
  return 0;
}

//function definitions

void getPassword(char password1[])
{
  //local constants
  const unsigned int MINLENGTH = 7;
  
  //local variables
  char password2[MAXLENGTH];//comparison array 
  
  //Creates password
  do
  {
    //checks password length
    do
    {
      cout<<"Enter the password (7 -10 characters): ";
      cin>>password1;
      if (strlen(password1) > (MAXLENGTH-1) || strlen(password1) < MINLENGTH)
      {
        cout<<endl;
      }	
    } while (strlen(password1) > (MAXLENGTH-1) || strlen(password1) < MINLENGTH);
    
    //Confirms password
    cout<<"Confirm the password: ";
    cin>>password2;
    cout<<endl;
  } while (strcmp(password1, password2));
    return;  
}

void greeting()
{
  cout<<"Welcome! Please Enter your information to sign up"<<endl<<endl;
}

void Result(const char username[], const char firstname[], 
            const char lastname[], const char password[])
{
  //local constants
  const int BORDERLENGTH = 20;
  
  //functionality
  cout<<"\t";
  for (int i = 0; i < BORDERLENGTH; i++)
  {
    cout<<"*";
  }
  cout<<endl;
  cout<<"Account information Summary:"<<endl;
  cout<<"\tFirst Name\t\t:"<<firstname<<endl;
  cout<<"\tLast Name\t\t:"<<lastname<<endl;
  cout<<"\tuserName\t\t:"<<username<<endl;
  cout<<"\tpassword\t\t:";
  printPassword(password);
  cout<<endl<<endl;
  cout<<"Thanks!"<<endl;
  return;
}

void printPassword(const char password[])
{
  for (unsigned int i = 0; password[i] != '\0'; i++)
  {
    cout<<"*";
  }
  return;
}
