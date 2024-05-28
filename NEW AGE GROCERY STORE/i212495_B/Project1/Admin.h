#pragma once
#include<iostream>
#include<ctime>
#include<string>
#include<fstream>
#include<conio.h>
#include"User.h"
#include"Manager.h"
#include"Customer.h"
#include"Catalogue.h"


using namespace std;

class Admin {

	/*char CNIC[15], SET_NUM[20], SET_ADDRESS[20], SET_MAIL[20], SET_GENDER[1];
	bool CNIC_check = false, password_check = false;*/


public:
	char A_USERNAME[20], A_PASSWORD[20], city[20];

	Admin() {

	}


	Admin(string au, string ap)
	{
		strcpy_s(A_USERNAME, au.c_str());
		strcpy_s(A_PASSWORD, au.c_str());
	}





	void Admin_Create() {
		string s;
		Admin obj;

		s = "fahad";
		strcpy_s(obj.A_USERNAME, 20, s.c_str());

		s = "alam";
		strcpy_s(obj.A_PASSWORD, 20, s.c_str());


		write_admin("Admin.dat", obj);
	}



	void write_admin(string file_name, Admin obj33)
	{

		ofstream fout(file_name, ios::binary | ios::app);
		fout.write((char*)&obj33, sizeof(obj33));
		fout.close();

	}

	




	void Admin_Login()

	{
		int x = 0;
		bool flag = false;
		string U, P;
		while (x == 0)
		{
			cout << "Enter the Username: ";
			cin >> U;

			cout << "enter the password: ";
			cin >> P;
			cout << endl;
			cout << "enter the store city: ";
			cin >> city;

			Admin a1;

			ifstream fin("Admin.dat", ios::binary);

			while (fin.read((char*)&a1, sizeof(a1))) {

				cout << "Name :";
				cout << a1.A_USERNAME;
				cout << "\n";
				cout << "Password: ";
				cout << a1.A_PASSWORD;
				cout << "\n";
				if (U == a1.A_USERNAME && P == a1.A_PASSWORD)
				{
					cout << "Success, You have been logged in as Admin," << a1.A_USERNAME;
					cout << "\n";
					flag = true;
					x = 1;
					break;
				}
			}


			if (flag == false)
			{
				cout << "Incorrect credentials, please enter again";
				cout << "\n";

				x = 0;
			}
			fin.close();
		}
		system("cls");
		cout << "Success, You have been logged in as Admin,";
		
		cout << "\n";

	}

	void control_Customer() {
		int input;
		Customer c1;

		Admin a2;
		cout << "this is the Customer control menu.\n";
		cout << "enter 1 to view Customer list\n";
		cout << "enter 2 to delete Customer.\n";

		cin >> input;

		if (input == 1) {
			a2.CustomerList();
			c1.Display();

		}
		else if (input == 2) {
			a2.deleteCustomer_Record();

		}


	}


	void control_Catalogue(){
		int input;
		Catalogue cc;

		cout << "Welcome to the Catalogue: \n";
		cout << "Enter 1 to add items to Catalogue.\n";
		cout << "Enter 2 to Display items in the Catalogue.\n";
		cout << "Enter 3 to modify items in the Catalogue.\n";

		cin >> input;
		if (input == 1) {
			cc.set_items();
		}
		else if (input == 2) {
			cc.display_catalogue();
		}
	
	}









	void control_Manager() {
		int input;
		Customer c1;
		Manager m1;
		Admin a2;
		cout << "this is the manager control menu.\n";
		cout << "press 1 to register manager.\n";
		cout << "enter 2 to see manager list.\n";
		cout << "enter 3 to delete manager.\n";
	//	cout << "enter 4 to view customer list\n";
		cin >> input;
		if (input == 1) {
			m1.Register();
		}
		else if (input == 2) {
			
			a2.ManagerList();
			m1.Display_Manager();
		}
		else if (input == 3) {
			a2.deleteManager_Record();
		}
		else if (input == 4) {
			a2.CustomerList();
			c1.Display();

		}
	}

	void deleteCustomer_Record()
	{

		Customer c5;
		ifstream fin;
		fin.open("Customer.dat", ios::in | ios::binary);
		ofstream fout1("t.dat");
		ofstream fout2("Binn.dat", ios::app);
		int  flag = 0;
		char cnic[20];
		cout << "Enter manager CNIC you want to delete: ";

		cin >> cnic;

		while (fin.read((char*)&c5, sizeof(c5)))
		{
			if (cnic == c5.CNIC)
			{
				cout << "These items have been deleted:\n";
				c5.Display();
				flag++;
				fout2.write((char*)&c5, sizeof(c5));
			}
			else
			{
				fout1.write((char*)&c5, sizeof(c5));
			}
		}
		fin.close();
		fout1.close();
		fout2.close();
		if (flag == 0)

			cout << "Customer deleted.\n";
		remove("Customer.dat");
		rename("t.dat", "Customer.dat");
	}




















	void deleteManager_Record()
	{
		Manager m5;
		ifstream fin;
		fin.open("Manager.dat", ios::in | ios::binary);
		ofstream fout1("temp.dat");
		ofstream fout2("Bin.dat", ios::app);
		int  flag = 0;
		char cnic[20];
		cout << "Enter manager CNIC you want to delete: ";

		cin >> cnic;

		while (fin.read((char*)&m5, sizeof(m5)))
		{
			if (cnic == m5.CNIC)
			{
				cout << "These items have been deleted:\n";
				m5.Display_Manager();
				flag++;
				fout2.write((char*)&m5, sizeof(m5));
			}
			else
			{
				fout1.write((char*)&m5, sizeof(m5));
			}
		}
		fin.close();
		fout1.close();
		fout2.close();
		if (flag == 0)

			cout << "Manager deleted.\n";
		remove("Manager.dat");
		rename("temp.dat", "Manager.dat");
	}


	void CustomerList()
	{
		Customer c1;
		ifstream fin("Customer.dat", ios::binary);
		while (fin.read((char*)&c1, sizeof(c1))) {

			
			cout << "CNIC: " << c1.CNIC << endl;
			cout << "PASSWORD: " << c1.set_password << endl;
			cout << "MAIL: " << c1.set_mail << endl;
			cout << "ADDRESS: " << c1.set_address << endl;
		}
		fin.close();

		_getch();
	}

	void ManagerList()
	{
		Manager m1;
		ifstream fin("Customer.dat", ios::binary);
		while (fin.read((char*)&m1, sizeof(m1))) {


			cout << "CNIC: " << m1.CNIC << endl;
			cout << "MAIL: " << m1.SET_MAIL << endl;

		}
		fin.close();

		_getch();
	}

	void Logout() {
		system("cls");
		cout << "you have been logged out succesfully \n";

	}

	//void edit_manager()
	//{
	//	Manager m7;
	//	fstream fio;
	//	fio.open("Manager.dat", ios::in | ios::out | ios::binary);
	//	int flag = 0, pos;
	//	char str[20];
	//	cout << "Manager CNIC: ";
	//	cin >> str;

	//	while (fio.read((char*)&m7, sizeof(m7)))
	//	{
	//		if (str == m7.CNIC)
	//		{
	//			pos = fio.tellg();	//return the current position of cursor
	//			cout << "Following record found to be modified....\n";
	//			m7.();

	//			cout << "\nEnter new record details\n";
	//			fio.seekg(pos - sizeof(s));//shift the cursor to its parameterized position
	//			s.getData();	//new data to memory
	//			fio.write((char*)&s, sizeof(s));
	//			flag++;
	//		}
	//	}
	//	fio.close();
	//	if (flag == 0)
	//		cout << "No such roll number in file...\n";
	//}










};