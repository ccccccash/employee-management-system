#pragma once
#include<iostream>
using namespace std;
#include"woker.h"
#include"employee.h"
#include"boss.h"
#include"manager.h"
#include<fstream>
#define FILENAME "empfile.txt"

class Wokermanage
{
public:
	Wokermanage();
	
	//��ʾ�˵�
	void Show_menu();
	//�˳�ϵͳ
	void Exit_sys();
	//���ְ��
	void Add_emp();

	//�����ļ�
	void save();
	//�ж��ļ��Ƿ�Ϊ��
	bool m_FileIsEmpty;
	//ͳ������
	int get_EmpNum();
	//��ʼ��ְ��
	void init_Emp();

	//��ʾְ��
	void show_Emp();
	//ɾ��ְ��
	void del_Emp();
	int is_Exist(int id);//�ж�ְ���Ƿ���ڲ����������е�λ��

	//�޸�ְ����Ϣ
	void change_info();

	//����ְ����Ϣ
	void find_emp();

	//����ְ��ID����
	void Sort_Emp();

	//��������ĵ�
	void Clear_All();

	//��¼ְ������
	int m_empnum;
	//ְ������ָ��
	Woker** m_emparry;

	~Wokermanage();

};



