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

		//开辟空间,使用二级指针指向一个指针数组，这个指针数组会因为多态而指向不同职工
		Worker **newSpace = new Worker *[newSize];

		//如果原来有数据要复制到新空间下
		if (this->m_EmpArray != NULL)
		{
			for (int i = 0; i < this->m_EmpNum; i++)
			{
				newSpace[i] = this->m_EmpArray[i];
			}
		}

		//添加新成员
		for (int i = 0; i < addNum; i++)
		{
			int id;
			string name;
			int dSelect;

			cout << "输入第"<<i+1<<"个职工的编号" << endl;
			cin >> id;

			cout << "输入第" << i + 1 << "个职工的姓名" << endl;
			cin >> name;

			cout << "选择岗位职称" << endl;
			cout << "1：表示普通员工" << endl;
			cout << "2：表示经理" << endl;
			cout << "3：表示老板" << endl;
			cin >> dSelect;

			Worker* worker = NULL;
			switch (dSelect)
			{
			case 1:
				worker = new Employee(id, name, 1);
				break;
			case 2:
				worker = new Manager(id, name, 2);
				break;
			case 3:
				worker = new Boss(id, name, 3);
				break;
			default:
				break;
			}

			//将职工信息添加到数组中
			newSpace[this->m_EmpNum + i] = worker;
		}

		//释放堆区数据
		delete[] m_EmpArray;

		//更新双重指针的指向
		this->m_EmpArray = newSpace;

		//更新人数
		this->m_EmpNum = newSize;

		//成功添加后保存到文件中
		Save();

		//提示添加成功
		cout << "添加成功，添加了"<<addNum<<"人" << endl;
		system("pause");
		system("cls");
	}
	else
	{
		cout << "输入错误" << endl;
	}

}
void WorkerManager::Save()
{
	//创建写入文件对象
	ofstream ofs;
	//打开文件
	ofs.open(FILENAME, ios::out);
	//开始写入
	for (int i = 0; i < this->m_EmpNum; i++)
	{
		ofs << this->m_EmpArray[i]->m_Id << " "
			<< this->m_EmpArray[i]->m_Name << " "
			<< this->m_EmpArray[i]->m_DeptId << endl;
	}
	//关闭文件
	ofs.close();
}
WorkerManager::~WorkerManager()
{
	if (this->m_EmpArray != NULL)//创建在堆区的数据会被清除
	{
		delete[] m_EmpArray;
		m_EmpArray = NULL;
	}
}