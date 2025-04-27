#pragma once
#include <iostream>
using namespace std;
#include <string>
#include "worker.h"

//老板类
class Boss :public Worker
{
public:
	Boss(int id, string name, int did);
	//显示个人性息
	void showInfo();
	//获取岗位个人性息
	string GetDeptName();
};