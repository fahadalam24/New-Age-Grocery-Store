#pragma once
#include<iostream>
#include<string>
#include<fstream>
#include<cstring>
#include"User.h"
#include"Inventory.h"
//#include"Customer.h"
using namespace std;
class Manager : public User
{	
public:
	char CNIC[15], SET_NUM[20], SET_ADDRESS[20], SET_MAIL[20], SET_GENDER[1];
	bool CNIC_check = false, password_check = false;
	


	Manager() {

	}


	Manager(string CNIc, string Phone, string ADDRESS, string Email, string GENDER) {



		strcpy_s(CNIC, CNIc.c_str());
		strcpy_s(SET_NUM, Phone.c_str());
		strcpy_s(SET_ADDRESS, ADDRESS.c_str());
		strcpy_s(SET_GENDER, GENDER.c_str());
		strcpy_s(SET_MAIL, Email.c_str());

	}



	void Register() {
		Manager c;


		string s;

		cout << "Enter username:";
		cin >> s;
		strcpy_s(c.username, 30, s.c_str());

		cout << "Enter CNIC:";
		cin >> s;
		strcpy_s(c.CNIC, 30, s.c_str());

		cout << "Enter password:";
		cin >> s;
		strcpy_s(c.set_password, 20, s.c_str());

		cout << "Enter email:";
		cin >> s;
		strcpy_s(c.SET_MAIL, 20, s.c_str());


		write_manager("Manager.dat", c);

	}


	void MANAGER_LOGIN()

	{
		int z = 0;
		bool flag = false;
		string USER, PASS;
		while (z == 0)
		{
			cout << "Enter the Username: ";
			cin >> USER;

			cout << "enter the password: ";
			cin >> PASS;
			
			cout << endl;

			Manager obj1;

			ifstream fin("Manager.dat", ios::binary);

			while (fin.read((char*)&obj1, sizeof(obj1))) {
				
				cout << "Name :";
				cout << obj1.username;
				cout<<"\n";
				cout << "Password: ";
				cout << obj1.set_password;
				cout << "\n";
				if (USER == obj1.username && PASS == obj1.set_password)
				{
					cout << "Success, You have been logged in as manager," << obj1.username;
					cout << "\n";
					flag = true;
					z = 1;
					break;
				}
			}


			if (flag == false)
			{
				cout << "Incorrect credentials, please enter again";
				cout << "\n";
				z = 0;
			}
			fin.close();
		}


		system("cls");
		cout << "Success, You have been logged in as manager,";
		cout << "\n";
	
	}

	void write_manager(string file_name, Manager obj22)
	{

		ofstream fout(file_name, ios::binary | ios::app);
		fout.write((char*)&obj22, sizeof(obj22));
		fout.close();

	}

	void read(string file_name, string U, string P)
	{
		Manager obj1;
		int flag = 0;
		ifstream fin(file_name, ios::binary);
		while (fin.read((char*)&obj1, sizeof(obj1)))
		{
			string a(obj1.username);
			string b(obj1.username);
			if (a == U) {
				if (P == b) {

					cout << "Success, You have been logged in as manager," << endl;
					flag+=1;
					cout << endl;
					break;
				}
			}

		}

		fin.close();
		if (flag == 0) {
			cout << "No account. Go to main screen and login again. \n";
		}
	}
	void control_inventory() {
		int input;
		Inventory in;

		cout << "Welcome to the Inventory: \n";
		cout << "Enter 1 to add items to Inventory.\n";
		cout << "Enter 2 to Display items in the Inventory.\n";
		cout << "Enter 3 to modify items in the Inventory.\n";

		cin >> input;
		if (input == 1) {
			in.set_items();
		}
		else if (input == 2) {
			in.display_catalogue();
		}
		

	}


	void Display_Manager() {
		Manager m4;
		cout << "Manager Name: " << m4.username << endl;
		cout << "Manager CNIC: " << m4.CNIC << endl;
	}

	void Logout_manager() {
		system("cls");
		cout << "you have been logged out succesfully \n";

	}

	void deleteInventory_Record()
	{
		Inventory i24;
		ifstream fin;
		fin.open("Inventory.dat", ios::in | ios::binary);
		ofstream fout1("Bin.dat");
		ofstream fout2("Binn.dat", ios::app);
		int  flag = 0;
		char cnic[20];
		cout << "Enter manager CNIC you want to delete: ";

		cin >> cnic;

		while (fin.read((char*)&i24, sizeof(i24)))
		{
			if (cnic == i24.product_id)
			{
				cout << "These items have been deleted:\n";
				i24.display_inventory();
				flag++;
				fout2.write((char*)&i24, sizeof(i24));
			}
			else
			{
				fout1.write((char*)&i24, sizeof(i24));
			}
		}
		fin.close();
		fout1.close();
		fout2.close();
		if (flag == 0)

			cout << "Inventory items deleted.\n";
		remove("Inventory.dat");
		rename("Bin.dat", "Inventory.dat");
	}





};