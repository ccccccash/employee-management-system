#include "wokermanage.h"
#include<vector>

Wokermanage::Wokermanage()
{
	ifstream ifs;
	ifs.open(FILENAME, ios::in);

	//1���ļ�������
	if (!ifs.is_open())
	{
		//cout << "�ļ�������" << endl;
		m_empnum = 0;
		m_emparry = NULL;
		m_FileIsEmpty = true;
		ifs.close();
		return;
	}
	//2,�ļ�Ϊ��
	char ch;
	ifs >> ch;
	if (ifs.eof())
	{
		//cout << "�ļ�Ϊ��" << endl;
		m_empnum = 0;
		m_emparry = NULL;
		m_FileIsEmpty = true;
		ifs.close();
		return;
	}
	//3,�ļ�����
	int num = this->get_EmpNum();
	//cout << "��ǰְ������Ϊ  " << num << endl;
	this->m_empnum = num;
	//���ٿռ�
	this->m_emparry = new Woker * [this->m_empnum];
	//���ļ��е����ݴ浽������
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
	cout << "��ӭ�´�ʹ��" << endl;
	system("pause");
	exit(0);

}

void Wokermanage::Show_menu()
{
	cout << "*****************************************" << endl;
	cout << "********** ��ӭʹ��ְ������ϵͳ *********" << endl;
	cout << "************* 0.�˳�������� ************" << endl;
	cout << "************* 1.����ְ����Ϣ ************" << endl;
	cout << "************* 2.��ʾְ����Ϣ ************" << endl;
	cout << "************* 3.ɾ����ְԱ�� ************" << endl;
	cout << "************* 4.�޸�ְ����Ϣ ************" << endl;
	cout << "************* 5.����ְ����Ϣ ************" << endl;
	cout << "************* 6.���ձ������ ************" << endl;
	cout << "************* 7.��������ĵ� ************" << endl;
	cout << "*****************************************" << endl;
}

void Wokermanage::Add_emp()
{
	cout << "��������Ҫ��ӵ�ְ��������" << endl;
	int addnum = 0;
	cin >> addnum;
	if (addnum > 0)
	{
		//��������ӵ������ռ��С
		int newsize = this->m_empnum + addnum;
		//���ݴ�С���ٿռ�
		vector<Woker*>v;
		
		//��ԭ���ռ��µ����ݿ������¿ռ�
		if (this->m_emparry != NULL)
		{
			for (int i = 0; i < this->m_empnum; i++)
			{
				v.push_back(this->m_emparry[i]);
			}
		}
		//���������
		for (int i = 0; i < addnum; i++)
		{
			int id = 0;
			string name;
			int dept = 0;

			cout << "������� " << i + 1 << "����ְ�����" << endl;
			cin >> id;
			//�ж�ְ������Ƿ��ظ�
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
				cout << "������� " << i + 1 << "����ְ������" << endl;
				cin >> name;
				cout << "������� " << i + 1 << "����ְ����λ" << endl;
				cout << "1����ְͨ��" << endl;
				cout << "2������" << endl;
				cout << "3���ϰ�" << endl;
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
				//��������ְ��ָ�뱣�浽������			
				v.push_back(woker);								
			}
			else
			{								
				addnum--;
				cout << "�������ְ������Ѵ��ڣ����ʧ�����������" << endl;
			}

		}
		int newsize1 = this->m_empnum + addnum;				
		//�ͷ�ԭ�еĿռ�
		delete[]this->m_emparry;
		//�����¿ռ�ָ��
		
		memcpy(this->m_emparry, &v[0], v.size() * sizeof(v[0]));
		//�����µ�ְ������
		this->m_empnum = newsize1;
		this->m_FileIsEmpty = false;
		cout << "�ɹ����" << addnum << "����ְ����" << endl;
		
		this->save();
		
	}
	else
	{
		cout << "����������������������" << endl;
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
		cout << "��¼Ϊ��" << endl;
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
		cout << "�ļ������ڻ��¼Ϊ��" << endl;
	}
	else
	{
		cout << "��������Ҫɾ����ְ�����:" << endl;
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
			cout << "ɾ���ɹ�" << endl;
		}
		else
		{
			cout << "ְ��������" << endl;
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
		cout << "�ļ������ڻ��¼Ϊ��" << endl;
	}
	else
	{
		cout << "��������Ҫ�޸ĵ�ְ�����:" << endl;
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
			cout << "�鵽���Ϊ��" << id << "��Ա��" << endl;
			cout << "�������޸ĺ��Ա�����" << endl;
			cin >> new_id;
			cout << "�������޸ĺ��Ա������" << endl;
			cin >> name;
			cout << "�������޸ĺ��Ա�����ű��" << endl;
			cout << "1:��ͨԱ��" << endl;
			cout << "2:����" << endl;
			cout << "3:�ϰ�" << endl;
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
			cout << "�޸ĳɹ�" << endl;
			this->save();
		}
		else
		{
			cout << "ְ��������" << endl;
		}
	}
	system("pause");
	system("cls");
}

void Wokermanage::find_emp()
{
	if (this->m_FileIsEmpty)
	{
		cout << "�ļ������ڻ��¼Ϊ��" << endl;
	}
	else
	{
		cout << "��ѡ����Ҫ���ҵķ�ʽ:" << endl;
		cout << "1:��ְ����Ų���" << endl;
		cout << "2:��ְ����������" << endl;

		int type_num = 0;
		cin >> type_num;
		if (type_num == 1)
		{
			cout << "��������Ҫ���ҵ�ְ�����" << endl;
			int find_num = 0;
			cin >> find_num;
			int index = this->is_Exist(find_num);
			if (index != -1)
			{
				this->m_emparry[index]->ShowInfo();
			}
			else
			{
				cout << "ְ��������" << endl;
			}
		}
		else if (type_num == 2)
		{
			cout << "��������Ҫ���ҵ�ְ������" << endl;
			string find_name;
			bool flag = false;
			cin >> find_name;
			for (int i = 0; i < m_empnum; i++)
			{
				if (m_emparry[i]->m_name == find_name)
				{
					cout << "�ҵ�����Ϊ�� " << find_name << " ��ְ��" << endl;
					flag = true;
					m_emparry[i]->ShowInfo();
				}
			}
			if (flag = false)
			{
				cout << "���޴���" << endl;
			}
		}
		else
		{
			cout << "��������" << endl;
		}
	}
	system("pause");
	system("cls");
}

void Wokermanage::Sort_Emp()
{
	if (this->m_FileIsEmpty)
	{
		cout << "�ļ������ڻ��ļ�Ϊ��" << endl;
		system("pause");
		system("cls");
	}
	else
	{
		cout << "��ѡ����Ҫ���еķ�ʽ" << endl;
		cout << "1:��������" << endl;
		cout << "2:��������" << endl;
		int select = 0;
		cin >> select;
		
		for (int i = 0; i < m_empnum; i++)
		{
			int minOrmax = i;
			for (int j = i + 1; j < m_empnum; j++)
			{
				if (select == 1)//����
				{
					if (this->m_emparry[minOrmax]->m_id > this->m_emparry[j]->m_id)
					{
						minOrmax = j;
					}
				}
				else//����
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
		
		cout << "����ɹ��������Ľ��Ϊ��" << endl;
		this->save();
		this->show_Emp();

	}
}

void Wokermanage::Clear_All()
{
	if (this->m_FileIsEmpty)
	{
		cout << "�ļ������ڻ��ļ�Ϊ��" << endl;
		
	}
	else
	{
		cout << "������ִ��ɾ����·������ȷ�ϣ�" << endl;
		cout << "1:ȷ��" << endl;
		cout << "2:����" << endl;
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
			cout << "�ĵ������" << endl;
		}
		

	}
	system("pause");
	system("cls");
}