#ifndef GAMER_H
#define GAMER_H

#include"DataStruct.h"
#include"Role.h"
#include<iomanip>
#include <stdio.h>
#include <conio.h>

//用户类
class GamerClass
{
private:
	string Account;	//登录账号
	string Password;	//登录密码
	vector<Role>Roles;	//一个账号拥有的多个角色
public:
	GamerClass(string acc, string psw, vector<Role>roleTemp) {
		Account = acc;
		Password = psw;
		Roles = roleTemp;
	}
	GamerClass(string acc, string psw,Role role) {
		Account = acc;
		Password = psw;
		Roles.push_back(role);
	}
	GamerClass(){}

	void RoleCreate(vector<School>sch);	//创建一个新的角色
	void RoleDelete(string NickName);	//删除一个角色
	bool Code();						//将输入的密码显示为*
	bool NameRep(string name);			//判断该昵称是否存在 1存在 0不存在
	void RoleShow();					//显示当前账号拥有的角色
	bool ReturnRole(Role &rolePre, string NickName, int &n);	//返回当前角色
	string AccReturn() {		//返回账号
		return Account;	}
	string PswReturn() {
		return Password;		//返回密码
	}
	//存档时导出角色信息
	void RolesReturn(vector<Role>&roles) {
		roles = Roles;
	}
	void RoleModi(Role role,int n) {
		Roles[n] = role;
	}
};

void AccCreate(vector<GamerClass>&gamers, vector <School>sch);	//注册

bool Correct(string psw, string psw1);	//两次密码是否一致

string IntToStr(vector<int>n);

#endif // !GAMER_H