#include "boneyard.h"

using namespace std;

ostream &operator<<(ostream& out, Boneyard &by)
{
	out << "Boneyard: ";
	for(const auto &it : by)
		out << it << " ";
	out << "\n";
}