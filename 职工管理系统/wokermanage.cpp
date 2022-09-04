#include "wokermanage.h"
#include<vector>

Wokermanage::Wokermanage()
{
	ifstream ifs;
	ifs.open(FILENAME, ios::in);

	//1，文件不存在
	if (!ifs.is_open())
	{
		//cout << "文件不存在" << endl;
		m_empnum = 0;
		m_emparry = NULL;
		m_FileIsEmpty = true;
		ifs.close();
		return;
	}
	//2,文件为空
	char ch;
	ifs >> ch;
	if (ifs.eof())
	{
		//cout << "文件为空" << endl;
		m_empnum = 0;
		m_emparry = NULL;
		m_FileIsEmpty = true;
		ifs.close();
		return;
	}
	//3,文件存在
	int num = this->get_EmpNum();
	//cout << "当前职工人数为  " << num << endl;
	this->m_empnum = num;
	//开辟空间
	this->m_emparry = new Woker * [this->m_empnum];
	//将文件中的数据存到数组中
	this->init_Emp();
	
};

Wokermanage::~Wokermanage()
{
	if (this->m_emparry != NULL)
	{
		delete[]this->m_emparry;
		this->m_emparry = NULL;
	}
};

void Wokermanage::Exit_sys()
{
	cout << "欢迎下次使用" << endl;
	system("pause");
	exit(0);

}

void Wokermanage::Show_menu()
{
	cout << "*****************************************" << endl;
	cout << "********** 欢迎使用职工管理系统 *********" << endl;
	cout << "************* 0.退出管理程序 ************" << endl;
	cout << "************* 1.增加职工信息 ************" << endl;
	cout << "************* 2.显示职工信息 ************" << endl;
	cout << "************* 3.删除离职员工 ************" << endl;
	cout << "************* 4.修改职工信息 ************" << endl;
	cout << "************* 5.查找职工信息 ************" << endl;
	cout << "************* 6.按照编号排序 ************" << endl;
	cout << "************* 7.清空所有文档 ************" << endl;
	cout << "*****************************************" << endl;
}

void Wokermanage::Add_emp()
{
	cout << "请输入您要添加的职工数量：" << endl;
	int addnum = 0;
	cin >> addnum;
	if (addnum > 0)
	{
		//计算新添加的人数空间大小
		int newsize = this->m_empnum + addnum;
		//根据大小开辟空间
		vector<Woker*>v;
		
		//将原来空间下的数据拷贝到新空间
		if (this->m_emparry != NULL)
		{
			for (int i = 0; i < this->m_empnum; i++)
			{
				v.push_back(this->m_emparry[i]);
			}
		}
		//添加新数据
		for (int i = 0; i < addnum; i++)
		{
			int id = 0;
			string name;
			int dept = 0;

			cout << "请输入第 " << i + 1 << "个新职工编号" << endl;
			cin >> id;
			//判断职工编号是否重复
			int index = -1;
			for (vector<Woker*>::iterator it = v.begin(); it != v.end(); it++)
			{
				if ((*it)->m_id == id)
				{
					index = 0;
					break;
				}
			}

			if (index == -1)
			{
				cout << "请输入第 " << i + 1 << "个新职工姓名" << endl;
				cin >> name;
				cout << "请输入第 " << i + 1 << "个新职工岗位" << endl;
				cout << "1：普通职工" << endl;
				cout << "2：经理" << endl;
				cout << "3：老板" << endl;
				cin >> dept;

				Woker* woker = NULL;
				switch (dept)
				{
				case 1:
					woker = new Employee(id, name, 1);
					break;
				case 2:
					woker = new Manager(id, name, 2);
					break;
				case 3:
					woker = new Boss(id, name, 3);
					break;
				default:
					break;
				}
				//将创建的职工指针保存到数组中			
				v.push_back(woker);								
			}
			else
			{								
				addnum--;
				cout << "您输入的职工编号已存在，添加失败请重新添加" << endl;
			}

		}
		int newsize1 = this->m_empnum + addnum;				
		//释放原有的空间
		delete[]this->m_emparry;
		//更改新空间指向
		
		memcpy(this->m_emparry, &v[0], v.size() * sizeof(v[0]));
		//更新新的职工人数
		this->m_empnum = newsize1;
		this->m_FileIsEmpty = false;
		cout << "成功添加" << addnum << "名新职工！" << endl;
		
		this->save();
		
	}
	else
	{
		cout << "您的输入有误请重新输入" << endl;
	}
	
	system("pause");
	system("cls");
}

void Wokermanage::save()
{
	ofstream ofs;
	ofs.open(FILENAME, ios::out);

	for (int i = 0; i < m_empnum; i++)
	{
		ofs << this->m_emparry[i]->m_id << "  " <<
			this->m_emparry[i]->m_name << "  " <<
			this->m_emparry[i]->m_deptid << endl;
	}
	ofs.close();
}

int Wokermanage::get_EmpNum()
{
	ifstream ifs;
	ifs.open(FILENAME, ios::in);

	int id;
	string name;
	int did;
	int num = 0;
	while (ifs>>id&&ifs>>name&&ifs>>did)
	{
		num++;
	}
	return num;
}

void Wokermanage::init_Emp()
{
	ifstream ifs;
	ifs.open(FILENAME, ios::in);
	int id;
	string name;
	int did;
	int index = 0;

	while (ifs >> id && ifs >> name && ifs >> did)
	{
		Woker* woker = NULL;
		if (did == 1)
		{
			woker = new Employee(id, name, did);
		}
		else if (did == 2)
		{
			woker = new Manager(id, name, did);
		}
		else
		{
			woker = new Boss(id, name, did);
		}
		this->m_emparry[index] = woker;
		index++;
	}
	ifs.close();
}

void Wokermanage::show_Emp()
{
	if (this->m_FileIsEmpty)
	{
		cout << "记录为空" << endl;
	}
	else
	{
		for (int i = 0; i < this->m_empnum; i++)
		{
			this->m_emparry[i]->ShowInfo();
		}
	}
	system("pause");
	system("cls");
}

void Wokermanage::del_Emp()
{
	if (this->m_FileIsEmpty)
	{
		cout << "文件不存在或记录为空" << endl;
	}
	else
	{
		cout << "请输入您要删除的职工编号:" << endl;
		int id = 0;
		cin >> id;
		int index = this->is_Exist(id);
		if (index != -1)
		{
			for (int i = index; i < this->m_empnum - 1; i++)
			{
				this->m_emparry[i] = this->m_emparry[i + 1];
			}
			this->m_empnum--;
			this->save();
			cout << "删除成功" << endl;
		}
		else
		{
			cout << "职工不存在" << endl;
		}
	}
	system("pause");
	system("cls");
}

int Wokermanage::is_Exist(int id)
{
	int index = -1;
	for (int i = 0; i < this->m_empnum; i++)
	{
		if (this->m_emparry[i]->m_id == id)
		{
			index = i;
			break;
		}
	}
	return index;
}

void Wokermanage::change_info()
{
	if (this->m_FileIsEmpty)
	{
		cout << "文件不存在或记录为空" << endl;
	}
	else
	{
		cout << "请输入您要修改的职工编号:" << endl;
		int id = 0;
		cin >> id;
		int index = this->is_Exist(id);
		if (index != -1)
		{
			delete this->m_emparry[index];
			string name;
			int new_id = 0;
			int select = 0;
			Woker* woker = NULL;
			cout << "查到编号为：" << id << "的员工" << endl;
			cout << "请输入修改后的员工编号" << endl;
			cin >> new_id;
			cout << "请输入修改后的员工姓名" << endl;
			cin >> name;
			cout << "请输入修改后的员工部门编号" << endl;
			cout << "1:普通员工" << endl;
			cout << "2:经理" << endl;
			cout << "3:老板" << endl;
			cin >> select;
			switch (select)
			{
			case 1:woker = new Employee(new_id, name, select); break;
			case 2:woker = new Manager(new_id, name, select); break;
			case 3:woker = new Boss(new_id, name, select); break;
			default:
				break;
			}
			this->m_emparry[index] = woker;
			cout << "修改成功" << endl;
			this->save();
		}
		else
		{
			cout << "职工不存在" << endl;
		}
	}
	system("pause");
	system("cls");
}

void Wokermanage::find_emp()
{
	if (this->m_FileIsEmpty)
	{
		cout << "文件不存在或记录为空" << endl;
	}
	else
	{
		cout << "请选择您要查找的方式:" << endl;
		cout << "1:按职工编号查找" << endl;
		cout << "2:按职工姓名查找" << endl;

		int type_num = 0;
		cin >> type_num;
		if (type_num == 1)
		{
			cout << "请输入您要查找的职工编号" << endl;
			int find_num = 0;
			cin >> find_num;
			int index = this->is_Exist(find_num);
			if (index != -1)
			{
				this->m_emparry[index]->ShowInfo();
			}
			else
			{
				cout << "职工不存在" << endl;
			}
		}
		else if (type_num == 2)
		{
			cout << "请输入您要查找的职工姓名" << endl;
			string find_name;
			bool flag = false;
			cin >> find_name;
			for (int i = 0; i < m_empnum; i++)
			{
				if (m_emparry[i]->m_name == find_name)
				{
					cout << "找到姓名为： " << find_name << " 的职工" << endl;
					flag = true;
					m_emparry[i]->ShowInfo();
				}
			}
			if (flag = false)
			{
				cout << "查无此人" << endl;
			}
		}
		else
		{
			cout << "输入有误" << endl;
		}
	}
	system("pause");
	system("cls");
}

void Wokermanage::Sort_Emp()
{
	if (this->m_FileIsEmpty)
	{
		cout << "文件不存在或文件为空" << endl;
		system("pause");
		system("cls");
	}
	else
	{
		cout << "请选择您要排列的方式" << endl;
		cout << "1:升序排列" << endl;
		cout << "2:降序排列" << endl;
		int select = 0;
		cin >> select;
		
		for (int i = 0; i < m_empnum; i++)
		{
			int minOrmax = i;
			for (int j = i + 1; j < m_empnum; j++)
			{
				if (select == 1)//升序
				{
					if (this->m_emparry[minOrmax]->m_id > this->m_emparry[j]->m_id)
					{
						minOrmax = j;
					}
				}
				else//降序
				{
					if (this->m_emparry[minOrmax]->m_id < this->m_emparry[j]->m_id)
					{
						minOrmax = j;
					}
				}

			}

			if (i != minOrmax)
			{
				Woker* temp = this->m_emparry[i];
				this->m_emparry[i] = this->m_emparry[minOrmax];
				this->m_emparry[minOrmax] = temp;
			}
		}
		
		cout << "排序成功！排序后的结果为：" << endl;
		this->save();
		this->show_Emp();

	}
}

void Wokermanage::Clear_All()
{
	if (this->m_FileIsEmpty)
	{
		cout << "文件不存在或文件为空" << endl;
		
	}
	else
	{
		cout << "您正在执行删库跑路操作请确认！" << endl;
		cout << "1:确定" << endl;
		cout << "2:返回" << endl;
		int select = 0;
		cin >> select;
		if (select == 1)
		{
			ofstream ofs;
			ofs.open(FILENAME, ios::trunc);
			ofs.close();
			for (int i = 0; i < this->m_empnum; i++)
			{
				delete this->m_emparry[i];
				this->m_emparry[i] = NULL;

			}
			this->m_empnum = 0;
			delete[]this->m_emparry;
			this->m_emparry = NULL;
			this->m_FileIsEmpty = true;
			cout << "文档已清空" << endl;
		}
		

	}
	system("pause");
	system("cls");
}