#pragma once
#include<iostream>
using namespace std;

class Woker
{
public:
	//��ʾ������Ϣ
	virtual void ShowInfo() = 0;
	//��ȡ��λ����
	virtual  string Getdeptname() = 0;

	//ְ�����
	int m_id;
	//ְ������
	string m_name;
	//���ű��
	int m_deptid;
};