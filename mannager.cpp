#include"manager.h"

Manager::Manager(int id, string name, int did)
{
	this->m_id = id;
	this->m_name = name;
	this->m_deptid = did;
}

void Manager::ShowInfo()
{
	cout << "ְ����ţ�" << this->m_id << "\t"
		<< "ְ��������" << this->m_name << "\t"
		<< "ְ����λ��" << this->Getdeptname() << "\t"
		<< "��λְ������ϰ彻���������·���Ա��" << endl;
}

string Manager::Getdeptname()
{
	return string("����");
}