#include "workerManager.h"

WorkerManager::WorkerManager()
{
	//1，判断文件是否存在
	ifstream ifs;
	ifs.open(FILENAME, ios::in);
	if (!ifs.is_open())
	{
		cout << "文件不存在" << endl;
		//初始化属性
		this->m_EmpArray = NULL;
		this->m_EmpNum = 0;
		this->m_FileIsEmpty = true;

		ifs.close();
		return;
	}
	//文件存在，但是没有记录
	char ch;
	ifs >> ch;
	if (ifs.eof())
	{
		//文件为空
		//cout << "文件为空" << endl;
		//初始化属性
		this->m_EmpArray = NULL;
		this->m_EmpNum = 0;
		this->m_FileIsEmpty = true;

		ifs.close();
		return;
	}
	//文件存在,并有记录
	int num = this->Get_EmpNUm();
	//cout << "职工人数为：" << num<<endl;
	this->m_EmpNum = num;
	//开辟空间
	this->m_EmpArray = new Worker * [this->m_EmpNum];
	//将数据存到数组中
	this->initEmp();

	////测试代码
	//for (int i = 0; i < this->m_EmpNum; i++)
	//{
	//	cout << "职工编号" << this->m_EmpArray[i]->m_Id << " "
	//		<< "职工姓名：" << this->m_EmpArray[i]->m_Name << " "
	//		<< "职工职称：" << this->m_EmpArray[i]->GetDeptName() << endl;

	//}
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

		//更新文件是不是空
		this->m_FileIsEmpty = false;
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
int WorkerManager::Get_EmpNUm()
{
	ifstream ifs;
	ifs.open(FILENAME, ios::in);

	int id;
	string name;
	int did;

	int empNum = 0;

	while (ifs >> id && ifs >> name && ifs >> did)
	{
		empNum++;
	}
	return empNum;
}
void WorkerManager::initEmp()
{
	//打开文件
	ifstream ifs;
	ifs.open(FILENAME, ios::in);

	int id;
	string name;
	int dId;

	int index = 0;

	while (ifs >> id && ifs >> name && ifs >> dId)
	{
		Worker* worker = NULL;
		if (dId == 1)
		{
			worker = new Employee(id, name, dId);
		}
		else if (dId == 2)
		{
			worker = new Manager(id, name, dId);
		}
		else
		{
			worker = new Boss(id, name, dId);
		}
		this->m_EmpArray[index] = worker;//将数据存储在指针数组中
		index++;//记录人数
	}
	//关闭文件
	ifs.clear();
}
void WorkerManager::Show_Emp()
{
	//判断文件是否为空
	if (this->m_FileIsEmpty)
	{
		cout << "文件不存在或为空" << endl;

	}
	else
	{
		for (int i = 0; i < this->m_EmpNum; i++)
		{
			this->m_EmpArray[i]->showInfo();
		}
		system("pause");
		system("cls");
	}
}
// 删除职工
void WorkerManager::Del_Emp()
{
	if (this->m_FileIsEmpty)
	{
		cout << "文件不存在" << endl;
	}
	else
	{
		cout << "请输入要删除的职工编号" << endl;
		int id = 0;
		cin >> id;

		int index = this->IsExist(id);

		if (index != -1 ) {
			for (int i = index; i < this->m_EmpNum - 1; i++)
			{
				//数据前移
				this->m_EmpArray[i] = this->m_EmpArray[i + 1];
			}
			//更新人数
			this->m_EmpNum--;

			//同步到文件中
			this->Save();

			cout << "删除成功" << endl;
		}
		else
		{
			cout << "职工编号不存在" << endl;
		}
	}
	system("pause");
	system("cls");
}
//判断职工是否存在
int WorkerManager::IsExist(int id)
{
	int index = -1;
	for (int i = 0; i < this->m_EmpNum; i++)
	{
		if (this->m_EmpArray[i]->m_Id == id)
		{
			//按照编号，找到职工
			index = i;
			break;
		}
	}
	return index;
}

void WorkerManager::Mod_Emp()
{
	if (this->m_FileIsEmpty)
	{
		cout << "文件不存在" << endl;
	}
	else
	{
		cout << "请输入要修改的员工编号" << endl;
		int oldId = 0;
		cin >> oldId;

		int ret = this->IsExist(oldId);
		if (ret != -1)
		{
			//先清空原有数据
			delete  this->m_EmpArray[ret];

			//提示输入，修改职工信息
			int id;
			string name;
			int dSelect;

			cout << "查到：" << oldId << "号职工，请输入职工新编号" << endl;
			cin >> id;

			cout << "输入职工的姓名" << endl;
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
			this->m_EmpArray[ret] = worker;
			cout << "修改成功" << endl;
			//同步到文件
			this->Save();
		}
		else
		{
			cout << "修改失败，员工编号不存在" << endl;
		}
	}
	system("pause");
	system("cls");
}
int WorkerManager::IsNameExist(string name) {
	bool flag = -1;
	for (int i = 0; i < this->m_EmpNum; i++)
	{
		if (this->m_EmpArray[i]->m_Name == name)
		{
			flag = i;
			break;
		}
	}
	return flag;
}
void WorkerManager::Find_Emp()
{
	if (this->m_FileIsEmpty)
	{
		cout << "文件不存在" << endl;
	}
	else
	{
		cout << "请输入查找方式" << endl;
		cout << "1：按照编号查询" << endl;
		cout << "2：按照姓名查询" << endl;
		int select = 0;
		cin >> select;

		switch (select)
		{
		case 1:
		{
			//按照编号查询
			int id;
			cout << "请输入查找的编号：" << endl;
			cin >> id;
			int index = 0;
			index = this->IsExist(id);

			if(index != -1)
			{
				cout << "查询到编号为"<<id<<"的职工，信息如下：" << endl;
				this->m_EmpArray[index]->showInfo();
			}
			else
			{
				cout << "查无此人！" << endl;
			}
		}
			break;
		case 2:
		{
			//按照姓名查找
			string name;
			cout << "请输出要查找的职工姓名：" << endl;
			cin >> name;

			int index = this->IsNameExist(name);
			if (index != -1)
			{
				cout << "查找成功," << name << "职工的信息如下:" << endl;
				this->m_EmpArray[index]->showInfo();
			}
			else
			{
				cout << "查无此人" << endl;
			}
		}
			break;
		default:
			cout << "输入错误请重新输入！！" << endl;
			break;
		}
	}
	system("pause");
	system("cls");
}
WorkerManager::~WorkerManager()
{
	if (this->m_EmpArray != NULL)//创建在堆区的数据会被清除
	{
		delete[] m_EmpArray;
		m_EmpArray = NULL;
	}
}