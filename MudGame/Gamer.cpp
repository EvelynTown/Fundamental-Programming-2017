#include"Gamer.h"

//�������벻������
bool GamerClass::Code()
{
	char pw[50], ch;
	const char *syspw = Password.data(); // ԭʼ����
	int i, m = 0;
	cout << "����������:";
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
			cout << "�����������������!" << endl;
			m++;
		}
		else {
			cout << "������ȷ��" << endl;
			system("cls");
			return 1;
		}
	}
	cout << "����3���������!" << endl;
	system("cls");
	return 0;
}

//����һ���µĽ�ɫ
void GamerClass::RoleCreate(vector<School>sch)
{
	Role RoleTemp;
	cout << "�������ǳ�:";
	string acc;
	cin>>acc;
	while (!NameRep(acc)) {
		cout << "���ǳ��Ѵ��ڣ���һ��" << endl;
		cin >> acc;
	}
	RoleTemp.RoleName = acc;
	for (int i = 0; i < sch.size(); i++) {
		cout << "����:" << sch[i].SchoolName << endl;
		cout << "����:" << sch[i].Descript << endl;
		cout << "����:" << sch[i].Weapon << endl;
		cout << "����:" << endl;
		for (int j = 0; j < sch[i].Skills.size(); j++) {
			cout << "��������:" << sch[i].Skills[i].SkillName << endl;
			cout << "��������:" << sch[i].Skills[i].Descript << endl;
			cout << "����Ч��:" << sch[i].Skills[i].plus << endl;
			cout << endl;
		}
		cout << endl;
	}
	cout << "����������:";
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
	//��ʼװ����Ϣ
	RoleTemp.Wearing.StuffName = "����";
	RoleTemp.Wearing.Add = 0;
	RoleTemp.Wearing.Count = 1;
	RoleTemp.Wearing.Descript = "�߳���";
	RoleTemp.Wearing.Price = 0;
	RoleTemp.Wearing.Type = "װ��";
	//������Ϣ
	RoleTemp.bag.Capacity = 20;
	RoleTemp.bag.Coin = 1000;

	Roles.push_back(RoleTemp);
	cout << "��ɫ�����ɹ�" << endl;
}

//ɾ��һ����ɫ
void GamerClass::RoleDelete(string NickName)
{
	if (Roles.size() == 1)
		cout << "ֻ��һ����ɫ����ɾ�˱�ɾ��" << endl;
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
			cout << "ɾ���ɹ�" << endl;
		}
		else
			cout << "�ٵ� �����ڵ�~" << endl;
	}
}

//�жϸ��ǳ��Ƿ����
bool GamerClass::NameRep(string name)
{
	for (int i = 0; i < Roles.size(); i++)
		if (name.compare(Roles[i].RoleName) == 0)
			return 1;
	return 0;
}

//ע��
void AccCreate(vector<GamerClass>&gamers, vector <School>sch)
{
	string acc, psw,psw1;
	cout << "�������û���:";
	cin >> acc;
	while (1) {
		cout << "����������:";
		cin >> psw;
		if (psw.size() < 6)
			cout << "���볤�Ȳ�������������" << endl;
		else
			break;
	}		
	cout << "��ȷ������:";
	cin >> psw1;
	while (!Correct(psw, psw1)) {
		cout << "�����������벻һ�£�" << endl;
		cout << "����������:";
		cin >> psw;
		cout << "��ȷ������:";
		cin >> psw1;
	}
	//��ʼ���ڽ�ɫ
	Role RoleTemp;
	cout << "�������ɫ�ǳ�:";
	string NickName;
	cin >> NickName;
	RoleTemp.RoleName = NickName;
	for (int i = 0; i < sch.size(); i++) {
		cout << "����:" << sch[i].SchoolName << endl;
		cout << "����:" << sch[i].Descript << endl;
		cout << "����:" << sch[i].Weapon << endl;
		cout << "����:" << endl;
		for (int j = 0; j < sch[i].Skills.size(); j++) {
			cout << "��������:" << sch[i].Skills[j].SkillName << endl;
			cout << "��������:" << sch[i].Skills[j].Descript << endl;
			cout << "����Ч��:" << sch[i].Skills[j].plus << endl;
			cout << endl;
		}
		cout << endl;
	}
	cout << "����������:";
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
	//��ʼװ����Ϣ
	RoleTemp.Wearing.StuffName = "����";
	RoleTemp.Wearing.Add = 0;
	RoleTemp.Wearing.Count = 1;
	RoleTemp.Wearing.Descript = "�߳���";
	RoleTemp.Wearing.Price = 0;
	RoleTemp.Wearing.Type = "װ��";
	//������Ϣ
	RoleTemp.bag.Capacity = 20;
	RoleTemp.bag.Coin = 1000;

	GamerClass gamerT(acc, psw, RoleTemp);
	gamers.push_back(gamerT);
	cout << "ע��ɹ�!" << endl;
}

//���������Ƿ�һ��
bool Correct(string psw, string psw1)
{
	if (psw.compare(psw1) != 0)
		return 0;
	else
		return 1;
}

//��ɫ��ʾ
void GamerClass::RoleShow()
{
	for (int i = 0; i < Roles.size(); i++)
		cout << "�ǳ�:" << Roles[i].RoleName << "\t\t" << "����:" << Roles[i].SchoolIn.SchoolName << endl;
	cout << endl;
}

//����ת�����ַ���
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

//���ص�ǰ��ɫ��Ϣ
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