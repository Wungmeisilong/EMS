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

	//�ж��ļ��Ƿ�Ϊ��
	bool m_FileIsEmpty;

	//ͳ���ļ��е�����
	int Get_EmpNUm();

	//����ļ��������м�¼���������ݲ��洢�������У���ʼ��Ա������
	void initEmp();
	//��¼�������ж��ٸ�ְ������
	int m_EmpNum;

	//��ʾְ������
	void Show_Emp();

	// ɾ��ְ��
	void Del_Emp();
	//�ж�ְ���Ƿ����
	int IsExist(int id);

	//�޸�ְ��
	void Mod_Emp();

	//����ְ��
	int IsNameExist(string name);
	void Find_Emp();
	//ְ������ָ�룬ʹ��˫��ָ�����worker����ָ�룬����������*Worker
	Worker** m_EmpArray;
	~WorkerManager();
};
