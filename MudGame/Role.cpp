#include"Role.h"

//��ʾ��ǰ��ɫ��Ϣ
void IdentityShow(Role OneRole, vector<Task>tasks)
{
	cout << "��ǰ��ɫ��Ϣ��" << endl;
	cout << "�ǳ�:" << OneRole.RoleName << endl;
	cout << "����:" << OneRole.SchoolIn.SchoolName << endl;
	cout << "����:" << OneRole.HP << endl;
	cout << "����:" << OneRole.Atk << endl;
	cout << "����:" << OneRole.Def << endl;
	cout << "�ȼ�:" << OneRole.Grade << endl;
	cout << "����:" << OneRole.Experience << endl;
	cout << "װ��:" << OneRole.Wearing.StuffName << endl;
	cout << "����ɵ�����:";
	for (int i = 0; i < OneRole.TaskCpl.size(); i++)
		cout << tasks[OneRole.TaskCpl[i]].TaskName << ' ';
	cout << endl;
	cout << "����:";
	for (int i = 0; i < OneRole.bag.Things.size(); i++)
		cout << OneRole.bag.Things[i].StuffName << ' ';
	cout << endl;
	cout << "���:" << OneRole.bag.Coin << endl;
	cout << endl;
}

//����
void LevelUp(Role &OneRole)
{
	int temp = OneRole.Grade;
	if (OneRole.Experience <= 8)
		OneRole.Grade = 1;
	else if (OneRole.Experience <= 24)
		OneRole.Grade = 2;
	else if (OneRole.Experience <= 48)
		OneRole.Grade = 3;
	else if (OneRole.Experience <= 80)
		OneRole.Grade = 4;
	else if (OneRole.Experience <= 120)
		OneRole.Grade = 5;
	else if (OneRole.Experience <= 168)
		OneRole.Grade = 6;
	else if (OneRole.Experience <= 224)
		OneRole.Grade = 7;
	else if (OneRole.Experience <= 288)
		OneRole.Grade = 8;
	else if (OneRole.Experience <= 360)
		OneRole.Grade = 9;
	else if (OneRole.Experience <= 440)
		OneRole.Grade = 10;
	else if (OneRole.Experience <= 528)
		OneRole.Grade = 11;
	else if (OneRole.Experience <= 624)
		OneRole.Grade = 12;
	else if (OneRole.Experience <= 728)
		OneRole.Grade = 13;
	else if (OneRole.Experience <= 840)
		OneRole.Grade = 14;
	else if (OneRole.Experience <= 960)
		OneRole.Grade = 15;
	else if (OneRole.Experience <= 1088)
		OneRole.Grade = 16;
	else if (OneRole.Experience <= 1224)
		OneRole.Grade = 17;
	else if (OneRole.Experience <= 1368)
		OneRole.Grade = 18;
	else if (OneRole.Experience <= 1520)
		OneRole.Grade = 19;
	else
		OneRole.Grade = 20;
	if (temp != OneRole.Grade && OneRole.Grade < 20)
	{
		cout << "�������ˣ�" << endl;
		cout << "��ǰ�ȼ�:" << OneRole.Grade << endl;
	}
	else if (temp != OneRole.Grade &&OneRole.Grade == 20)
		cout << "666666666666��������" << endl;
}

//��ʾ������Ϣ
void BagShow(Role OneRole)
{
	cout << "������Ϣ:" << endl;
	cout << "���:" << OneRole.bag.Coin << endl;
	cout << "ʣ��ռ�:" << 20 - OneRole.bag.Things.size() << endl;
	for (int i = 0; i < OneRole.bag.Things.size(); i++) {
		cout << "��Ʒ����\t����\t�۸�\t��Ŀ" << endl;
		cout << OneRole.bag.Things[i].StuffName << '\t' << OneRole.bag.Things[i].Type << '\t' << OneRole.bag.Things[i].Price << '\t' << OneRole.bag.Things[i].Count << endl;
	}
	cout << endl;
}

//�жϸ������ǲ���������
bool TaskFin(int TaskNum, vector<Monster>mst, vector<Task>tsk)
{
	for (int i = 0; i < tsk[TaskNum].MstToKill.size(); i++) {
		if (mst[tsk[TaskNum].MstToKill[i]].Beat == 0)
			return 0;
	}
	return 1;
}

//��ʾ�̵�
void ShopShow(vector<Stuff>Shop)
{
	cout << "����\t�۸�\t����\t����" << endl;
	for (int i = 0; i < Shop.size(); i++)
		if (Shop[i].Price > 0)
			cout << Shop[i].StuffName << '\t' << Shop[i].Price << '\t' << Shop[i].Type << '\t' << Shop[i].Descript << endl;
}

//ȥ�̵�����
void BuyStuff(vector<Stuff>Shop, Role &RoleNow)
{
	string stuff;
	cout << "������Ҫ�������Ʒ:";
	cin >> stuff;
	bool flag = 0, flag2 = 0;//flag���Ƿ񱳰������и���Ʒ
	ShopShow(Shop);
	for (int i = 0; i < Shop.size(); i++) {
		if (stuff.compare(Shop[i].StuffName) == 0) {
			flag2 = 1;
			if (RoleNow.bag.Coin - Shop[i].Price < 0)
				cout << "��Ҳ���,����ʧ��" << endl;
			else {
				for (int j = 0; j < RoleNow.bag.Things.size(); j++) {
					if (stuff.compare(RoleNow.bag.Things[j].StuffName) == 0) {
						RoleNow.bag.Things[j].Count++;
						RoleNow.bag.Coin -= Shop[i].Price;
						cout << "����ɹ���" << endl;
						flag = 1;
						break;
					}
				}
				if (flag == 0 && RoleNow.bag.Things.size() == 20)
					cout << "����������" << endl;
				//�����ڻ���λ��
				else if (flag == 0 && RoleNow.bag.Things.size() < 20) {
					RoleNow.bag.Things.push_back(Shop[i]);
					RoleNow.bag.Coin -= Shop[i].Price;
					cout << "����ɹ���" << endl;
				}
				
			}		
			break;
		}
	}
	if (!flag2)
		cout << "�̵���û���������" << endl;
}

//��ҩ�ʳƷ && ������
void EatStuff(Role &OneRole)
{
	cout << "����Ҫʳ�õ���Ʒ:";
	string stuff;
	cin >> stuff;
	int StuffNum = -1;
	bool flag = 0;
	for (int i = 0; i < OneRole.bag.Things.size(); i++) {
		if (stuff.compare(OneRole.bag.Things[i].StuffName) == 0 && OneRole.bag.Things[i].Type.compare("ҩƷ") == 0) {
			StuffNum = i;
			flag = 1;
		}
	}
	if (flag) {
		if (OneRole.bag.Things[StuffNum].Count == 1) 
			OneRole.bag.Things.erase(OneRole.bag.Things.begin() + StuffNum - 1);
		else if (OneRole.bag.Things[StuffNum].Count > 1)
			OneRole.bag.Things[StuffNum].Count--;
		OneRole.HP += OneRole.bag.Things[StuffNum].Add;
	}
	else
		cout << "����û�и���Ʒ�����Ʒ����ʳ�ã�" << endl;
}

//��ҩ�ʳƷ
void SellStuff(Role &OneRole)
{
	cout << "����Ҫ��������Ʒ:";
	string stuff;
	cin >> stuff;
	int StuffNum = -1;
	bool flag = 0;
	for (int i = 0; i < OneRole.bag.Things.size(); i++) {
		if (stuff.compare(OneRole.bag.Things[i].StuffName) == 0 ) {
			StuffNum = i;
			flag = 1;
		}
	}
	if (flag) {
		if (OneRole.bag.Things[StuffNum].Count == 1)
			OneRole.bag.Things.erase(OneRole.bag.Things.begin() + StuffNum - 1);
		else if (OneRole.bag.Things[StuffNum].Count > 1)
			OneRole.bag.Things[StuffNum].Count--;
		OneRole.bag.Coin += OneRole.bag.Things[StuffNum].Price;
	}
	else
		cout << "����û�и���Ʒ��" << endl;
}

//�ж��Ƿ���������������
bool GameOver(vector<Task>task)
{
	for (int i = 0; i < task.size(); i++)
		if (task[i].Complete == 0)
			return 0;
	return 1;
}