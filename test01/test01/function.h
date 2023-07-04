#pragma once
#include <iostream>
#include <fstream>
#include <map>
#include <string>
#include <vector>
using namespace std;
//const char* _Filename,
//读取json文件
void readfile(const char* FileName);
//写入json文件
void writefile(const char* FileName);

//创建一个json值的虚类
class jsonValue
{
public:
	virtual string ValuetoString()const = 0;
};
//bool类型值的类
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
//NULL类型的类
class jsonNull :public jsonValue
{
public:
	string ValuetoString()const
	{
		return "NULL";
	}
};
//整形类型的类
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
//浮点型类型的类
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
//字符类型
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
//json对象
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