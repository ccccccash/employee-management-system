#include"employee.h"

Employee::Employee(int id, string name, int did)
{
	this->m_id = id;
	this->m_name = name;
	this->m_deptid = did;
}

void Employee::ShowInfo()
{
	cout << "ְ����ţ�" << this->m_id << "\t"
		<< "ְ��������" << this->m_name << "\t"
		<< "ְ����λ��" << this->Getdeptname() << "\t"
		<< "��λְ����ɾ�����������" << endl;
}

string Employee::Getdeptname()
{
	return string("Ա��");
}