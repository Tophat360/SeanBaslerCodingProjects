//-----------------------------------------------------------------------
// Programmer: Sean Basler           Student ID: 12366509 
// Lab: 12, "Classes"                Filename: Lab12.cpp
// Due Date: 04/08/14                Class: CSc54, Section C
//------------------------------------------------------------------------
#include <iostream>
#include <ctime>
#include <cstdlib>
using namespace std;
//Classes
class ClassRoom
{
  public:
    
    //Desc: the classId is set to the member variable id of the object
    // Pre: none
    //Post: the classId is set to the id of the object
    void setId(string classid);
    
    //Desc: the boardType is set to the member variable board of the object
    // Pre: boardtype is either b(BLACK) or w(WHITE) only
    //Post: the boardType is set to the board of the object
    void setBoard(char boardType);
    
    //Desc: the cap is set to the member variable capacity of the object
    // Pre: cap is in the range of 50 and 75
    //Post: the capacity is set to the capacity of the object
    void setCapacity(int cap);
    
    //Desc: returns the classId of the object
    // Pre: none
    //Post: returns the id to the calling function
    string getId();
  
    //Desc: the type of the board is returned
    // Pre: none
    //Post: a b or w is returned representing BLACK or WHITE respectively
    char getBoard();
  
    //Desc: the capacity of the classRoom is returned 
    // Pre: none
    //Post: returns the capacity of the classRoom             
    int getCap();
  
  private:
    string id;
    char board;
    int capacity;                            
};

//functions

//Desc: generates a b or a w with equal randomness
// Pre: none
//Post: returns b or w to the calling function
char generateBandW();

//Desc: generates an integer between 50 - 75
// Pre: none
//Post: returns an integer between 50 - 75
int generateCap();

int main()
{
  //sets the clock
  srand(time(NULL));
    
  //local variables
  int userCap;
  char userBoard;
  bool classCond1, classCond2;
  
  //local object declaration 
  ClassRoom room1, room2;
  
  //greeting
  cout<<"Welcome to resource Scheduler"<<endl<<endl;
  
  //room 1 is set
  room1.setId("T251");
  room1.setBoard(generateBandW());
  room1.setCapacity(generateCap());
  
  //room 2 is set
  room2.setId("CS216");
  room2.setBoard(generateBandW());
  room2.setCapacity(generateCap());
  
  //user input section
  cout<<"TAKING USERS REQUIREMENTS"<<endl<<endl;
  
  //user prompts
  cout<<"The class capacity that you are looking for?: ";
  cin>>userCap;
  cout<<"Do you need a blackboard(b) or whiteboard(w)?: ";
  cin>>userBoard;
  cout<<endl;
  
  //Processing
  cout<<"PLEASE WAIT WHILE WE PROCESS YOUR REQUEST"<<endl<<endl;
  classCond1 = (userCap <= room1.getCap() && userBoard == room1.getBoard());
  classCond2 = (userCap <= room2.getCap() && userBoard == room2.getBoard());
  if (classCond1 && classCond2)
  {
    cout<<room1.getId()<<" satisfies your requirements"<<endl;
    cout<<room2.getId()<<" satisfies your requirements"<<endl;
  }
  else if(classCond1)
    cout<<room1.getId()<<" satisfies your requirements"<<endl;
  else if(classCond2)
    cout<<room2.getId()<<" satisfies your requirements"<<endl;
  else 
    cout<<"No classroom satisfies your requirements"<<endl;
  
  //goodbye
  cout<<endl;
  cout<<"Thanks for using the resource scheduler"<<endl;
  return 0;
}  

void ClassRoom::setId(string classid)
{
  id = classid;
  return;
}

void ClassRoom::setBoard(char boardType)
{
  board = boardType;
  return; 
}

void ClassRoom::setCapacity (int cap)
{
  capacity = cap;
  return;
}

string ClassRoom::getId()
{
  return id;
}

char ClassRoom::getBoard()
{
  return board;
}

int ClassRoom::getCap()
{
  return capacity;
}

char generateBandW()
{  
  //local constants 
  const int CHANCE = 2;
  
  //local variable definition
  char boardtype;
  int randnum;
  
  //letter generation
  randnum = rand()%CHANCE;
  if (randnum == 0)
    boardtype = 'b';
  else
    boardtype = 'w';
  cout<<"generated board type: "<<boardtype<<endl;  
  return boardtype;
}

int generateCap()
{  
  //local constants
  const int UP = 75 + 1, LOW = 50;//the capacity's upper and lower bounds
  
  //local variables
  int theCap;
  
  //capacity generation
  theCap = ((rand()%UP-LOW)+LOW);
  cout<<"generated class capacity: "<<theCap<<endl<<endl;  
  return theCap;
}
