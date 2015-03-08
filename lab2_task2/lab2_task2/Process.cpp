#include "stdafx.h"
#include "Process.h"

using namespace std;

string RemoveExtraSpaces(const string &arg)
{
	string newString = "";
	int lastIndex = arg.length() - 1;
	while (lastIndex >= 0 && arg[lastIndex] == ' ')
	{
		lastIndex--;
	}
	bool wasSpace = true;
	for (int i = 0; i <= lastIndex; i++)
	{
		if (arg[i] == ' ')
		{
			if (!wasSpace)
			{
				newString += arg[i];
				wasSpace = true;
			}
		}
		else
		{
			wasSpace = false;
			newString += arg[i];
		}
	}
	return newString;
}