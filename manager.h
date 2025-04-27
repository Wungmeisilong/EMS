#pragma once
#include <iostream>
using namespace std;
#include <string>
#include "worker.h"
//经理类
class Manager :public Worker
{
public:
	Manager(int id, string name, int did);
	//显示个人性息
	void showInfo();
	//获取岗位个人性息
	string GetDeptName();
};