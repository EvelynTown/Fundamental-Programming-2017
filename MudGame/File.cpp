#include"File.h"

//读档背景文件,存入怪物、npc、地图、门派、商店
void FileClass::FileInBackgroung(vector<City>&map, vector<School>&school, vector<Stuff>&shop, vector<NPC>&npc,vector<Monster>&monster,vector<Task>&tasks)
{
	XMLDocument doc;
	doc.LoadFile("Background.xml");
	if (!doc.LoadFile("Background.xml")) {
		XMLElement *Background_P = doc.RootElement();
		XMLElement *BkgEle = Background_P->FirstChildElement();
		XMLElement *City_P = BkgEle->FirstChildElement();
		int MstN = 0, CityN = 0, TaskN = 0, NpcN = 0, SchN = 0, SklN = 0, StfN = 0;
		while (City_P) {
			City OneCity;
			OneCity.CityNum = CityN;
			CityN++;
			XMLElement *CityEle = City_P->FirstChildElement();
			OneCity.CityName = CityEle->GetText();
			CityEle = CityEle->NextSiblingElement();
			OneCity.Descript = CityEle->GetText();
			CityEle = CityEle->NextSiblingElement();
			XMLElement *NPC_P = CityEle->FirstChildElement();
			while (NPC_P) {
				XMLElement *NPCEle = NPC_P->FirstChildElement();
				NPC NPCTemp;
				NPCTemp.NPCNum = NpcN;
				NpcN++;
				NPCTemp.NPCName = NPCEle->GetText();
				NPCEle = NPCEle->NextSiblingElement();
				NPCTemp.Descript = NPCEle->GetText();
				NPCEle = NPCEle->NextSiblingElement();
				XMLElement *Task_P = NPCEle->FirstChildElement();
				while (Task_P) {
					XMLElement *TaskEle = Task_P->FirstChildElement();
					Task TaskTemp;
					TaskTemp.TaskNum = TaskN;
					TaskN++;
					TaskTemp.Complete = 0;
					TaskTemp.TaskName = TaskEle->GetText();
					TaskEle = TaskEle->NextSiblingElement();
					TaskTemp.word = TaskEle->GetText();
					TaskEle = TaskEle->NextSiblingElement();
					TaskTemp.ExperienceAdd = StrToInt(TaskEle->GetText());
					TaskEle = TaskEle->NextSiblingElement();
					vector<int>Ntemp;
					StrToIntVec(TaskEle->GetText(), Ntemp);
					TaskTemp.MstToKill = Ntemp;
					NPCTemp.Tasks.push_back(TaskTemp.TaskNum);
					tasks.push_back(TaskTemp);
					Task_P = Task_P->NextSiblingElement();
				}//读完任务信息
				OneCity.NPC.push_back(NPCTemp.NPCNum);
				npc.push_back(NPCTemp);
				NPC_P = NPC_P->NextSiblingElement();
			}//读完NPC信息
			CityEle = CityEle->NextSiblingElement();
			XMLElement *Mst_P = CityEle->FirstChildElement();
			while (Mst_P) {
				XMLElement *MstEle = Mst_P->FirstChildElement();
				Monster MstTemp;
				MstTemp.MonsterNum = MstN;
				MstN++;
				MstTemp.Beat = 0;
				MstTemp.MonsterName = MstEle->GetText();
				MstEle = MstEle->NextSiblingElement();
				MstTemp.Descript = MstEle->GetText();
				MstEle = MstEle->NextSiblingElement();
				MstTemp.HP = StrToInt(MstEle->GetText());
				MstEle = MstEle->NextSiblingElement();
				MstTemp.Atk = StrToInt(MstEle->GetText());
				MstEle = MstEle = MstEle->NextSiblingElement();
				MstTemp.Def = StrToInt(MstEle->GetText());
				MstEle = MstEle = MstEle->NextSiblingElement();
				MstTemp.ExperienceAdd = StrToInt(MstEle->GetText());
				OneCity.Monster.push_back(MstTemp.MonsterNum);
				monster.push_back(MstTemp);
				Mst_P = Mst_P->NextSiblingElement();
			}//小怪信息读完
			map.push_back(OneCity);
			City_P = City_P->NextSiblingElement();
		}
		BkgEle = BkgEle->NextSiblingElement();//开始读取商店
		XMLElement *Stf_P = BkgEle->FirstChildElement();
		while (Stf_P) {
			Stuff StfTemp;
			StfTemp.StuffNum = StfN;
			StfN++;
			StfTemp.Count = 0;
			XMLElement *StfEle = Stf_P->FirstChildElement();
			StfTemp.StuffName = StfEle->GetText();
			StfEle = StfEle->NextSiblingElement();
			StfTemp.Descript = StfEle->GetText();
			StfEle = StfEle->NextSiblingElement();
			StfTemp.Add = StrToInt(StfEle->GetText());
			StfEle = StfEle->NextSiblingElement();
			StfTemp.Price = StrToInt(StfEle->GetText());
			StfEle = StfEle->NextSiblingElement();
			StfTemp.Type = StfEle->GetText();
			shop.push_back(StfTemp);
			Stf_P = Stf_P->NextSiblingElement();
		}
		BkgEle = BkgEle->NextSiblingElement();//开始读取门派
		XMLElement *Sch_P = BkgEle->FirstChildElement();
		while (Sch_P) {
			School SchTemp;
			SchTemp.SchoolNum = SchN;
			SchN++;
			XMLElement *SchEle = Sch_P->FirstChildElement();
			SchTemp.SchoolName = SchEle->GetText();
			SchEle = SchEle->NextSiblingElement();
			SchTemp.Descript = SchEle->GetText();
			SchEle = SchEle->NextSiblingElement();
			XMLElement *Skl_P = SchEle->FirstChildElement();
			while (Skl_P) {
				XMLElement *SklEle = Skl_P->FirstChildElement();
				Skill SklTemp;
				SklTemp.SkillNum = SklN;
				SklN++;
				SklTemp.SkillName = SklEle->GetText();
				SklEle = SklEle->NextSiblingElement();
				SklTemp.Descript = SklEle->GetText();
				SklEle = SklEle->NextSiblingElement();
				SklTemp.plus = StrToDbl(SklEle->GetText());
				SchTemp.Skills.push_back(SklTemp);
				Skl_P = Skl_P->NextSiblingElement();
			}
			SchEle = SchEle->NextSiblingElement();
			SchTemp.Weapon = SchEle->GetText();
			school.push_back(SchTemp);
			Sch_P = Sch_P->NextSiblingElement();
		}
	}
	else
		cout << "fail to open the file" << endl;
}

//读档用户信息
void FileClass::FileInGamer(vector<GamerClass>&Gamers, vector<School>school,vector<Stuff>shop)
{
	XMLDocument doc;
	doc.LoadFile("Gamer.xml");
	if (!doc.LoadFile("Gamer.xml")) {
		XMLElement *gamer_p = doc.RootElement();
		XMLElement *user_p = gamer_p->FirstChildElement();
		while (user_p) {
			XMLElement *userEle = user_p->FirstChildElement();
			string acc, psw;
			acc = userEle->GetText();
			userEle = userEle->NextSiblingElement();
			psw = userEle->GetText();
			userEle = userEle->NextSiblingElement();
			vector<Role>RolesTemp;
			XMLElement *role_p = userEle->FirstChildElement();
			while (role_p) {
				Role roleTemp;
				XMLElement *roleEle = role_p->FirstChildElement();
				roleTemp.RoleName = roleEle->GetText();
				roleEle = roleEle->NextSiblingElement();
				roleTemp.SchoolIn = Sch(StrToInt(roleEle->GetText()), school);
				roleEle = roleEle->NextSiblingElement();
				roleTemp.HP = StrToInt(roleEle->GetText());
				roleEle = roleEle->NextSiblingElement();
				roleTemp.Atk = StrToInt(roleEle->GetText());
				roleEle = roleEle->NextSiblingElement();
				roleTemp.Def = StrToInt(roleEle->GetText());
				roleEle = roleEle->NextSiblingElement();
				roleTemp.Experience = StrToInt(roleEle->GetText());
				roleEle = roleEle->NextSiblingElement();
				roleTemp.Grade = StrToInt(roleEle->GetText());
				roleEle = roleEle->NextSiblingElement();

				vector<int>bagN;
				StrToIntVec(roleEle->GetText(), bagN);
				BagStf(bagN, roleTemp.bag, shop);
				roleEle = roleEle->NextSiblingElement();
				//
				roleTemp.bag.Coin = StrToInt(roleEle->GetText());
				roleEle = roleEle->NextSiblingElement();

				vector<int>Tasknum;
				StrToIntVec(roleEle->GetText(), Tasknum);
				roleEle = roleEle->NextSiblingElement();
				roleTemp.TaskCpl = Tasknum;

				roleTemp.Wearing = StfNum(StrToInt(roleEle->GetText()),shop);
				RolesTemp.push_back(roleTemp);
				role_p = role_p->NextSiblingElement();
			}
			GamerClass gamerTemp(acc, psw, RolesTemp);
			Gamers.push_back(gamerTemp); 
			user_p = user_p->NextSiblingElement();
		}
	}
	else
		cout << "fail to open the file!" << endl;
}

//存档玩家信息
void FileClass::FileOutGamer(vector<GamerClass>Gamers)
{
	XMLDocument *pDoc = new XMLDocument();
	XMLDeclaration *pDel = pDoc->NewDeclaration("xml version=\"1.0\" encoding=\"UTF-8\"");
	pDoc->LinkEndChild(pDel);

	XMLElement *GamerElement = pDoc->NewElement("Gamer");
	pDoc->LinkEndChild(GamerElement);
	for (int i = 0; i < Gamers.size(); i++) {
		XMLElement *userElement = pDoc->NewElement("user");
		GamerElement->LinkEndChild(userElement);

		XMLElement *accElement = pDoc->NewElement("account");
		accElement->LinkEndChild(pDoc->NewText(Gamers[i].AccReturn().data()));
		userElement->LinkEndChild(accElement);

		XMLElement *pswElement = pDoc->NewElement("psword");
		pswElement->LinkEndChild(pDoc->NewText(Gamers[i].PswReturn().data()));
		userElement->LinkEndChild(pswElement);

		XMLElement *rolesElement = pDoc->NewElement("roles");
		userElement->LinkEndChild(rolesElement);

		vector<Role>Roles;
		Gamers[i].RolesReturn(Roles);
		for (int i = 0; i < Roles.size(); i++) {
			XMLElement *roleElement = pDoc->NewElement("role");

			XMLElement *nameElement = pDoc->NewElement("name");
			nameElement->LinkEndChild(pDoc->NewText(Roles[i].RoleName.data()));
			roleElement->LinkEndChild(nameElement);

			XMLElement *schElement = pDoc->NewElement("sch");
			schElement->LinkEndChild(pDoc->NewText(to_string(Roles[i].SchoolIn.SchoolNum).data()));
			roleElement->LinkEndChild(schElement);

			XMLElement *hpElement = pDoc->NewElement("hp");
			hpElement->LinkEndChild(pDoc->NewText(to_string(Roles[i].HP).data()));
			roleElement->LinkEndChild(hpElement);

			XMLElement *atkElement = pDoc->NewElement("atk");
			atkElement->LinkEndChild(pDoc->NewText(to_string(Roles[i].Atk).data()));
			roleElement->LinkEndChild(atkElement);

			XMLElement *defElement = pDoc->NewElement("def");
			defElement->LinkEndChild(pDoc->NewText(to_string(Roles[i].Def).data()));
			roleElement->LinkEndChild(defElement);

			XMLElement *expElement = pDoc->NewElement("exp");
			expElement->LinkEndChild(pDoc->NewText(to_string(Roles[i].Experience).data()));
			roleElement->LinkEndChild(expElement);

			XMLElement *grdElement = pDoc->NewElement("grd");
			grdElement->LinkEndChild(pDoc->NewText(to_string(Roles[i].Grade).data()));
			roleElement->LinkEndChild(grdElement);

			XMLElement *bagElement = pDoc->NewElement("bag");
			bagElement->LinkEndChild(pDoc->NewText(BagIntVec(Roles[i].bag).data()));
			roleElement->LinkEndChild(bagElement);

			XMLElement *coinElement = pDoc->NewElement("coin");
			coinElement->LinkEndChild(pDoc->NewText(to_string(Roles[i].bag.Coin).data()));
			roleElement->LinkEndChild(coinElement);

			XMLElement *taskElement = pDoc->NewElement("taskCpl");
			taskElement->LinkEndChild(pDoc->NewText(IntToStr(Roles[i].TaskCpl).data()));
			roleElement->LinkEndChild(taskElement);

			XMLElement *wearElement = pDoc->NewElement("wear");
			wearElement->LinkEndChild(pDoc->NewText(to_string(Roles[i].Wearing.StuffNum).data()));
			roleElement->LinkEndChild(wearElement);

			rolesElement->LinkEndChild(roleElement);
		}
	}
	pDoc->SaveFile("Gamer.xml");//保存文件 参数：路径
	pDoc->Print();//打印
	delete pDoc;
}

//string转成int
int StrToInt(string str)
{
	int n = 0;
	for (int i = 0; i < str.size(); i++) {
		n = n * 10 + (int)(str[i] - '0');
	}
	return n;
}

//string转成double
double StrToDbl(string str)
{
	double n = 0, delta = 0;
	bool flag = 0;
	int i = 0, j = 0;
	for (i; str[i] != '.'&&i < str.size(); i++)
		n = n * 10 + (int)(str[i] - '0');
	for (j = i + 1; j < str.size(); j++)
		delta = delta * 10 + (int)(str[j] - '0');
	delta = delta / pow(10, j - i - 1);
	n = n + delta;
	return n;
}

//输出我看一下
void Print(vector<City>map, vector<School>school, vector<Stuff>shop, vector<NPC>npc, vector<Monster>monster)
{
	for (int i = 0; i < map.size(); i++)
		cout << map[i].CityName << ' ';
	cout << endl;
	for (int i = 0; i < school.size(); i++)
		cout << school[i].SchoolName << ' ';
	cout << endl; 
	for (int i = 0; i < shop.size(); i++)
		cout << shop[i].StuffName << ' ';
	cout << endl;
	for (int i = 0; i < npc.size(); i++)
		cout << npc[i]. NPCName<< ' ';
	cout << endl;
	for (int i = 0; i < monster.size(); i++)
		cout << monster[i].MonsterName << ' ';
	cout << endl;
}

//返回门派结构
School Sch(int n, vector<School>school)
{
	for (int i = 0; i < school.size(); i++) {
		if (school[i].SchoolNum == n)
			return school[i];
	}
}

//解析x,x,x的string类转成int数组
void StrToIntVec(string str, vector<int>&num)
{
	int n = 0;
	for (int i = 0; i < str.size(); i++)
	{
		if (str[i] != ',')
			n = n * 10 + (int)(str[i] - '0');
		else
		{
			num.push_back(n);
			n = 0;
		}
	}
	num.push_back(n);
}

//返回一个背包结构
void BagStf(vector<int> num, Bag &bag, vector<Stuff>shop)
{
	bag.Capacity = 20;
	sort(num.begin(), num.end());
	int count = 1, i = 0;
	for (i; i < num.size() - 1; i++)
	{
		if (num[i] == num[i + 1])
			count++;
		else {
			Stuff stfTemp = shop[num[i]];
			stfTemp.Count = count;
			count = 1;
			bag.Things.push_back(stfTemp);
		}
	}
	Stuff stfTemp = shop[num[i]];
	stfTemp.Count = count;
	bag.Things.push_back(stfTemp);
}

//返回物品结构
Stuff StfNum(int n, vector<Stuff>shop)
{
	for (int i = 0; i < shop.size(); i++) {
		if (n == shop[i].StuffNum)
			return shop[i];
	}
}

//返回背包数组
string BagIntVec(Bag bag)
{
	string bagStr;
	for (int i = 0; i < bag.Things.size(); i++) {
		for (int j = 0; j < bag.Things[i].Count; j++)
		{
			bagStr += to_string(bag.Things[i].StuffNum);
			if (i < bag.Things.size() - 1 && j < bag.Things[i].Count - 1)
				bagStr += ',';
		}
	}
	return bagStr;
}