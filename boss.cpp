#include "boss.h"

Boss::Boss(int id, string name, int did)
{
	this->m_Id = id;
	this->m_Name = name;
	this->m_DeptId = did;
}
//显示个人性息
void Boss::showInfo()
{
	cout << "职工编号：" << this->m_Id
		<< "\t职工姓名：" << this->m_Name
		<< "\t岗位：" << this->GetDeptName()
		<< "\t岗位职责：给经理派发任务" << endl;

}
//获取岗位个人性息
string Boss::GetDeptName()
{
	return string("老板");
}