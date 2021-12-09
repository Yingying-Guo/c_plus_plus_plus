#include<iostream>
#include<map>
#include<vector>
#include<algorithm>
#include<string>
#include<ctime>
using namespace std;

#define CEHUA 1
#define MEISHU 2
#define YANFA 3

//公司今天招募了10个员工(ABCDEFGHIJ)，10名远哥进入公司后，需要指派员工在哪个部门工作
//员工信息：姓名、工资组成
//部门分为：策划、美术、研发
//随机给10名员工分配部门和工资
//通过multimap进行信息的插入 key(部门编号) value(员工)
//分部门显示员工

class Worker
{
public:
	string m_Name;
	int m_Salary;
};

void createWorker(vector<Worker> &v)
{
	string nameSeed = "ABCDEFGHIJ";
	for (int i = 0; i < 10; i++)
	{
		Worker worker;
		worker.m_Name = "员工";
		worker.m_Name += nameSeed[i];

		worker.m_Salary = rand() % 10000 + 10000; //10000 ~ 19999
		//将员工放入到容器中
		v.push_back(worker);
	}
}

void setGroup(vector<Worker>& v, multimap<int, Worker>& m)
{
	for (vector<Worker>::iterator it = v.begin(); it != v.end(); it++)
	{
		//产生随机部门编号
		int depId = rand() % 3 + 1;

		//将员工插入到分组中
		//key部门编号，value具体员工
		m.insert(make_pair(depId, *it));
	}
}

void showWorkerByGroup(multimap<int, Worker>& m)
{
	cout << "策划部门： " << endl;
	
	multimap<int, Worker>::iterator pos = m.find(CEHUA);
	int count = m.count(CEHUA);  //统计策划部门具体人数

	for (int index = 0; pos != m.end() && index < count; pos++, index++)
	{
		cout << "姓名： " << pos->second.m_Name << " 工资： " << pos->second.m_Salary << endl;
	}
	cout << "-----------------------------------" << endl;
	cout << "美术部门： " << endl;
	pos = m.find(MEISHU);
	count = m.count(MEISHU);  //统计美术部门具体人数

	for (int index = 0; pos != m.end() && index < count; pos++, index++)
	{
		cout << "姓名： " << pos->second.m_Name << " 工资： " << pos->second.m_Salary << endl;
	}
	cout << "-----------------------------------" << endl;
	cout << "研发部门： " << endl;
	pos = m.find(YANFA);
	count = m.count(YANFA);  //统计研发部门具体人数

	for (int index = 0; pos != m.end() && index < count; pos++, index++)
	{
		cout << "姓名： " << pos->second.m_Name << " 工资： " << pos->second.m_Salary << endl;
	}
}

int main()
{
	srand((unsigned int)time(NULL));

	//1、创建员工
	vector<Worker> vWorker;
	createWorker(vWorker);

	//2、员工分组
	multimap<int, Worker> mWorker;
	setGroup(vWorker, mWorker);

	//3、分组显示员工
	showWorkerByGroup(mWorker);

	////测试
	//for (vector<Worker>::iterator it = vWorker.begin(); it != vWorker.end(); it++)
	//{
	//	cout << "姓名： " << (*it).m_Name << " 工资： " << (*it).m_Salary << endl;
	//}

	system("pause");
	return 0;
}