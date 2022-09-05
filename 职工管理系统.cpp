#include<iostream>
using namespace std;
#include "wokermanage.h"



int main()
{
	Wokermanage wm;
	int select = 0;
	while (true)
	{
		wm.Show_menu();
		cout << "请输入您要选择的功能" << endl;		
		cin >> select;
		cin.clear();
		cin.ignore();
		switch (select)
		{
		case 0:wm.Exit_sys(); break;
		case 1:wm.Add_emp(); break;
		case 2:wm.show_Emp(); break;
		case 3:wm.del_Emp();break; 
		case 4:wm.change_info(); break;
		case 5:wm.find_emp(); break;
		case 6:wm.Sort_Emp(); break;
		case 7:wm.Clear_All(); break;
		default:
			cout << "您的输入有误请重新输入" << endl;
			system("pause");
			system("cls");
			break;
		}
	}






	


	system("pause");
	return 0;
}