#include<iostream>
using namespace std;
#include<cstdlib>
#define MAX 1000

//菜单界面
void showMenu()
{
	cout << "***************************" << endl;
	cout << "*****  1、添加联系人  *****" << endl;
	cout << "*****  2、显示联系人  *****" << endl;
	cout << "*****  3、删除联系人  *****" << endl;
	cout << "*****  4、查找联系人  *****" << endl;
	cout << "*****  5、修改联系人  *****" << endl;
	cout << "*****  6、清空联系人  *****" << endl;
	cout << "*****  0、退出通讯录  *****" << endl;
	cout << "***************************" << endl;
}


//设计联系人的结构体
struct Person
{
	string m_name;//姓名
	int m_sex; //1男，2女
	int m_age;//年龄
	string m_phone;//电话
	string m_addr;//住址
};

//设计通讯录的结构体
struct Addressbooks
{
	//通讯录中保存的联系人数组
	struct Person personArray[MAX];

	//通讯录中当前记录联系人个数
	int m_size;
};

//添加联系人
void addPerson(Addressbooks*abs)
{
	//判断通讯录是否已满
	if (abs->m_size == MAX)
	{
		cout<<"通讯录已满！！无法添加" << endl;
		return;
	}
	else
	{
		//添加具体联系人

		//姓名
		//string name;
		cout << "请输入姓名：" << endl;
		//cin >> name;
		cin >> abs->personArray[abs->m_size].m_name;
		//abs->personArray[abs->m_size].m_name = name;
		//年龄
		int sex;
		while (true)
		{
			cout << "请输入性别，输入1为男，2为女" << endl;
			cin >> sex;
			if (sex == 1 || sex == 2)
			{
				abs->personArray[abs->m_size].m_sex = sex;
				break;
			}
			else
			{
				cout << "输入有误请重新输入！" << endl;
			}
		}
		//年龄
		//int age;
		cout << "请输入年龄"<<endl;
		//cin >> age;
		cin >> abs->personArray[abs->m_size].m_age;
		//abs->personArray[abs->m_size].m_age = age;

		//电话
		//string phone;
		cout << "请输入联系电话" << endl;
		//cin >> phone;
		cin >> abs->personArray[abs->m_size].m_phone;
		//abs->personArray[abs->m_size].m_phone = phone;

		//住址
		//string addr;
		cout << "请输入家庭住址" << endl;
		//cin >> addr;
		cin >> abs->personArray[abs->m_size].m_addr;
		//abs->personArray[abs->m_size].m_addr = addr;

		//更新通讯录人数
		abs->m_size++;
		cout << "添加成功！！" << endl;

		system("pause");//请俺任意键继续
		system("cls");//清屏操作
	}
}

//显示所有联系人

void showPerson(Addressbooks* abs)
{
	//判断通讯录中是否有记录
	if (abs->m_size == 0)
	{
		cout << "当前的记录为空" << endl;
		system("pause");//请俺任意键继续
		system("cls");//清屏操作
		return;
	}
	else
	{
		for (int i = 0; i < abs->m_size; i++)
		{
			cout << "姓名：" << abs->personArray[i].m_name << "\t";
			cout << "性别：" << abs->personArray[i].m_sex << "\t";
			cout << "年龄：" << abs->personArray[i].m_age << "\t";
			cout << "电话：" << abs->personArray[i].m_phone << "\t";
			cout << "住址：" << abs->personArray[i].m_addr << endl;
		}
		system("pause");
		system("cls");
	}
}
//检测联系人是否存在，如果存在，返回联系人所在数组中的具体位置，不存在返回-1
//参数1 通讯录，参数2，人名
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

//删除指定的联系人
void deletePerson(Addressbooks* abs)
{
	cout << "请输入您要删除的联系人" << endl;
	string name;
	cin >> name;
	int ret = isExist(abs, name);
	if (ret != -1)
	{
		for (int i = ret; i < abs->m_size; i++)
		{
			abs->personArray[i] = abs->personArray[i + 1];
		}
		abs->m_size--;//更新通讯录中的人数
		cout << "删除成功！！" << endl;
	}
	else
	{
		cout<<"查无此人！！！"<<endl;
	}
	system("pause");
	system("cls");

}

//查找联系人
void findPerson(Addressbooks* abs)
{
	cout << "请输入您要查找的联系人" << endl;
	string name;
	cin >> name;
	int ret = isExist(abs, name);
	if ( ret != -1)
	{
				cout << "姓名：" << abs->personArray[ret].m_name << "\t";
				cout << "性别：" << abs->personArray[ret].m_sex << "\t";
				cout << "年龄：" << abs->personArray[ret].m_age << "\t";
				cout << "电话：" << abs->personArray[ret].m_phone << "\t";
				cout << "住址：" << abs->personArray[ret].m_addr << endl;
	}
	else
	{
		cout << "查无此人！！" << endl;
	}
	system("pause");
	system("cls");
}

//修改联系人
void modifyPerson(Addressbooks *abs)
{
	cout << "请输入您要修改的联系人" << endl;
	string name;
	cin >> name;
	int ret = isExist(abs,name);
	if (ret != -1)
	{
		cout << "请输入修改后的名字" << endl;
		cin >> abs->personArray[ret].m_name;
		int sex;
		while (true)
		{
			cout << "请输入修改后性别" << endl;
			cout << "1-----男" << endl;
			cout << "2-----女" << endl;
			cin >> sex;
			if (sex == 1 || sex == 2)
			{
				abs->personArray[ret].m_sex = sex;
				break;
			}
			cout << "您的输入有误，请重新输入！！" << endl;
		}
		cout << "请输入修改后年龄" << endl;
		cin >> abs->personArray[ret].m_age;
		cout << "请输入修改后电话" << endl;
		cin >> abs->personArray[ret].m_phone;
		cout << "请输入修改后住址" << endl;
		cin >> abs->personArray[ret].m_addr;
	}
	else
	{
		cout << "查无此人！！" << endl;
	}
	system("pause");
	system("cls");
}

//清空联系人 通讯录记录人数置为0
void cleanPerson(Addressbooks* abs)
{
	int ret;
	cout << "是否要清空？"<<endl;
	cout << "1-----清空" << endl;
	cout << "2---不清空" << endl;
	cin >> ret;
	if (ret == 1)
	{
		abs->m_size = 0;
		cout << "已清空！" << endl;
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

	//创建通讯录结构体变量
	Addressbooks abs;
	//初始化通讯录中当前的个数
	abs.m_size = 0;

	int select = 0;

	while (true)
	{
		
		showMenu();//菜单的调用

		cin >> select;

		switch (select)
		{
		case 1 ://1、添加联系人
			addPerson(&abs);//利用地址传递，可以修改实参
			break;
		case 2://2、显示联系人
			showPerson(&abs);
			break;
		case 3://3、删除联系人
		{
			/*cout << "请输入要删除的姓名" << endl;
			string name;
			cin >> name;
			if (isExist(&abs, name) == -1)
			{
				cout << "查无此人！！" << endl;
			}
			else
			{
				cout << "找到此人！！" << endl;
			}*/
			deletePerson(&abs);
			break;
		}
		case 4://4、查找联系人
			findPerson(&abs);
			break;
		case 5://5、修改联系人
			modifyPerson(&abs);
			break;
		case 6://6、清空联系人
			cleanPerson(&abs);
			break;
		case 0://0、退出通讯录
			cout << "*****  欢迎下次使用   *****" << endl;
			system("pause");
			return 0;
			break;
		}
	}
	system("pause");
	return 0;
}