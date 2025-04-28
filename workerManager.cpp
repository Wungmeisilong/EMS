#include "workerManager.h"

WorkerManager::WorkerManager()
{
	//初始化属性
	this->m_EmpArray = NULL;
	this->m_EmpNum = 0;
}
void WorkerManager::Show_Menu()
{
	cout << "*************************" << endl;
	cout << "***欢迎使用职工管理系统******" << endl;
	cout << "*****  0-退出管理程序  *****" << endl;
	cout << "*****  1-增加职工信息  *****" << endl;
	cout << "*****  2-显示职工信息  *****" << endl;
	cout << "*****  3-删除职工信息  *****" << endl;
	cout << "*****  4-修改职工信息  *****" << endl;
	cout << "*****  5-查找职工信息  *****" << endl;
	cout << "*****  6-按照编号排序  *****" << endl;
	cout << "*****  7-清空所有文档  *****" << endl;
	cout << "*************************" << endl;
}
void WorkerManager::ExitSystem()
{
	//退出功能
	cout << "欢迎下次再使用！！" << endl;
	system("pause");
	exit(0);	 
}
void WorkerManager::Add_Emp()
{
	//提示
	cout << "请输入要添加的人数" << endl;

	//保存输入的人数
	int addNum = 0;
	cin >> addNum;
	if (addNum > 0)
	{
		//添加
		//计算添加空间大小
		int newSize = this->m_EmpNum + addNum;

		//开辟空间
		Worker **newSpace = new Worker *[newSize];

		//如果原来有数据要复制到新空间下
		if (this->m_EmpArray != NULL)
		{
			for (int i = 0; i < this->m_EmpNum; i++)
			{
				newSpace[i] = this->m_EmpArray[i];
			}
		}
	}
	else
	{

	}

}
WorkerManager::~WorkerManager()
{

}