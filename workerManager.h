#pragma once //��ֹͷ�ļ��ظ�����
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
	//���캯��
	WorkerManager();
	//չʾ�˵�
	void Show_Menu();
	//�˳�ϵͳ
	void ExitSystem();

	//���ְ������
	void Add_Emp();

	//�����ļ�����
	void Save();
	//��¼�������ж��ٸ�ְ������
	int m_EmpNum;

	//ְ������ָ�룬ʹ��˫��ָ�����worker����ָ�룬����������*Worker
	Worker** m_EmpArray;
	~WorkerManager();
};
