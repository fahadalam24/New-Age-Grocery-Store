#pragma once
#include<iostream>
#include<string>
using namespace std;
class User {
protected:


	char username[100], set_password[10];
public:
	User() {
		username[99] = '\0';
		set_password[9] = '\0';
	}
	User(string name, string pass) {

		strcpy_s(username, name.c_str());
		strcpy_s(set_password, pass.c_str());
	}
	virtual void Display() {

	}
};