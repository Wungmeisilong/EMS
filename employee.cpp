#include "employee.h"

Employee::Employee(int id, string name, int did)
{
	this->m_Id = id;
	this->m_Name = name;
	this->m_DeptId = did;
}
//��ʾ������Ϣ
void Employee::showInfo()
{
	cout << "ְ����ţ�" << this->m_Id
		<< "\tְ��������" << this->m_Name
		<< "\t��λ��" << this->GetDeptName()
		<< "\t��λְ����ɾ�����������" << endl;

}
//��ȡ��λ������Ϣ
string Employee::GetDeptName()
{
	return string("Ա��");
}