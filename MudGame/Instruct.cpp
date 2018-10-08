#include"Instruct.h"
#include"File.h"
#include"Map.h"
#include"Gamer.h"
#include"Role.h"


vector<Stuff>Shop;				//商店
vector<GamerClass>GamerTotal;	//总的用户
vector<City>MapTotal;			//地图
vector<School>SchoolTotal;		//门派
vector<NPC>NPCTotal;			//总的NPC
vector<Monster>MstTotal;		//总的怪
vector<Task>TaskTotal;			//总的任务
GamerClass gamer;				//当前登录的用户
Role RolePre;					//当前的角色
FileClass FileTotal;

//不断接受指令
void InstructLoop()
{
	bool save = 0;	//判断是否保存过
	string istr;
	//导入背景文件
	FileTotal.FileInBackgroung(MapTotal, SchoolTotal, Shop, NPCTotal, MstTotal, TaskTotal);
	//导入用户信息
	FileTotal.FileInGamer(GamerTotal, SchoolTotal, Shop);
	//地图类
	MapClass Map(MapTotal, NPCTotal, MstTotal, TaskTotal);
	//Print(MapTotal, SchoolTotal, Shop, NPCTotal, MstTotal);
	int SceneNum = 4, NPCNum = -1, TaskNum = -1, MstNum = -1, GamerNum = -1, RoleNum = -1;
	
	while (1) {
		cout << "请选择登录【LogIn】或注册【RollIn】:";
		cin >> istr;

		//登录
		if (istr == "LogIn") {
			cout << "请输入用户名：";
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
				cout << "该用户不存在！" << endl;
		}

		//注册
		else if (istr == "RollIn") {
			AccCreate(GamerTotal, SchoolTotal);
			gamer = GamerTotal.back();
			GamerNum = GamerTotal.size() - 1;
			break;
		}

		else if (istr.compare("LogIn") != 0 && istr.compare("RollIN") != 0)
			cout << "错误的指令！" << endl;
	}
		
	//登陆成功
	if (gamer.Code()) {
		string NickName;
		while (1) {
			cout << "请输入指令选择已现有角色【Pre】开始游戏、重新注册【New】、删除角色【Del】:";
			cin >> istr;
			//选择角色登录
			if (istr.compare("Pre") == 0) {
				//显示已存在的角色信息
				cout << "已存在的角色:" << endl;
				gamer.RoleShow();
				while (1) {
					cout << "请输入你想选择的游戏角色：";
					cin >> NickName;
					//得到角色信息以及角色编号
					if (!gamer.ReturnRole(RolePre, NickName, RoleNum)) {
						cout << "该角色不存在！请重新输入游戏角色:";
						cin >> NickName;
					}
					else if (gamer.ReturnRole(RolePre, NickName, RoleNum))
						break;
				}
				break;
			}

			//新建角色
			else if (istr.compare("New") == 0) {
				gamer.RoleCreate(SchoolTotal);
			}

			//删除角色
			else if (istr.compare("Del") == 0) {
				cout << "输入想删除的角色:";
				string nikname;
				cin >> nikname;
				gamer.RoleDelete(nikname);
			}
			
		}
		
		for (int i = 0; i < RolePre.TaskCpl.size(); i++)
			TaskTotal[RolePre.TaskCpl[i]].Complete = 1;

		system("cls");

		cout << "游戏开始！" << endl;
		while (1) {
			cout << "输入指令:";
			cin >> istr;
			//加载文档
			if (istr.compare(0, 8, "LoadFile") == 0)
				cout << "游戏初始化完成。" << endl;

			//移动
			else if (istr.compare(0, 4, "Goto") == 0) {
				//去天策府
				if (istr.compare(4, istr.size() - 4, "天策府") == 0) {
					cout << "所处位置：天策府" << endl;
					SceneNum = 0;
				}
				//去长歌门
				else if (istr.compare(4, istr.size() - 4, "长歌门") == 0) {
					cout << "所处位置：长歌门" << endl;
					SceneNum = 1;
				}
				//去浩气盟
				else if (istr.compare(4, istr.size() - 4, "浩气盟") == 0) {
					cout << "所处位置：浩气盟" << endl;
					SceneNum = 2;
				}
				//去南屏山
				else if (istr.compare(4, istr.size() - 4, "南屏山") == 0) {
					cout << "所处位置：南屏山" << endl;
					SceneNum = 3;
				}
				//去扬州城
				else if (istr.compare(4, istr.size() - 4, "扬州城") == 0) {
					cout << "所处位置：扬州城" << endl;
					SceneNum = 4;
				}
				//输入错误
				else
					cout << "该场景暂未开放，敬请期待！" << endl;
			}

			//选择任务【非隐藏任务
			else if (istr.compare(0, 7, "GetTask") == 0) {
				int i = 0;
				if (NPCTotal[NPCNum].NPCName == "汤大帅"&&istr.compare(7, istr.size() - 7, "隐藏任务") == 0)
					cout << "你以为隐藏任务那么容易触发???" << endl;
				else {
					for (i = 0; i < TaskTotal.size(); i++) {
						if (istr.compare(7, istr.size() - 7, TaskTotal[i].TaskName) == 0) {
							TaskNum = i;
							if (TaskTotal[TaskNum].Complete == 1)
								cout << "该任务已经完成！" << endl;
							else {
								cout << NPCTotal[NPCNum].NPCName << ":" << TaskTotal[TaskNum].word << endl;
								cout << "领取任务【" << TaskTotal[TaskNum].TaskName << "】成功！" << endl;
								break;
							}
						}
					}
					if (i == NPCTotal[NPCNum].Tasks.size())
						cout << "该任务暂未开放" << endl;
				}
			}

			//选择一个NPC//只能选择当前场景
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
					cout << "该NPC暂未开放" << endl;
				else if (p == 0)
					cout << "该NPC不在本场景" << endl;
			}

			//杀怪
			else if (istr.compare(0, 6, "Attack") == 0) {
				bool q = 0, p = 0;
				for (int i = 0; i < MstTotal.size(); i++) {
					if (istr.compare(6, istr.size() - 1, MstTotal[i].MonsterName) == 0) {
						for (int j = 0; j < MapTotal[SceneNum].Monster.size(); j++) {
							if (i == MapTotal[SceneNum].Monster[j]) {
								MstNum = i;
								p = 1;
								cout << "击杀【" << MstTotal[i].MonsterName << "】成功！" << endl;
								cout << "经验增加:" << MstTotal[i].ExperienceAdd << endl;
								RolePre.Experience += MstTotal[i].ExperienceAdd;
								//有点问题 比如要杀三只矮脚猪的时候
								if (Map.WhetherTask(TaskNum, MstNum))
									MstTotal[i].Beat = 1;
								
								if (TaskFin(TaskNum, MstTotal, TaskTotal)) {
									RolePre.TaskCpl.push_back(TaskNum);
									TaskTotal[TaskNum].Complete = 1;
									cout << endl;
									cout << "任务:" << TaskTotal[TaskNum].TaskName << "已完成" << endl;
									cout << "经验增加:" << TaskTotal[TaskNum].ExperienceAdd << endl;
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
					cout << "该怪物还在开发" << endl;
				else if (p == 0)
					cout << "该怪物不在当前场景" << endl;
			}

			//显示参数
			else if (istr.compare(0, 4, "Show") == 0) {

				//角色信息
				if (istr.compare(4, 6, "IdInfo") == 0) {
					IdentityShow(RolePre, TaskTotal);
				}

				//商店
				else if (istr.compare(4, 4, "Shop") == 0) {
					ShopShow(Shop);
				}

				//任务信息
				else if (istr.compare(4, 4, "Task") == 0) {
					Map.TaskShow(NPCNum, TaskNum, TaskTotal);
				}

				//场景信息
				else if (istr.compare(4, 5, "Scene") == 0) {
					Map.SceneInfoShow(SceneNum);
				}

				//背包信息
				else if (istr.compare(4, 3, "Bag") == 0) {
					BagShow(RolePre);
				}

				//地图信息
				else if (istr.compare(4, 3, "Map") == 0) {
					Map.MapShow();
				}

				//指令输入错误
				else
					cout << "错误的指令" << endl;
			}

			//退出游戏
			else if (istr.compare("Quit") == 0) {
				if (!save) {
					gamer.RoleModi(RolePre, RoleNum);
					GamerTotal[GamerNum] = gamer;
					FileTotal.FileOutGamer(GamerTotal);
				}
				exit(0);
			}

			//存档//有问题
			else if (istr.compare("Save") == 0) {
				gamer.RoleModi(RolePre, RoleNum);
				GamerTotal[GamerNum] = gamer;
				FileTotal.FileOutGamer(GamerTotal);
				save = 1;
				cout << "用户信息保存成功！" << endl;
			}

			//买东西
			else if (istr.compare("Buy") == 0) {
				ShopShow(Shop);
				BuyStuff(Shop, RolePre);
			}

			//卖东西
			else if (istr.compare("Sell") == 0) {
				BagShow(RolePre);
				SellStuff(RolePre);
			}

			//吃东西
			else if (istr.compare("Eat") == 0) {
				BagShow(RolePre);
				EatStuff(RolePre);
			}

			//隐藏任务触发
			else if (NPCTotal[NPCNum].NPCName.compare("汤大帅") && istr.compare("王雅薪是小猪崽") == 0) {
				TaskNum = 6;
				cout << NPCTotal[NPCNum].NPCName << ':' << TaskTotal[TaskNum].word << endl;
				string str;
				cin >> str;
				if (str.compare("汤思怡超帅的") == 0)
				{
					TaskTotal[TaskNum].Complete = 1;
					RolePre.TaskCpl.push_back(TaskNum);
					RolePre.Experience += TaskTotal[TaskNum].ExperienceAdd;
					cout << "贼机智啊 任务完成！" << endl;
					LevelUp(RolePre);
				}
				else
					cout << "你是猪嘛！这都输不对！" << endl;
			}

			//指令输入错误
			else
				cout << "错误的指令" << endl;
		}
		cout << endl;
	}

}