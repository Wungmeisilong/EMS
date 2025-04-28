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

		//���ٿռ�,ʹ�ö���ָ��ָ��һ��ָ�����飬���ָ���������Ϊ��̬��ָ��ְͬ��
		Worker **newSpace = new Worker *[newSize];

		//���ԭ��������Ҫ���Ƶ��¿ռ���
		if (this->m_EmpArray != NULL)
		{
			for (int i = 0; i < this->m_EmpNum; i++)
			{
				newSpace[i] = this->m_EmpArray[i];
			}
		}

		//����³�Ա
		for (int i = 0; i < addNum; i++)
		{
			int id;
			string name;
			int dSelect;

			cout << "�����"<<i+1<<"��ְ���ı��" << endl;
			cin >> id;

			cout << "�����" << i + 1 << "��ְ��������" << endl;
			cin >> name;

			cout << "ѡ���λְ��" << endl;
			cout << "1����ʾ��ͨԱ��" << endl;
			cout << "2����ʾ����" << endl;
			cout << "3����ʾ�ϰ�" << endl;
			cin >> dSelect;

			Worker* worker = NULL;
			switch (dSelect)
			{
			case 1:
				worker = new Employee(id, name, 1);
				break;
			case 2:
				worker = new Manager(id, name, 2);
				break;
			case 3:
				worker = new Boss(id, name, 3);
				break;
			default:
				break;
			}

			//��ְ����Ϣ��ӵ�������
			newSpace[this->m_EmpNum + i] = worker;
		}

		//�ͷŶ�������
		delete[] m_EmpArray;

		//����˫��ָ���ָ��
		this->m_EmpArray = newSpace;

		//��������
		this->m_EmpNum = newSize;

		//�ɹ���Ӻ󱣴浽�ļ���
		Save();

		//��ʾ��ӳɹ�
		cout << "��ӳɹ��������"<<addNum<<"��" << endl;
		system("pause");
		system("cls");
	}
	else
	{
		cout << "�������" << endl;
	}

}
void WorkerManager::Save()
{
	//����д���ļ�����
	ofstream ofs;
	//���ļ�
	ofs.open(FILENAME, ios::out);
	//��ʼд��
	for (int i = 0; i < this->m_EmpNum; i++)
	{
		ofs << this->m_EmpArray[i]->m_Id << " "
			<< this->m_EmpArray[i]->m_Name << " "
			<< this->m_EmpArray[i]->m_DeptId << endl;
	}
	//�ر��ļ�
	ofs.close();
}
WorkerManager::~WorkerManager()
{
	if (this->m_EmpArray != NULL)//�����ڶ��������ݻᱻ���
	{
		delete[] m_EmpArray;
		m_EmpArray = NULL;
	}
}