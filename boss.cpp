#include"boss.h"

Boss::Boss(int id, string name, int did)
{
	this->m_id = id;
	this->m_name = name;
	this->m_deptid = did;
}

void Boss::ShowInfo()
{
	cout << "职工编号：" << this->m_id << "\t"
		<< "职工姓名：" << this->m_name << "\t"
		<< "职工岗位：" << this->Getdeptname() << "\t"
		<< "岗位职责：管理公司所有事物" << endl;
}

string Boss::Getdeptname()
{
	return string("总裁");
}