#pragma once
#include <iostream>
using namespace std;
#include <string>
#include "worker.h"

//�ϰ���
class Boss :public Worker
{
public:
	Boss(int id, string name, int did);
	//��ʾ������Ϣ
	void showInfo();
	//��ȡ��λ������Ϣ
	string GetDeptName();
};