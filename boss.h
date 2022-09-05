#pragma once
#include<iostream>
using namespace std;
#include "woker.h"

class Boss :public Woker
{
public:
	Boss(int id, string name, int did);

	virtual void ShowInfo();

	virtual  string Getdeptname();
};

