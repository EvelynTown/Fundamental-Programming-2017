#include"Role.h"

//显示当前角色信息
void IdentityShow(Role OneRole, vector<Task>tasks)
{
	cout << "当前角色信息：" << endl;
	cout << "昵称:" << OneRole.RoleName << endl;
	cout << "门派:" << OneRole.SchoolIn.SchoolName << endl;
	cout << "体力:" << OneRole.HP << endl;
	cout << "攻击:" << OneRole.Atk << endl;
	cout << "防御:" << OneRole.Def << endl;
	cout << "等级:" << OneRole.Grade << endl;
	cout << "经验:" << OneRole.Experience << endl;
	cout << "装备:" << OneRole.Wearing.StuffName << endl;
	cout << "已完成的任务:";
	for (int i = 0; i < OneRole.TaskCpl.size(); i++)
		cout << tasks[OneRole.TaskCpl[i]].TaskName << ' ';
	cout << endl;
	cout << "背包:";
	for (int i = 0; i < OneRole.bag.Things.size(); i++)
		cout << OneRole.bag.Things[i].StuffName << ' ';
	cout << endl;
	cout << "金币:" << OneRole.bag.Coin << endl;
	cout << endl;
}

//升级
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
		cout << "您升级了！" << endl;
		cout << "当前等级:" << OneRole.Grade << endl;
	}
	else if (temp != OneRole.Grade &&OneRole.Grade == 20)
		cout << "666666666666您已满级" << endl;
}

//显示背包信息
void BagShow(Role OneRole)
{
	cout << "背包信息:" << endl;
	cout << "金币:" << OneRole.bag.Coin << endl;
	cout << "剩余空间:" << 20 - OneRole.bag.Things.size() << endl;
	for (int i = 0; i < OneRole.bag.Things.size(); i++) {
		cout << "物品名称\t属性\t价格\t数目" << endl;
		cout << OneRole.bag.Things[i].StuffName << '\t' << OneRole.bag.Things[i].Type << '\t' << OneRole.bag.Things[i].Price << '\t' << OneRole.bag.Things[i].Count << endl;
	}
	cout << endl;
}

//判断该任务是不是做完了
bool TaskFin(int TaskNum, vector<Monster>mst, vector<Task>tsk)
{
	for (int i = 0; i < tsk[TaskNum].MstToKill.size(); i++) {
		if (mst[tsk[TaskNum].MstToKill[i]].Beat == 0)
			return 0;
	}
	return 1;
}

//显示商店
void ShopShow(vector<Stuff>Shop)
{
	cout << "名称\t价格\t类型\t描述" << endl;
	for (int i = 0; i < Shop.size(); i++)
		if (Shop[i].Price > 0)
			cout << Shop[i].StuffName << '\t' << Shop[i].Price << '\t' << Shop[i].Type << '\t' << Shop[i].Descript << endl;
}

//去商店买东西
void BuyStuff(vector<Stuff>Shop, Role &RoleNow)
{
	string stuff;
	cout << "请输入要购买的物品:";
	cin >> stuff;
	bool flag = 0, flag2 = 0;//flag：是否背包内已有该物品
	ShopShow(Shop);
	for (int i = 0; i < Shop.size(); i++) {
		if (stuff.compare(Shop[i].StuffName) == 0) {
			flag2 = 1;
			if (RoleNow.bag.Coin - Shop[i].Price < 0)
				cout << "金币不够,购买失败" << endl;
			else {
				for (int j = 0; j < RoleNow.bag.Things.size(); j++) {
					if (stuff.compare(RoleNow.bag.Things[j].StuffName) == 0) {
						RoleNow.bag.Things[j].Count++;
						RoleNow.bag.Coin -= Shop[i].Price;
						cout << "购买成功！" << endl;
						flag = 1;
						break;
					}
				}
				if (flag == 0 && RoleNow.bag.Things.size() == 20)
					cout << "背包已满！" << endl;
				//背包内还有位置
				else if (flag == 0 && RoleNow.bag.Things.size() < 20) {
					RoleNow.bag.Things.push_back(Shop[i]);
					RoleNow.bag.Coin -= Shop[i].Price;
					cout << "购买成功！" << endl;
				}
				
			}		
			break;
		}
	}
	if (!flag2)
		cout << "商店里没有这个东西" << endl;
}

//吃药物、食品 && 卖东西
void EatStuff(Role &OneRole)
{
	cout << "输入要食用的物品:";
	string stuff;
	cin >> stuff;
	int StuffNum = -1;
	bool flag = 0;
	for (int i = 0; i < OneRole.bag.Things.size(); i++) {
		if (stuff.compare(OneRole.bag.Things[i].StuffName) == 0 && OneRole.bag.Things[i].Type.compare("药品") == 0) {
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
		cout << "背包没有该物品或该物品不可食用！" << endl;
}

//卖药物、食品
void SellStuff(Role &OneRole)
{
	cout << "输入要卖掉的物品:";
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
		cout << "背包没有该物品！" << endl;
}

//判断是否所有任务都已做完
bool GameOver(vector<Task>task)
{
	for (int i = 0; i < task.size(); i++)
		if (task[i].Complete == 0)
			return 0;
	return 1;
}