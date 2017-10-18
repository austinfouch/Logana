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
