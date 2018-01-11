/******************************************************************************
* Name: Austin Fouch
* Project: 1 Longana
* Class: CMPS 366 OPL
* Date: 10/18/2017
******************************************************************************/
#include "boneyard.h"

using namespace std;

ostream &operator<<(ostream& out, Boneyard &by)
{
	for(const auto &it : by)
		out << it << " ";
	out << endl;
}

void Boneyard::clear()
{
 while(!this->tiles.empty())
 	this->tiles.pop_back();
}
