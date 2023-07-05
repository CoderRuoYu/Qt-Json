#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
#include <sstream>
#include <fstream>
using namespace std;
stringstream ss;

bool is_obj()
{
	
}
bool is_json(const string str)
{
	if (str.length() == 0)
	{
		return false;
	}
	if 
	if (str[i] == '{')
	{
		return is_obj();
	}
	else if (str[i] == '[')
	{

	}
	else if (str[i] == '"')
	{

	}
	else if (str[i] == 't' || str[i] == 'f')
	{

	}
	else if (str[i] == 'n')
	{

	}
	else
	{

	}

}
int main()
{
	fstream file("text.txt");
	ss<< file.rdbuf();
	return 0;
}