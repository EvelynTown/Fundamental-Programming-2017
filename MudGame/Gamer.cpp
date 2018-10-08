#include"Gamer.h"

//密码输入不被看见
bool GamerClass::Code()
{
	char pw[50], ch;
	const char *syspw = Password.data(); // 原始密码
	int i, m = 0;
	cout << "请输入密码:";
	while (m < 3) {
		i = 0;
		while ((ch = _getch()) != '\r') {
			if (ch == '\b' && i > 0) {
				cout << "\b \b";
				--i;
			}
			else if (ch != '\b') {
				pw[i++] = ch;
				cout << "*";
			}
		}
		pw[i] = '\0';
		cout << endl;;
		if (strcmp(pw, syspw) != 0) {
			cout << "密码错误，请重新输入!" << endl;
			m++;
		}
		else {
			cout << "密码正确！" << endl;
			system("cls");
			return 1;
		}
	}
	cout << "连续3次输入错误!" << endl;
	system("cls");
	return 0;
}

//创建一个新的角色
void GamerClass::RoleCreate(vector<School>sch)
{
	Role RoleTemp;
	cout << "请输入昵称:";
	string acc;
	cin>>acc;
	while (!NameRep(acc)) {
		cout << "改昵称已存在，换一个" << endl;
		cin >> acc;
	}
	RoleTemp.RoleName = acc;
	for (int i = 0; i < sch.size(); i++) {
		cout << "名称:" << sch[i].SchoolName << endl;
		cout << "介绍:" << sch[i].Descript << endl;
		cout << "武器:" << sch[i].Weapon << endl;
		cout << "技能:" << endl;
		for (int j = 0; j < sch[i].Skills.size(); j++) {
			cout << "技能名字:" << sch[i].Skills[i].SkillName << endl;
			cout << "技能描述:" << sch[i].Skills[i].Descript << endl;
			cout << "增益效果:" << sch[i].Skills[i].plus << endl;
			cout << endl;
		}
		cout << endl;
	}
	cout << "请输入门派:";
	string school;
	cin >> school;
	for (int i = 0; i < sch.size(); i++) {
		if (school.compare(sch[i].SchoolName) == 0)
			RoleTemp.SchoolIn = sch[i];
	}
	RoleTemp.Experience = 0;
	RoleTemp.Atk = 20;
	RoleTemp.HP = 20;
	RoleTemp.Def = 20;
	RoleTemp.Grade = 1;
	//初始装备信息
	RoleTemp.Wearing.StuffName = "布衣";
	RoleTemp.Wearing.Add = 0;
	RoleTemp.Wearing.Count = 1;
	RoleTemp.Wearing.Descript = "羞耻匿";
	RoleTemp.Wearing.Price = 0;
	RoleTemp.Wearing.Type = "装备";
	//背包信息
	RoleTemp.bag.Capacity = 20;
	RoleTemp.bag.Coin = 1000;

	Roles.push_back(RoleTemp);
	cout << "角色创建成功" << endl;
}

//删除一个角色
void GamerClass::RoleDelete(string NickName)
{
	if (Roles.size() == 1)
		cout << "只有一个角色，别删了别删了" << endl;
	else if (Roles.size() > 1) {
		int count = 0;
		bool flag = 0;
		for (count; count < Roles.size(); count++) {
			if (Roles[count].RoleName == NickName)
				flag = 1;
			break;
		}
		if (flag == 1) {
			Roles.erase(Roles.begin() + count - 1);
			cout << "删除成功" << endl;
		}
		else
			cout << "假的 不存在的~" << endl;
	}
}

//判断该昵称是否存在
bool GamerClass::NameRep(string name)
{
	for (int i = 0; i < Roles.size(); i++)
		if (name.compare(Roles[i].RoleName) == 0)
			return 1;
	return 0;
}

//注册
void AccCreate(vector<GamerClass>&gamers, vector <School>sch)
{
	string acc, psw,psw1;
	cout << "请输入用户名:";
	cin >> acc;
	while (1) {
		cout << "请输入密码:";
		cin >> psw;
		if (psw.size() < 6)
			cout << "密码长度不够请重新输入" << endl;
		else
			break;
	}		
	cout << "请确认密码:";
	cin >> psw1;
	while (!Correct(psw, psw1)) {
		cout << "两次密码输入不一致！" << endl;
		cout << "请输入密码:";
		cin >> psw;
		cout << "请确认密码:";
		cin >> psw1;
	}
	//开始倒腾角色
	Role RoleTemp;
	cout << "请输入角色昵称:";
	string NickName;
	cin >> NickName;
	RoleTemp.RoleName = NickName;
	for (int i = 0; i < sch.size(); i++) {
		cout << "名称:" << sch[i].SchoolName << endl;
		cout << "介绍:" << sch[i].Descript << endl;
		cout << "武器:" << sch[i].Weapon << endl;
		cout << "技能:" << endl;
		for (int j = 0; j < sch[i].Skills.size(); j++) {
			cout << "技能名字:" << sch[i].Skills[j].SkillName << endl;
			cout << "技能描述:" << sch[i].Skills[j].Descript << endl;
			cout << "增益效果:" << sch[i].Skills[j].plus << endl;
			cout << endl;
		}
		cout << endl;
	}
	cout << "请输入门派:";
	string school;
	cin >> school;
	for (int i = 0; i < sch.size(); i++) {
		if (school.compare(sch[i].SchoolName) == 0)
			RoleTemp.SchoolIn = sch[i];
	}
	RoleTemp.Experience = 0;
	RoleTemp.Atk = 20;
	RoleTemp.HP = 20;
	RoleTemp.Def = 20;
	RoleTemp.Grade = 1;
	//初始装备信息
	RoleTemp.Wearing.StuffName = "布衣";
	RoleTemp.Wearing.Add = 0;
	RoleTemp.Wearing.Count = 1;
	RoleTemp.Wearing.Descript = "羞耻匿";
	RoleTemp.Wearing.Price = 0;
	RoleTemp.Wearing.Type = "装备";
	//背包信息
	RoleTemp.bag.Capacity = 20;
	RoleTemp.bag.Coin = 1000;

	GamerClass gamerT(acc, psw, RoleTemp);
	gamers.push_back(gamerT);
	cout << "注册成功!" << endl;
}

//两次密码是否一致
bool Correct(string psw, string psw1)
{
	if (psw.compare(psw1) != 0)
		return 0;
	else
		return 1;
}

//角色显示
void GamerClass::RoleShow()
{
	for (int i = 0; i < Roles.size(); i++)
		cout << "昵称:" << Roles[i].RoleName << "\t\t" << "门派:" << Roles[i].SchoolIn.SchoolName << endl;
	cout << endl;
}

//整形转换成字符串
string IntToStr(vector<int>n)
{
	string str;
	for (int i = 0; i < n.size(); i++)
	{
		str += to_string(n[i]);
		if (i < n.size() - 1)
			str += ',';
	}
	return str;
}

//返回当前角色信息
bool GamerClass::ReturnRole(Role &rolePre, string NickName,int &n)
{
	for (int i = 0; i < Roles.size(); i++)
		if (NickName.compare(Roles[i].RoleName) == 0)
		{
			rolePre = Roles[i];
			n = i;
			return 1;
		}
	return 0;
}