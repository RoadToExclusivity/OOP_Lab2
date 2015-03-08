#include "stdafx.h"
#include "Process.h"

using namespace std;

void AddToMap(msi &m, string s)
{
	string cur = "";
	for (size_t i = 0; i < s.length(); i++)
	{
		if (s[i] == '\n' || s[i] == '\t' || s[i] == ' ')
		{
			if (cur.length() > 0)
			{
				m[cur]++;
			}
			cur = "";
			continue;
		}
		cur += s[i];
	}
	if (cur.length() > 0)
	{
		m[cur]++;
	}
}