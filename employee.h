#pragma once
#include <iostream>
using namespace std;
#include <string>
#include "worker.h"
//职工类
class Employee:public Worker
{
public:
	Employee(int id,string name,int did);
	//显示个人性息
	void showInfo();
	//获取岗位个人性息
	string GetDeptName();
};