#include"Map.h"

//显示场景信息
void MapClass::SceneInfoShow(int CityNum)
{
	cout << "当前场景：" << Cities[CityNum].CityName << endl;

	cout << "当前场景NPC：";
	for (int i = 0; i < Cities[CityNum].NPC.size(); i++)
		cout << NPCs[Cities[CityNum].NPC[i]].NPCName << ' ';
	cout << endl;

	cout << "当前场景怪物：";
	for (int i = 0; i < Cities[CityNum].Monster.size(); i++)
		cout << Msts[Cities[CityNum].Monster[i]].MonsterName << ' ';
	cout << endl;
}

//显示当前NPC持有任务
void MapClass::NPCInfoShow(int NPCNum)
{
	if (NPCNum == -1)
		cout << "未选择NPC" << endl;
	else {
		cout << "NPC名字：" << NPCs[NPCNum].NPCName << endl;
		cout << "NPC介绍：" << NPCs[NPCNum].Descript << endl;
		cout << "当前NPC持有任务：" << endl;
		for (int i = 0; i < NPCs[NPCNum].Tasks.size(); i++)
			cout << Tasks[NPCs[NPCNum].Tasks[i]].TaskName<< ' ';
		cout << endl;
	}
}

//显示城市
void MapClass::MapShow()
{
	for (int i = 0; i < Cities.size(); i++)
		cout << Cities[i].CityName << ' ';
	cout << endl;
}

//显示怪物信息
void MapClass::MstShow(int MstNum)
{
	if (MstNum = -1)
		cout << "未选择战斗对象" << endl;
	else {
		cout << "怪物名字：" << Msts[MstNum].MonsterName << endl;
		cout << "介绍：" << Msts[MstNum].Descript << endl;
		cout << "HP：" << Msts[MstNum].HP << endl;
		cout << "Atk：" << Msts[MstNum].Atk << endl;
		cout << "Def：" << Msts[MstNum].Def << endl;
		cout << "经验加成：" << Msts[MstNum].ExperienceAdd << endl;
	}
	cout << endl;
}

//显示任务信息
void MapClass::TaskShow(int NPCNum, int TaskNum, vector<Task>task)
{
	if (TaskNum < 0)
		cout << "请选择任务" << endl;
	else {
		cout << "任务名称：" << task[TaskNum].TaskName << endl;
		cout << "任务描述：" << NPCs[NPCNum].NPCName << ':' << task[TaskNum].word << endl;
		cout << "经验加成：" << task[TaskNum].ExperienceAdd << endl;
		cout << "是否完成:";
		if (task[TaskNum].Complete)
			cout << "已完成" << endl;
		else
			cout << "未完成" << endl;
	}
	cout << endl;
}

//判断是不是为了任务而杀怪
bool MapClass::WhetherTask(int TaskNum, int MstNum)
{
	if (TaskNum >= 0 && TaskNum < Tasks.size()) {
		for (int i = 0; i < Tasks[TaskNum].MstToKill.size(); i++)
			if (MstNum == Tasks[TaskNum].MstToKill[i])
				return 1;
		return 0;
	}
	return 0;
}