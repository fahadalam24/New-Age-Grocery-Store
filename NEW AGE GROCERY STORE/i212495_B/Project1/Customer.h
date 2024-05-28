#pragma once
#include<iostream>
#include<fstream>
#include<string>
#include<cstring>
#include"Manager.h"
//#include"Customer.h"
#include"Catalogue.h"
#include"User.h"
using namespace std;


class Customer : public User {
public:

	char CNIC[20], set_password[20]{ NULL }, re_enterpassword[20], set_number[20], set_address[20], set_mail[20], set_gender[1],USER[20];
	bool cnic_check = false, correctpassword = false;

	


	Customer() {

	/*	cnic_check = false;
		correctpassword = false;*/

	}
	Customer(string pass, string Name) {
		strcpy_s(username, Name.c_str());
		strcpy_s(set_password, pass.c_str());

	}
	Customer(string user_name, string Password, string cnic, string Set_Password, string Number, string Adress, string Mail, string Gender) : User(user_name, Password) {

		/*strcpy_s(username, user_name.c_str());*/
		strcpy_s(CNIC, cnic.c_str());
		/*strcpy_s(set_password, Set_Password.c_str());*/
		strcpy_s(set_number, Number.c_str());
		strcpy_s(set_address, Adress.c_str());
		strcpy_s(set_gender, Gender.c_str());
		strcpy_s(set_mail, Mail.c_str());
	}
	Customer(string u) {
		strcpy_s(username, u.c_str());
	}



	void Register() {
	
		cout << "Please enter your name: " << endl;
		cin >> username;
		cout << endl;
		while (cnic_check == false) {
			cout << "Please enter your CNIC: " << endl;
			cin >> CNIC;
			cout << endl;
			cnic_check = true;
			if (strlen(CNIC) < 13) {
				cnic_check = false;
				cout << "Your CNIC must be atleast 13 characters " << endl;

			}
			cout << endl;
		}
		cout << "enter your phone number: ";
		cin >> set_number;
	
		cout << "Please enter password" << endl;
		cout << "Password must be 9 characters long and the use of a minimum of one special character, uppercase, lowercase, and the numeric digit is a must." << endl;
		cin >> set_password;
		cout << "Enter address: ";
		cin >> set_address;
		cout << "enter phone number: ";
		cin >> set_number;
		cout << "Gender F/M: ";
		cin >> set_gender;
		cout << "enter your email address: ";
		cin >> set_mail;


		cout << endl;
		cout << "Customer successfully registered" << endl;
		write("Customer.dat", *this);
	}

	void write(string file_name, Customer obj1)
	{

		ofstream fout(file_name, ios::binary | ios::app);
		fout.write((char*)&obj1, sizeof(obj1));
		fout.close();

	}

	void  buy_items() {
		int n;
		do
		{
			Catalogue obj1;

			ifstream fin("Catalogue.dat", ios::binary);

			while (fin.read((char*)&obj1, sizeof(obj1))) {

				cout << "product id :";
				cout << obj1.product_id;
				cout << "\n";
				cout << "product name: ";
				cout << obj1.product_name;
				cout << "\n";
				cout << "product type: ";
				cout << obj1.product_type << endl;
				cout << "product company: ";
				cout << obj1.product_company;
				cout << "product price ";
				cout << obj1.product_price;
				cout << "product quantity: ";
				cout << obj1.product_quantity;
				cout << endl;

			}
			fin.close();



			cout << "enter 1 to continue buying more items.";
			cout << endl;
			cin >> n;

		} while (n==1);


	}






		void read(string file_name, string U, string P)
		{
			Customer obj2;
			int flag=0;
			ifstream fin(file_name, ios::binary);
			while (fin.read((char*)&obj2, sizeof(obj2)))
			{
				string a(obj2.username);
				string b(obj2.set_password);
				if (a == U) {
					if (P == b) {

						cout << "Login Successful: " << endl;
						flag++;
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

		void read(string file_name) {
			Customer obj2;
			ifstream fin(file_name, ios::binary);
			while (fin.read((char*)&obj2, sizeof(obj2)))
			{
				obj2.Display();
			}
			fin.close();
		}

		void Login()
		{
			string user, pass;
			cout << "Enter Username:  " << endl;
			cin >> user;
			cout << endl;
			cout << "Enter Password: " << endl;
			cin >> pass;
			cout << endl;
			read("Customer.dat", user, pass);


		}
		void Payment() {
			int pay;
			char mobile_acc[12],card[15];
			cout << "enter payment method: 1 for jazzcash/easypaisa, 2 for debit/credit, 3 for COD\n ";
			cin >> pay;
			if (pay == 1) {
				cout << "enter mobile account number: ";
				cin >> mobile_acc;
			}
			else if (pay == 2) {
				cout << "enter visa/mastercard account number: ";
				cin >> card;
			}
			else if (pay == 3) {
				cout << "the item(s) will be delivered to the given address within 5 business days. Thank you for shopping with us." << endl;
			}
		}



		void Display() {
			cout << "Username: " << username << endl;
			cout << "password: " << set_password << endl;
		}

		void Logout_customer() {
			system("cls");
			cout << "you have been logged out succesfully \n";

		}



	};