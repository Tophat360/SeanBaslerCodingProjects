//Programmer: Sean Basler   Class Section: B
//Program: "schoolyard.h"   Date: 4/19/14
//Desc: This declares the schoolyard class
#ifndef SCHOOLYARD_H
#define SCHOOLYARD_H 
#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
using namespace std;
//global constant
const int MAXDIST = 25;

//the Class
class schoolyard
{
  public:
    schoolyard(const short yard, const short building);
	short getyard() {return m_yard;}
	short getbuilding() {return m_building;}
	friend ostream& operator <<(ostream& out, const schoolyard& yard);
  private:
    void build_school();
    char m_theYard[MAXDIST][MAXDIST];
	short m_yard;
	short m_building;
};
#endif
