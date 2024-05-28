#pragma once
#include<iostream>
#include<fstream>
#include<string>
#include<cstring>
#include"Manager.h"
#include"Customer.h"
#include"User.h"
using namespace std;

class Feedback {

public:
	char feedback[60];

	Feedback() {

	}

	void give_feedback() {
		Feedback f;
		string str1;
		cout << "please give us your feedback.\n";
		cin >> str1;
		strcpy_s(f.feedback, 60, str1.c_str());
		write_feedback("Feedback.dat", f);

	}


	void write_feedback(string file_name, Feedback f1)
	{

		ofstream fout(file_name, ios::binary | ios::app);
		fout.write((char*)&f1, sizeof(f1));
		fout.close();

	}



	//void for_customer() {


	//	cout << "Please enter your feedback: ";
	//	cin >> feedback;
	//}

};