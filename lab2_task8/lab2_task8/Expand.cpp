#include "stdafx.h"
#include "Expand.h"

using namespace std;

string ExpandTemplate(const string &tpl, const WordAccordances &params)
{
	string s = tpl;
	vector<int> indexes;
	vector<pair<size_t, string>> replaces;
	for (size_t i = 0; i < tpl.size(); i++)
	{
		indexes.push_back(i);
		replaces.push_back(make_pair(0, ""));
	}

	for (auto it = params.crbegin(); it != params.crend(); it++)
	{
		size_t strSize = (it->first).size();

		if (strSize == 0)
		{
			break;
		}
		size_t found = s.find(it->first);
		while (found != string::npos)
		{
			s.erase(found, strSize);
			replaces[indexes[found]] = make_pair(strSize, it->second);
			indexes.erase(indexes.begin() + found, indexes.begin() + found + strSize);
			found = s.find(it->first);
		}
	}

	s = "";
	size_t i = 0;
	while (i < tpl.size())
	{
		if (replaces[i].first > 0)
		{
			s += replaces[i].second;
			i += replaces[i].first;
		}
		else
		{
			s += tpl[i];
			i++;
		}
	}

	return s;
}