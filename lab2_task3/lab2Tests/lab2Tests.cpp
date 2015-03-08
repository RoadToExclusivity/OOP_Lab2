#include "stdafx.h"
#include "../lab2_task3/Process.h"

typedef std::pair<std::string, int> psi;

using namespace std;

BOOST_AUTO_TEST_CASE(EmptyString)
{
	string s = "";
	msi m;
	AddToMap(m, s);
	BOOST_CHECK(m.size() == 0);
}

BOOST_AUTO_TEST_CASE(StringWithOnlyDelimiters)
{
	string s = "\t   \t \n\n\t  \n ";
	msi m;
	AddToMap(m, s);
	BOOST_CHECK(m.size() == 0);
}

BOOST_AUTO_TEST_CASE(StringWithDifferentWords)
{
	string s = "one two  three\n";
	msi ans;
	ans.insert(psi("one", 1));
	ans.insert(psi("two", 1));
	ans.insert(psi("three", 1));
	msi m;
	AddToMap(m, s);
	BOOST_CHECK(m == ans);
}

BOOST_AUTO_TEST_CASE(StringWithSameWords)
{
	string s = "one two  one three three three   \n";
	msi ans;
	ans.insert(psi("one", 2));
	ans.insert(psi("two", 1));
	ans.insert(psi("three", 3));
	msi m;
	AddToMap(m, s);
	BOOST_CHECK(m == ans);
}

BOOST_AUTO_TEST_CASE(StringWithOneWord)
{
	string s = "one";
	msi ans;
	ans.insert(psi("one", 1));
	msi m;
	AddToMap(m, s);
	BOOST_CHECK(m == ans);
}