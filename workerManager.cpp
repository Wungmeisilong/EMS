#include "workerManager.h"

WorkerManager::WorkerManager()
{
	//1���ж��ļ��Ƿ����
	ifstream ifs;
	ifs.open(FILENAME, ios::in);
	if (!ifs.is_open())
	{
		cout << "�ļ�������" << endl;
		//��ʼ������
		this->m_EmpArray = NULL;
		this->m_EmpNum = 0;
		this->m_FileIsEmpty = true;

		ifs.close();
		return;
	}
	//�ļ����ڣ�����û�м�¼
	char ch;
	ifs >> ch;
	if (ifs.eof())
	{
		//�ļ�Ϊ��
		//cout << "�ļ�Ϊ��" << endl;
		//��ʼ������
		this->m_EmpArray = NULL;
		this->m_EmpNum = 0;
		this->m_FileIsEmpty = true;

		ifs.close();
		return;
	}
	//�ļ�����,���м�¼
	int num = this->Get_EmpNUm();
	//cout << "ְ������Ϊ��" << num<<endl;
	this->m_EmpNum = num;
	//���ٿռ�
	this->m_EmpArray = new Worker * [this->m_EmpNum];
	//�����ݴ浽������
	this->initEmp();

	////���Դ���
	//for (int i = 0; i < this->m_EmpNum; i++)
	//{
	//	cout << "ְ�����" << this->m_EmpArray[i]->m_Id << " "
	//		<< "ְ��������" << this->m_EmpArray[i]->m_Name << " "
	//		<< "ְ��ְ�ƣ�" << this->m_EmpArray[i]->GetDeptName() << endl;

	//}
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

		//�����ļ��ǲ��ǿ�
		this->m_FileIsEmpty = false;
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
int WorkerManager::Get_EmpNUm()
{
	ifstream ifs;
	ifs.open(FILENAME, ios::in);

	int id;
	string name;
	int did;

	int empNum = 0;

	while (ifs >> id && ifs >> name && ifs >> did)
	{
		empNum++;
	}
	return empNum;
}
void WorkerManager::initEmp()
{
	//���ļ�
	ifstream ifs;
	ifs.open(FILENAME, ios::in);

	int id;
	string name;
	int dId;

	int index = 0;

	while (ifs >> id && ifs >> name && ifs >> dId)
	{
		Worker* worker = NULL;
		if (dId == 1)
		{
			worker = new Employee(id, name, dId);
		}
		else if (dId == 2)
		{
			worker = new Manager(id, name, dId);
		}
		else
		{
			worker = new Boss(id, name, dId);
		}
		this->m_EmpArray[index] = worker;//�����ݴ洢��ָ��������
		index++;//��¼����
	}
	//�ر��ļ�
	ifs.clear();
}
void WorkerManager::Show_Emp()
{
	//�ж��ļ��Ƿ�Ϊ��
	if (this->m_FileIsEmpty)
	{
		cout << "�ļ������ڻ�Ϊ��" << endl;

	}
	else
	{
		for (int i = 0; i < this->m_EmpNum; i++)
		{
			this->m_EmpArray[i]->showInfo();
		}
		system("pause");
		system("cls");
	}
}
// ɾ��ְ��
void WorkerManager::Del_Emp()
{
	if (this->m_FileIsEmpty)
	{
		cout << "�ļ�������" << endl;
	}
	else
	{
		cout << "������Ҫɾ����ְ�����" << endl;
		int id = 0;
		cin >> id;

		int index = this->IsExist(id);

		if (index != -1 ) {
			for (int i = index; i < this->m_EmpNum - 1; i++)
			{
				//����ǰ��
				this->m_EmpArray[i] = this->m_EmpArray[i + 1];
			}
			//��������
			this->m_EmpNum--;

			//ͬ�����ļ���
			this->Save();

			cout << "ɾ���ɹ�" << endl;
		}
		else
		{
			cout << "ְ����Ų�����" << endl;
		}
	}
	system("pause");
	system("cls");
}
//�ж�ְ���Ƿ����
int WorkerManager::IsExist(int id)
{
	int index = -1;
	for (int i = 0; i < this->m_EmpNum; i++)
	{
		if (this->m_EmpArray[i]->m_Id == id)
		{
			//���ձ�ţ��ҵ�ְ��
			index = i;
			break;
		}
	}
	return index;
}

void WorkerManager::Mod_Emp()
{
	if (this->m_FileIsEmpty)
	{
		cout << "�ļ�������" << endl;
	}
	else
	{
		cout << "������Ҫ�޸ĵ�Ա�����" << endl;
		int oldId = 0;
		cin >> oldId;

		int ret = this->IsExist(oldId);
		if (ret != -1)
		{
			//�����ԭ������
			delete  this->m_EmpArray[ret];

			//��ʾ���룬�޸�ְ����Ϣ
			int id;
			string name;
			int dSelect;

			cout << "�鵽��" << oldId << "��ְ����������ְ���±��" << endl;
			cin >> id;

			cout << "����ְ��������" << endl;
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
			this->m_EmpArray[ret] = worker;
			cout << "�޸ĳɹ�" << endl;
			//ͬ�����ļ�
			this->Save();
		}
		else
		{
			cout << "�޸�ʧ�ܣ�Ա����Ų�����" << endl;
		}
	}
	system("pause");
	system("cls");
}
int WorkerManager::IsNameExist(string name) {
	bool flag = -1;
	for (int i = 0; i < this->m_EmpNum; i++)
	{
		if (this->m_EmpArray[i]->m_Name == name)
		{
			flag = i;
			break;
		}
	}
	return flag;
}
void WorkerManager::Find_Emp()
{
	if (this->m_FileIsEmpty)
	{
		cout << "�ļ�������" << endl;
	}
	else
	{
		cout << "��������ҷ�ʽ" << endl;
		cout << "1�����ձ�Ų�ѯ" << endl;
		cout << "2������������ѯ" << endl;
		int select = 0;
		cin >> select;

		switch (select)
		{
		case 1:
		{
			//���ձ�Ų�ѯ
			int id;
			cout << "��������ҵı�ţ�" << endl;
			cin >> id;
			int index = 0;
			index = this->IsExist(id);

			if(index != -1)
			{
				cout << "��ѯ�����Ϊ"<<id<<"��ְ������Ϣ���£�" << endl;
				this->m_EmpArray[index]->showInfo();
			}
			else
			{
				cout << "���޴��ˣ�" << endl;
			}
		}
			break;
		case 2:
		{
			//������������
			string name;
			cout << "�����Ҫ���ҵ�ְ��������" << endl;
			cin >> name;

			int index = this->IsNameExist(name);
			if (index != -1)
			{
				cout << "���ҳɹ�," << name << "ְ������Ϣ����:" << endl;
				this->m_EmpArray[index]->showInfo();
			}
			else
			{
				cout << "���޴���" << endl;
			}
		}
			break;
		default:
			cout << "����������������룡��" << endl;
			break;
		}
	}
	system("pause");
	system("cls");
}
WorkerManager::~WorkerManager()
{
	if (this->m_EmpArray != NULL)//�����ڶ��������ݻᱻ���
	{
		delete[] m_EmpArray;
		m_EmpArray = NULL;
	}
}