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
	
	//显示菜单
	void Show_menu();
	//退出系统
	void Exit_sys();
	//添加职工
	void Add_emp();

	//保存文件
	void save();
	//判断文件是否为空
	bool m_FileIsEmpty;
	//统计人数
	int get_EmpNum();
	//初始化职工
	void init_Emp();

	//显示职工
	void show_Emp();
	//删除职工
	void del_Emp();
	int is_Exist(int id);//判断职工是否存在并返回数组中的位置

	//修改职工信息
	void change_info();

	//查找职工信息
	void find_emp();

	//按照职工ID排序
	void Sort_Emp();

	//清空所有文档
	void Clear_All();

	//记录职工人数
	int m_empnum;
	//职工数组指针
	Woker** m_emparry;

	~Wokermanage();

};



