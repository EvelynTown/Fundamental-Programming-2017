#ifndef MAP_H
#define MAP_H

#include"DataStruct.h"

//地图类
class MapClass
{
private:
	vector<City>Cities;	//总的地图信息
	vector<NPC>NPCs;
	vector<Monster>Msts;
	vector<Task>Tasks;
public:
	MapClass(vector<City>CityT, vector<NPC>NPCT,vector<Monster>MstT,vector<Task>tasks) {
		Cities = CityT;
		NPCs = NPCT;
		Msts = MstT;
		Tasks = tasks;
	}
	//void BattleShow(int MstNum);			//显示战斗参数
	void SceneInfoShow(int CityNum);		//显示场景参数
	void NPCInfoShow(int NPCNum);			//显示当前NPC持有任务
	void MapShow();							//选择城市
	void MstShow(int MstNum);				//显示怪物信息
	void TaskShow(int NPCNum,int TaskNum, vector<Task>task);	//显示任务信息
	bool WhetherTask(int TaskNum, int MstNum);	//判断是不是为了任务而杀怪
};
#endif // !MAP_H
