#include<iostream>
using namespace std;
#include<cstdlib>
#define MAX 1000

//�˵�����
void showMenu()
{
	cout << "***************************" << endl;
	cout << "*****  1�������ϵ��  *****" << endl;
	cout << "*****  2����ʾ��ϵ��  *****" << endl;
	cout << "*****  3��ɾ����ϵ��  *****" << endl;
	cout << "*****  4��������ϵ��  *****" << endl;
	cout << "*****  5���޸���ϵ��  *****" << endl;
	cout << "*****  6�������ϵ��  *****" << endl;
	cout << "*****  0���˳�ͨѶ¼  *****" << endl;
	cout << "***************************" << endl;
}


//�����ϵ�˵Ľṹ��
struct Person
{
	string m_name;//����
	int m_sex; //1�У�2Ů
	int m_age;//����
	string m_phone;//�绰
	string m_addr;//סַ
};

//���ͨѶ¼�Ľṹ��
struct Addressbooks
{
	//ͨѶ¼�б������ϵ������
	struct Person personArray[MAX];

	//ͨѶ¼�е�ǰ��¼��ϵ�˸���
	int m_size;
};

//�����ϵ��
void addPerson(Addressbooks*abs)
{
	//�ж�ͨѶ¼�Ƿ�����
	if (abs->m_size == MAX)
	{
		cout<<"ͨѶ¼���������޷����" << endl;
		return;
	}
	else
	{
		//��Ӿ�����ϵ��

		//����
		//string name;
		cout << "������������" << endl;
		//cin >> name;
		cin >> abs->personArray[abs->m_size].m_name;
		//abs->personArray[abs->m_size].m_name = name;
		//����
		int sex;
		while (true)
		{
			cout << "�������Ա�����1Ϊ�У�2ΪŮ" << endl;
			cin >> sex;
			if (sex == 1 || sex == 2)
			{
				abs->personArray[abs->m_size].m_sex = sex;
				break;
			}
			else
			{
				cout << "�����������������룡" << endl;
			}
		}
		//����
		//int age;
		cout << "����������"<<endl;
		//cin >> age;
		cin >> abs->personArray[abs->m_size].m_age;
		//abs->personArray[abs->m_size].m_age = age;

		//�绰
		//string phone;
		cout << "��������ϵ�绰" << endl;
		//cin >> phone;
		cin >> abs->personArray[abs->m_size].m_phone;
		//abs->personArray[abs->m_size].m_phone = phone;

		//סַ
		//string addr;
		cout << "�������ͥסַ" << endl;
		//cin >> addr;
		cin >> abs->personArray[abs->m_size].m_addr;
		//abs->personArray[abs->m_size].m_addr = addr;

		//����ͨѶ¼����
		abs->m_size++;
		cout << "��ӳɹ�����" << endl;

		system("pause");//�밳���������
		system("cls");//��������
	}
}

//��ʾ������ϵ��

void showPerson(Addressbooks* abs)
{
	//�ж�ͨѶ¼���Ƿ��м�¼
	if (abs->m_size == 0)
	{
		cout << "��ǰ�ļ�¼Ϊ��" << endl;
		system("pause");//�밳���������
		system("cls");//��������
		return;
	}
	else
	{
		for (int i = 0; i < abs->m_size; i++)
		{
			cout << "������" << abs->personArray[i].m_name << "\t";
			cout << "�Ա�" << abs->personArray[i].m_sex << "\t";
			cout << "���䣺" << abs->personArray[i].m_age << "\t";
			cout << "�绰��" << abs->personArray[i].m_phone << "\t";
			cout << "סַ��" << abs->personArray[i].m_addr << endl;
		}
		system("pause");
		system("cls");
	}
}
//�����ϵ���Ƿ���ڣ�������ڣ�������ϵ�����������еľ���λ�ã������ڷ���-1
//����1 ͨѶ¼������2������
int isExist(Addressbooks * abs,string name)
{
	for (int i = 0; i < abs->m_size; i++)
	{
		if (abs->personArray[i].m_name == name)
		{
			return i;
		}
	}
	return -1;
}

//ɾ��ָ������ϵ��
void deletePerson(Addressbooks* abs)
{
	cout << "��������Ҫɾ������ϵ��" << endl;
	string name;
	cin >> name;
	int ret = isExist(abs, name);
	if (ret != -1)
	{
		for (int i = ret; i < abs->m_size; i++)
		{
			abs->personArray[i] = abs->personArray[i + 1];
		}
		abs->m_size--;//����ͨѶ¼�е�����
		cout << "ɾ���ɹ�����" << endl;
	}
	else
	{
		cout<<"���޴��ˣ�����"<<endl;
	}
	system("pause");
	system("cls");

}

//������ϵ��
void findPerson(Addressbooks* abs)
{
	cout << "��������Ҫ���ҵ���ϵ��" << endl;
	string name;
	cin >> name;
	int ret = isExist(abs, name);
	if ( ret != -1)
	{
				cout << "������" << abs->personArray[ret].m_name << "\t";
				cout << "�Ա�" << abs->personArray[ret].m_sex << "\t";
				cout << "���䣺" << abs->personArray[ret].m_age << "\t";
				cout << "�绰��" << abs->personArray[ret].m_phone << "\t";
				cout << "סַ��" << abs->personArray[ret].m_addr << endl;
	}
	else
	{
		cout << "���޴��ˣ���" << endl;
	}
	system("pause");
	system("cls");
}

//�޸���ϵ��
void modifyPerson(Addressbooks *abs)
{
	cout << "��������Ҫ�޸ĵ���ϵ��" << endl;
	string name;
	cin >> name;
	int ret = isExist(abs,name);
	if (ret != -1)
	{
		cout << "�������޸ĺ������" << endl;
		cin >> abs->personArray[ret].m_name;
		int sex;
		while (true)
		{
			cout << "�������޸ĺ��Ա�" << endl;
			cout << "1-----��" << endl;
			cout << "2-----Ů" << endl;
			cin >> sex;
			if (sex == 1 || sex == 2)
			{
				abs->personArray[ret].m_sex = sex;
				break;
			}
			cout << "���������������������룡��" << endl;
		}
		cout << "�������޸ĺ�����" << endl;
		cin >> abs->personArray[ret].m_age;
		cout << "�������޸ĺ�绰" << endl;
		cin >> abs->personArray[ret].m_phone;
		cout << "�������޸ĺ�סַ" << endl;
		cin >> abs->personArray[ret].m_addr;
	}
	else
	{
		cout << "���޴��ˣ���" << endl;
	}
	system("pause");
	system("cls");
}

//�����ϵ�� ͨѶ¼��¼������Ϊ0
void cleanPerson(Addressbooks* abs)
{
	int ret;
	cout << "�Ƿ�Ҫ��գ�"<<endl;
	cout << "1-----���" << endl;
	cout << "2---�����" << endl;
	cin >> ret;
	if (ret == 1)
	{
		abs->m_size = 0;
		cout << "����գ�" << endl;
		system("pause");
		system("cls");
	}
	else
	{
		system("pause");
		system("cls");
	}
	
}

int main()
{

	//����ͨѶ¼�ṹ�����
	Addressbooks abs;
	//��ʼ��ͨѶ¼�е�ǰ�ĸ���
	abs.m_size = 0;

	int select = 0;

	while (true)
	{
		
		showMenu();//�˵��ĵ���

		cin >> select;

		switch (select)
		{
		case 1 ://1�������ϵ��
			addPerson(&abs);//���õ�ַ���ݣ������޸�ʵ��
			break;
		case 2://2����ʾ��ϵ��
			showPerson(&abs);
			break;
		case 3://3��ɾ����ϵ��
		{
			/*cout << "������Ҫɾ��������" << endl;
			string name;
			cin >> name;
			if (isExist(&abs, name) == -1)
			{
				cout << "���޴��ˣ���" << endl;
			}
			else
			{
				cout << "�ҵ����ˣ���" << endl;
			}*/
			deletePerson(&abs);
			break;
		}
		case 4://4��������ϵ��
			findPerson(&abs);
			break;
		case 5://5���޸���ϵ��
			modifyPerson(&abs);
			break;
		case 6://6�������ϵ��
			cleanPerson(&abs);
			break;
		case 0://0���˳�ͨѶ¼
			cout << "*****  ��ӭ�´�ʹ��   *****" << endl;
			system("pause");
			return 0;
			break;
		}
	}
	system("pause");
	return 0;
}