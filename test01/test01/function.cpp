#define _CRT_SECURE_NO_WARNINGS 1
#include "function.h"
//��ȡjson�ļ�
void readfile(const char* FileName)
{
	ifstream fin;
	fin.open(FileName, ios::in);
	if (!fin.is_open())
	{
		cout << "2.���ļ�ʧ��" << endl;
		return;
	}
	char buff[1024] = { 0 };
	while (fin.getline(buff, sizeof(buff)))
	{
		cout << buff << endl;
	}
	fin.close();
}

//д��json�ļ�
void writefile(const char* FileName)
{
	ofstream fout;
	fout.open(FileName, ios::out);
	if (!fout.is_open())
	{
		cout << "1.�ļ���ʧ��" << endl;
		return;
	}
	fout << "{\"name\":\"gaoruoyu\",\"age\":\"18\"}" << endl;
	fout.close();
}