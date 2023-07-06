#define _CRT_SECURE_NO_WARNINGS 1
#include "function.h"
//读取json文件
void readfile(const char* FileName)
{
	ifstream fin;
	fin.open(FileName, ios::in);
	if (!fin.is_open())
	{
		cout << "2.打开文件失败" << endl;
		return;
	}
	char buff[1024] = { 0 };
	while (fin.getline(buff, sizeof(buff)))
	{
		cout << buff << endl;
	}
	fin.close();
}

//写入json文件
void writefile(const char* FileName)
{
	ofstream fout;
	fout.open(FileName, ios::out);
	if (!fout.is_open())
	{
		cout << "1.文件打开失败" << endl;
		return;
	}
	fout << "{\"name\":\"gaoruoyu\",\"age\":\"18\"}" << endl;
	fout.close();
}