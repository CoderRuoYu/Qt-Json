#pragma once
#include <iostream>
#include <fstream>
#include <map>
#include <string>
#include <vector>
using namespace std;
//const char* _Filename,
//��ȡjson�ļ�
void readfile(const char* FileName);
//д��json�ļ�
void writefile(const char* FileName);

//����һ��jsonֵ������
class jsonValue
{
public:
	virtual string ValuetoString()const = 0;
};
//bool����ֵ����
class jsonBool:public jsonValue
{
public:
	jsonBool(bool value) : _value(value)
	{
		;
	}
	string ValuetoString()const
	{
		return _value ? "true" : "false";
	}
private:
	bool _value;
};
//NULL���͵���
class jsonNull :public jsonValue
{
public:
	string ValuetoString()const
	{
		return "NULL";
	}
};
//�������͵���
class jsonInt:public jsonValue
{
public:
	jsonInt(int value):_value(value)
	{
		;
	}
	string ValuetoString()const
	{
		return to_string(_value);
	}
private:
	int _value;
};
//���������͵���
class jsonDouble :public jsonValue
{
public:
	jsonDouble(double value) :_value(value)
	{
		;
	}
	string ValuetoString()const
	{
		return to_string(_value);
	}
private:
	double _value;
};
//�ַ�����
class jsonString :public jsonValue
{
public:
	jsonString(string value) :_value(value)
	{
		;
	}
	string ValuetoString()const
	{
		return _value;
	}
private:
	string _value;
};
class jsonArray :public jsonValue
{
public:
	void addValue(const jsonValue* value)
	{
		_value.push_back(value);
	}
	string ValuetoString()const
	{
		string result = "[";
		int count = 0;
		for (int i = 0; i < _value.size(); i++)
		{
			result += "\"" + _value[i]->ValuetoString() + "\"";
			if (count < _value.size() - 1)
			{
				result += ",";
			}
			count++;
		}
		result += "]";
		return result;
	}
private:
	vector< const jsonValue*>_value;
};
//json����
class jsonProject :public jsonValue
{
public:
	void addValue(const string& key, const jsonValue* value)
	{
		_value[key] = value;
	}
	string ValuetoString()const
	{
		string result = "{";
		int count = 0;
		for (auto& i : _value)
		{
			result += "\"" + i.first + "\":" + "\"" + i.second->ValuetoString() + "\"";
			if (count < _value.size() - 1)
			{
				result += ",";
			}
			count++;
		}
		result += "}";
		return result;
	}
private:
	map<string, const jsonValue*>_value;
};