#include"employee.h"

Employee::Employee(int id, string name, int did)
{
	this->m_id = id;
	this->m_name = name;
	this->m_deptid = did;
}

void Employee::ShowInfo()
{
	cout << "职工编号：" << this->m_id << "\t"
		<< "职工姓名：" << this->m_name << "\t"
		<< "职工岗位：" << this->Getdeptname() << "\t"
		<< "岗位职责：完成经理交代的任务" << endl;
}

string Employee::Getdeptname()
{
	return string("员工");
}