#pragma once
#include<iostream>
using namespace std;
#include "woker.h"

class Manager :public Woker
{
public:
	Manager(int id, string name, int did);

	virtual void ShowInfo();

	virtual  string Getdeptname();
};

