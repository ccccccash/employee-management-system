#pragma once
#include<iostream>
using namespace std;

class Woker
{
public:
	//显示个人信息
	virtual void ShowInfo() = 0;
	//获取岗位名称
	virtual  string Getdeptname() = 0;

	//职工编号
	int m_id;
	//职工姓名
	string m_name;
	//部门编号
	int m_deptid;
};