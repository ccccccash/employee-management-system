#pragma once
#include<iostream>
using namespace std;
#include "woker.h"

class Employee :public Woker
{
public:
	Employee(int id, string name, int did);

	virtual void ShowInfo();

	virtual  string Getdeptname();
};

