#include <iostream>
using namespace std;
#include "workerManager.h"
#include "worker.h"
#include "employee.h"
#include "manager.h"
#include "boss.h"
int main()
{
	WorkerManager wm;
	int choice = 0;//用于存储用户选择
	
	while (true)
	{
		wm.Show_Menu(); //显示菜单
		cout << "请输入您的选择： " << endl;
		cin >> choice;
		switch (choice)
		{
		case 0: //退出系统
			wm.ExitSystem();
			break;
		case 1: //增加职工
			wm.Add_Emp();
			break;
		case 2: //显示职工
			wm.Show_Emp();

			break;
		case 3: //删除职工
			wm.Del_Emp();
			break;
		case 4: //修改职工
			wm.Mod_Emp();
			break;
		case 5: //查找职工
			wm.Find_Emp();
			break;
		case 6: //按照编号排序
			wm.Sort_Emp();
			break;
		case 7: //清空文件
			wm.Clean_File();
			break;
		default:
			cout << "输入有误，请重新输入" << endl;
			system("pause");
			system("cls"); //清屏操作
			break;
		}
	}
	system("pause");
	return 0;
}