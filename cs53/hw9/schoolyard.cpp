//Programmer: Sean Basler   Class Section: B
//Program: "schoolyard.cpp" Date: 4/19/14
//Desc: This program Defines the member and friend functions of the schoolyard
//      class. 
#include "schoolyard.h"

schoolyard::schoolyard(const short yard, const short building)
{
  if (yard <= MAXDIST && building < yard)
  {
    //sets member variables
    m_yard = yard;
    m_building = building;
    
    //creates total possible area
    for (int i = 0; i < MAXDIST; i++)
    {
      for (int j = 0; j < MAXDIST; j++)
      {
        m_theYard[i][j] = ' ';
      }
    }
    
    //builds school 
    build_school();
  }
  else
    exit(2);
}

void schoolyard::build_school()
{
  //local constants
  const int AMT_TRASH = 10;
  const int CHANCE_TRASH = 10;
  
  //local variables
  short theSchool = getbuilding() - 1, outside = getyard() - 1;
  short trash = ((outside*outside)-(theSchool*theSchool))/AMT_TRASH;
  int randnum;
  
  //building the outer yard
  for (int i = 0; i <= outside; i++)
  {
    for (int j = 0; j <= outside; j++)
    {
      //Makes sure space isn't a T before filling it
      if (m_theYard[i][j] != 'T')
        m_theYard[i][j] = ' ';//blank spaces
      
      //creates a chance of whether or not a space is trash
      randnum = rand()%CHANCE_TRASH;
      if (randnum == 0 && trash != 0 && j > theSchool)
      {
        m_theYard[i][j] = 'T';
        trash = trash - 1;
      }		  
    }
    if (i == (outside - 1) && trash != 0)
    {
      i = 0;
    }
  }	
  
  //building the school 
  for (int i = 0; i <= theSchool; i++)
  {
    for (int j = 0; j <= theSchool; j++)
    {
      m_theYard[i][j] = 'S';
    }
  }
  m_theYard[theSchool][theSchool] = 'D';
}

ostream& operator <<(ostream& out, const schoolyard& yard)
{
  int theGrid = yard.m_yard - 1; 
  for (int i = 0; i <= theGrid; i++)
  {
    for (int j = 0; j <= theGrid; j++)
    {
      out<<yard.m_theYard[i][j];
    }
    out<<endl;
  }
  return(out);
}
