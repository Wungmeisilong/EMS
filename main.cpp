#include <iostream>
using namespace std;
#include "workerManager.h"
#include "worker.h"
#include "employee.h"
#include "manager.h"
#include "boss.h"
int main()
{
	WorkerManager wm;
	int choice = 0;//���ڴ洢�û�ѡ��
	
	while (true)
	{
		wm.Show_Menu(); //��ʾ�˵�
		cout << "����������ѡ�� " << endl;
		cin >> choice;
		switch (choice)
		{
		case 0: //�˳�ϵͳ
			wm.ExitSystem();
			break;
		case 1: //����ְ��
			wm.Add_Emp();
			break;
		case 2: //��ʾְ��
			wm.Show_Emp();
			break;
		case 3: //ɾ��ְ��
			wm.Del_Emp();
			break;
		case 4: //�޸�ְ��
			wm.Mod_Emp();
			break;
		case 5: //����ְ��
			break;
		case 6: //���ձ������
			wm.Find_Emp();
			break;
		case 7: //����ļ�
		{
			int i = 0;
			for (; i < 6; i++)
			{
				cout << "��"<<i+1<<"�������"<<i << endl;
			}
			cout << "��" << i + 1 << "�������" << i << endl;
		}
			break;
		default:
			cout << "������������������" << endl;
			system("pause");
			system("cls"); //��������
			break;
		}
	}
	system("pause");
	return 0;
}