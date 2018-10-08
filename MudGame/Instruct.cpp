#include"Instruct.h"
#include"File.h"
#include"Map.h"
#include"Gamer.h"
#include"Role.h"


vector<Stuff>Shop;				//�̵�
vector<GamerClass>GamerTotal;	//�ܵ��û�
vector<City>MapTotal;			//��ͼ
vector<School>SchoolTotal;		//����
vector<NPC>NPCTotal;			//�ܵ�NPC
vector<Monster>MstTotal;		//�ܵĹ�
vector<Task>TaskTotal;			//�ܵ�����
GamerClass gamer;				//��ǰ��¼���û�
Role RolePre;					//��ǰ�Ľ�ɫ
FileClass FileTotal;

//���Ͻ���ָ��
void InstructLoop()
{
	bool save = 0;	//�ж��Ƿ񱣴��
	string istr;
	//���뱳���ļ�
	FileTotal.FileInBackgroung(MapTotal, SchoolTotal, Shop, NPCTotal, MstTotal, TaskTotal);
	//�����û���Ϣ
	FileTotal.FileInGamer(GamerTotal, SchoolTotal, Shop);
	//��ͼ��
	MapClass Map(MapTotal, NPCTotal, MstTotal, TaskTotal);
	//Print(MapTotal, SchoolTotal, Shop, NPCTotal, MstTotal);
	int SceneNum = 4, NPCNum = -1, TaskNum = -1, MstNum = -1, GamerNum = -1, RoleNum = -1;
	
	while (1) {
		cout << "��ѡ���¼��LogIn����ע�᡾RollIn��:";
		cin >> istr;

		//��¼
		if (istr == "LogIn") {
			cout << "�������û�����";
			string acc;
			cin >> acc;
			bool flag = 0;
			for (int i = 0; i < GamerTotal.size(); i++)
				if (acc.compare(GamerTotal[i].AccReturn()) == 0) {
					gamer = GamerTotal[i];
					GamerNum = i;
					flag = 1;
				}
			if (flag)
				break;
			else
				cout << "���û������ڣ�" << endl;
		}

		//ע��
		else if (istr == "RollIn") {
			AccCreate(GamerTotal, SchoolTotal);
			gamer = GamerTotal.back();
			GamerNum = GamerTotal.size() - 1;
			break;
		}

		else if (istr.compare("LogIn") != 0 && istr.compare("RollIN") != 0)
			cout << "�����ָ�" << endl;
	}
		
	//��½�ɹ�
	if (gamer.Code()) {
		string NickName;
		while (1) {
			cout << "������ָ��ѡ�������н�ɫ��Pre����ʼ��Ϸ������ע�᡾New����ɾ����ɫ��Del��:";
			cin >> istr;
			//ѡ���ɫ��¼
			if (istr.compare("Pre") == 0) {
				//��ʾ�Ѵ��ڵĽ�ɫ��Ϣ
				cout << "�Ѵ��ڵĽ�ɫ:" << endl;
				gamer.RoleShow();
				while (1) {
					cout << "����������ѡ�����Ϸ��ɫ��";
					cin >> NickName;
					//�õ���ɫ��Ϣ�Լ���ɫ���
					if (!gamer.ReturnRole(RolePre, NickName, RoleNum)) {
						cout << "�ý�ɫ�����ڣ�������������Ϸ��ɫ:";
						cin >> NickName;
					}
					else if (gamer.ReturnRole(RolePre, NickName, RoleNum))
						break;
				}
				break;
			}

			//�½���ɫ
			else if (istr.compare("New") == 0) {
				gamer.RoleCreate(SchoolTotal);
			}

			//ɾ����ɫ
			else if (istr.compare("Del") == 0) {
				cout << "������ɾ���Ľ�ɫ:";
				string nikname;
				cin >> nikname;
				gamer.RoleDelete(nikname);
			}
			
		}
		
		for (int i = 0; i < RolePre.TaskCpl.size(); i++)
			TaskTotal[RolePre.TaskCpl[i]].Complete = 1;

		system("cls");

		cout << "��Ϸ��ʼ��" << endl;
		while (1) {
			cout << "����ָ��:";
			cin >> istr;
			//�����ĵ�
			if (istr.compare(0, 8, "LoadFile") == 0)
				cout << "��Ϸ��ʼ����ɡ�" << endl;

			//�ƶ�
			else if (istr.compare(0, 4, "Goto") == 0) {
				//ȥ��߸�
				if (istr.compare(4, istr.size() - 4, "��߸�") == 0) {
					cout << "����λ�ã���߸�" << endl;
					SceneNum = 0;
				}
				//ȥ������
				else if (istr.compare(4, istr.size() - 4, "������") == 0) {
					cout << "����λ�ã�������" << endl;
					SceneNum = 1;
				}
				//ȥ������
				else if (istr.compare(4, istr.size() - 4, "������") == 0) {
					cout << "����λ�ã�������" << endl;
					SceneNum = 2;
				}
				//ȥ����ɽ
				else if (istr.compare(4, istr.size() - 4, "����ɽ") == 0) {
					cout << "����λ�ã�����ɽ" << endl;
					SceneNum = 3;
				}
				//ȥ���ݳ�
				else if (istr.compare(4, istr.size() - 4, "���ݳ�") == 0) {
					cout << "����λ�ã����ݳ�" << endl;
					SceneNum = 4;
				}
				//�������
				else
					cout << "�ó�����δ���ţ������ڴ���" << endl;
			}

			//ѡ�����񡾷���������
			else if (istr.compare(0, 7, "GetTask") == 0) {
				int i = 0;
				if (NPCTotal[NPCNum].NPCName == "����˧"&&istr.compare(7, istr.size() - 7, "��������") == 0)
					cout << "����Ϊ����������ô���״���???" << endl;
				else {
					for (i = 0; i < TaskTotal.size(); i++) {
						if (istr.compare(7, istr.size() - 7, TaskTotal[i].TaskName) == 0) {
							TaskNum = i;
							if (TaskTotal[TaskNum].Complete == 1)
								cout << "�������Ѿ���ɣ�" << endl;
							else {
								cout << NPCTotal[NPCNum].NPCName << ":" << TaskTotal[TaskNum].word << endl;
								cout << "��ȡ����" << TaskTotal[TaskNum].TaskName << "���ɹ���" << endl;
								break;
							}
						}
					}
					if (i == NPCTotal[NPCNum].Tasks.size())
						cout << "��������δ����" << endl;
				}
			}

			//ѡ��һ��NPC//ֻ��ѡ��ǰ����
			else if (istr.compare(0, 7, "ChosNPC") == 0) {
				bool q = 0, p = 0;
				for (int i = 0; i < NPCTotal.size(); i++) {
					if (istr.compare(7, istr.size() - 4, NPCTotal[i].NPCName) == 0) {
						for (int j = 0; j < MapTotal[SceneNum].NPC.size(); j++) {
							if (MapTotal[SceneNum].NPC[j] == i) {
								p = 1;
								NPCNum = i;
								Map.NPCInfoShow(i);
								break;
							}
						}
						q = 1;
						break;
					}
				}
				if (q == 0)
					cout << "��NPC��δ����" << endl;
				else if (p == 0)
					cout << "��NPC���ڱ�����" << endl;
			}

			//ɱ��
			else if (istr.compare(0, 6, "Attack") == 0) {
				bool q = 0, p = 0;
				for (int i = 0; i < MstTotal.size(); i++) {
					if (istr.compare(6, istr.size() - 1, MstTotal[i].MonsterName) == 0) {
						for (int j = 0; j < MapTotal[SceneNum].Monster.size(); j++) {
							if (i == MapTotal[SceneNum].Monster[j]) {
								MstNum = i;
								p = 1;
								cout << "��ɱ��" << MstTotal[i].MonsterName << "���ɹ���" << endl;
								cout << "��������:" << MstTotal[i].ExperienceAdd << endl;
								RolePre.Experience += MstTotal[i].ExperienceAdd;
								//�е����� ����Ҫɱ��ֻ�������ʱ��
								if (Map.WhetherTask(TaskNum, MstNum))
									MstTotal[i].Beat = 1;
								
								if (TaskFin(TaskNum, MstTotal, TaskTotal)) {
									RolePre.TaskCpl.push_back(TaskNum);
									TaskTotal[TaskNum].Complete = 1;
									cout << endl;
									cout << "����:" << TaskTotal[TaskNum].TaskName << "�����" << endl;
									cout << "��������:" << TaskTotal[TaskNum].ExperienceAdd << endl;
								}
								LevelUp(RolePre);
								cout << endl;
								break;
							}
						}
						q = 1;
						break;
					}
				}
				if (q == 0)
					cout << "�ù��ﻹ�ڿ���" << endl;
				else if (p == 0)
					cout << "�ù��ﲻ�ڵ�ǰ����" << endl;
			}

			//��ʾ����
			else if (istr.compare(0, 4, "Show") == 0) {

				//��ɫ��Ϣ
				if (istr.compare(4, 6, "IdInfo") == 0) {
					IdentityShow(RolePre, TaskTotal);
				}

				//�̵�
				else if (istr.compare(4, 4, "Shop") == 0) {
					ShopShow(Shop);
				}

				//������Ϣ
				else if (istr.compare(4, 4, "Task") == 0) {
					Map.TaskShow(NPCNum, TaskNum, TaskTotal);
				}

				//������Ϣ
				else if (istr.compare(4, 5, "Scene") == 0) {
					Map.SceneInfoShow(SceneNum);
				}

				//������Ϣ
				else if (istr.compare(4, 3, "Bag") == 0) {
					BagShow(RolePre);
				}

				//��ͼ��Ϣ
				else if (istr.compare(4, 3, "Map") == 0) {
					Map.MapShow();
				}

				//ָ���������
				else
					cout << "�����ָ��" << endl;
			}

			//�˳���Ϸ
			else if (istr.compare("Quit") == 0) {
				if (!save) {
					gamer.RoleModi(RolePre, RoleNum);
					GamerTotal[GamerNum] = gamer;
					FileTotal.FileOutGamer(GamerTotal);
				}
				exit(0);
			}

			//�浵//������
			else if (istr.compare("Save") == 0) {
				gamer.RoleModi(RolePre, RoleNum);
				GamerTotal[GamerNum] = gamer;
				FileTotal.FileOutGamer(GamerTotal);
				save = 1;
				cout << "�û���Ϣ����ɹ���" << endl;
			}

			//����
			else if (istr.compare("Buy") == 0) {
				ShopShow(Shop);
				BuyStuff(Shop, RolePre);
			}

			//������
			else if (istr.compare("Sell") == 0) {
				BagShow(RolePre);
				SellStuff(RolePre);
			}

			//�Զ���
			else if (istr.compare("Eat") == 0) {
				BagShow(RolePre);
				EatStuff(RolePre);
			}

			//�������񴥷�
			else if (NPCTotal[NPCNum].NPCName.compare("����˧") && istr.compare("����н��С����") == 0) {
				TaskNum = 6;
				cout << NPCTotal[NPCNum].NPCName << ':' << TaskTotal[TaskNum].word << endl;
				string str;
				cin >> str;
				if (str.compare("��˼����˧��") == 0)
				{
					TaskTotal[TaskNum].Complete = 1;
					RolePre.TaskCpl.push_back(TaskNum);
					RolePre.Experience += TaskTotal[TaskNum].ExperienceAdd;
					cout << "�����ǰ� ������ɣ�" << endl;
					LevelUp(RolePre);
				}
				else
					cout << "��������ⶼ�䲻�ԣ�" << endl;
			}

			//ָ���������
			else
				cout << "�����ָ��" << endl;
		}
		cout << endl;
	}

}