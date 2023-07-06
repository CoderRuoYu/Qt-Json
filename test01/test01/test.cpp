#define _CRT_SECURE_NO_WARNINGS 1
#include "function.h"

int main()
{
	writefile("test.json");
	readfile("test.json");
	
	//数组和对象的生成
	jsonProject a;
	a.addValue("bool", new jsonBool(true));
	a.addValue("int", new jsonInt(12));
	a.addValue("double", new jsonDouble(1.23));
	a.addValue("string", new jsonString("abc"));
	a.addValue("NULL", new jsonNull);


	jsonArray b;
	b.addValue( new jsonBool(true));
	b.addValue( new jsonInt(12));
	a.addValue("Array", &b);

	cout << a.ValuetoString() << endl;


	return 0;
}