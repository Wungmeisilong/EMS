#include "workerManager.h"

WorkerManager::WorkerManager()
{
	//��ʼ������
	this->m_EmpArray = NULL;
	this->m_EmpNum = 0;
}
void WorkerManager::Show_Menu()
{
	cout << "*************************" << endl;
	cout << "***��ӭʹ��ְ������ϵͳ******" << endl;
	cout << "*****  0-�˳��������  *****" << endl;
	cout << "*****  1-����ְ����Ϣ  *****" << endl;
	cout << "*****  2-��ʾְ����Ϣ  *****" << endl;
	cout << "*****  3-ɾ��ְ����Ϣ  *****" << endl;
	cout << "*****  4-�޸�ְ����Ϣ  *****" << endl;
	cout << "*****  5-����ְ����Ϣ  *****" << endl;
	cout << "*****  6-���ձ������  *****" << endl;
	cout << "*****  7-��������ĵ�  *****" << endl;
	cout << "*************************" << endl;
}
void WorkerManager::ExitSystem()
{
	//�˳�����
	cout << "��ӭ�´���ʹ�ã���" << endl;
	system("pause");
	exit(0);	 
}
void WorkerManager::Add_Emp()
{
	//��ʾ
	cout << "������Ҫ��ӵ�����" << endl;

	//�������������
	int addNum = 0;
	cin >> addNum;
	if (addNum > 0)
	{
		//���
		//������ӿռ��С
		int newSize = this->m_EmpNum + addNum;

		//���ٿռ�
		Worker **newSpace = new Worker *[newSize];

		//���ԭ��������Ҫ���Ƶ��¿ռ���
		if (this->m_EmpArray != NULL)
		{
			for (int i = 0; i < this->m_EmpNum; i++)
			{
				newSpace[i] = this->m_EmpArray[i];
			}
		}
	}
	else
	{

	}

}
WorkerManager::~WorkerManager()
{

}