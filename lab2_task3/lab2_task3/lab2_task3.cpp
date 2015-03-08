#include "stdafx.h"
#include "Process.h"

using namespace std;

int _tmain(int argc, _TCHAR* argv[])
{
	string s;
	msi m;
	while (getline(cin, s))
	{
		AddToMap(m, s);
	}
	for (auto s : m)
	{
		cout << s.first << " - " << s.second << " times" << endl;
	}
}

