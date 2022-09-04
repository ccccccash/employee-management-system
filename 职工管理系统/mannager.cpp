#include"manager.h"

Manager::Manager(int id, string name, int did)
{
	this->m_id = id;
	this->m_name = name;
	this->m_deptid = did;
}

void Manager::ShowInfo()
{
	cout << "职工编号：" << this->m_id << "\t"
		<< "职工姓名：" << this->m_name << "\t"
		<< "职工岗位：" << this->Getdeptname() << "\t"
		<< "岗位职责：完成老板交代的任务并下发给员工" << endl;
}

string Manager::Getdeptname()
{
	return string("经理");
}