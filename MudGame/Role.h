#ifndef ROLE_H
#define ROLE_H

#include"DataStruct.h"

void IdentityShow(Role OneRole,vector<Task>tasks);	//显示当前角色信息
void BuyStuff(vector<Stuff>Shop, Role &RoleNow);	//去商店买东西
void EatStuff(Role &OneRole);						//吃药物、食品
void SellStuff(Role &OneRole);						//卖药物、食品
void LevelUp(Role &OneRole);						//升级
void ShopShow(vector<Stuff>Shop);					//显示商店
void BagShow(Role OneRole);							//显示背包信息
bool TaskFin(int TaskNum, vector<Monster>mst,vector<Task>tsk);	//判断该打怪任务是不是做完了
bool GameOver(vector<Task>task);					//判断是否所有任务都已做完
#endif // !ROLE_H
