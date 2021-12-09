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

//��˾������ļ��10��Ա��(ABCDEFGHIJ)��10��Զ����빫˾����Ҫָ��Ա�����ĸ����Ź���
//Ա����Ϣ���������������
//���ŷ�Ϊ���߻����������з�
//�����10��Ա�����䲿�ź͹���
//ͨ��multimap������Ϣ�Ĳ��� key(���ű��) value(Ա��)
//�ֲ�����ʾԱ��

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
		worker.m_Name = "Ա��";
		worker.m_Name += nameSeed[i];

		worker.m_Salary = rand() % 10000 + 10000; //10000 ~ 19999
		//��Ա�����뵽������
		v.push_back(worker);
	}
}

void setGroup(vector<Worker>& v, multimap<int, Worker>& m)
{
	for (vector<Worker>::iterator it = v.begin(); it != v.end(); it++)
	{
		//����������ű��
		int depId = rand() % 3 + 1;

		//��Ա�����뵽������
		//key���ű�ţ�value����Ա��
		m.insert(make_pair(depId, *it));
	}
}

void showWorkerByGroup(multimap<int, Worker>& m)
{
	cout << "�߻����ţ� " << endl;
	
	multimap<int, Worker>::iterator pos = m.find(CEHUA);
	int count = m.count(CEHUA);  //ͳ�Ʋ߻����ž�������

	for (int index = 0; pos != m.end() && index < count; pos++, index++)
	{
		cout << "������ " << pos->second.m_Name << " ���ʣ� " << pos->second.m_Salary << endl;
	}
	cout << "-----------------------------------" << endl;
	cout << "�������ţ� " << endl;
	pos = m.find(MEISHU);
	count = m.count(MEISHU);  //ͳ���������ž�������

	for (int index = 0; pos != m.end() && index < count; pos++, index++)
	{
		cout << "������ " << pos->second.m_Name << " ���ʣ� " << pos->second.m_Salary << endl;
	}
	cout << "-----------------------------------" << endl;
	cout << "�з����ţ� " << endl;
	pos = m.find(YANFA);
	count = m.count(YANFA);  //ͳ���з����ž�������

	for (int index = 0; pos != m.end() && index < count; pos++, index++)
	{
		cout << "������ " << pos->second.m_Name << " ���ʣ� " << pos->second.m_Salary << endl;
	}
}

int main()
{
	srand((unsigned int)time(NULL));

	//1������Ա��
	vector<Worker> vWorker;
	createWorker(vWorker);

	//2��Ա������
	multimap<int, Worker> mWorker;
	setGroup(vWorker, mWorker);

	//3��������ʾԱ��
	showWorkerByGroup(mWorker);

	////����
	//for (vector<Worker>::iterator it = vWorker.begin(); it != vWorker.end(); it++)
	//{
	//	cout << "������ " << (*it).m_Name << " ���ʣ� " << (*it).m_Salary << endl;
	//}

	system("pause");
	return 0;
}