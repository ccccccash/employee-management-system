#include"boss.h"

Boss::Boss(int id, string name, int did)
{
	this->m_id = id;
	this->m_name = name;
	this->m_deptid = did;
}

void Boss::ShowInfo()
{
	cout << "ְ����ţ�" << this->m_id << "\t"
		<< "ְ��������" << this->m_name << "\t"
		<< "ְ����λ��" << this->Getdeptname() << "\t"
		<< "��λְ�𣺹���˾��������" << endl;
}

string Boss::Getdeptname()
{
	return string("�ܲ�");
}