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
	//记录数组中有多少个职工人数
	int m_EmpNum;

	//职工数组指针，使用双重指针管理worker数组指针，数组类型是*Worker
	Worker** m_EmpArray;
	~WorkerManager();
};
