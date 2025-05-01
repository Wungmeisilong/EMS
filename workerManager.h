#pragma once //防止头文件重复包含
#include <iostream>
#include "worker.h"
#include "employee.h"
#include "boss.h"
#include "manager.h"
#include <fstream>

#define FILENAME "empFile.txt"
using namespace std;

class WorkerManager
{
public:
	//构造函数
	WorkerManager();
	//展示菜单
	void Show_Menu();
	//退出系统
	void ExitSystem();

	//添加职工函数
	void Add_Emp();

	//保存文件函数
	void Save();

	//判断文件是否为空
	bool m_FileIsEmpty;

	//统计文件中的人数
	int Get_EmpNUm();

	//如果文件存在且有记录，读出数据并存储在数组中，初始化员工人数
	void initEmp();
	//记录数组中有多少个职工人数
	int m_EmpNum;

	//显示职工函数
	void Show_Emp();

	// 删除职工
	void Del_Emp();
	//判断职工是否存在
	int IsExist(int id);

	//修改职工
	void Mod_Emp();

	//查找职工
	int IsNameExist(string name);
	void Find_Emp();
	//职工数组指针，使用双重指针管理worker数组指针，数组类型是*Worker
	Worker** m_EmpArray;
	~WorkerManager();
};
