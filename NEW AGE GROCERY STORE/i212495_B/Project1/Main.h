#pragma once
#include<iostream>
#include<string>
#include"User.h"
#include"Admin.h"
#include"Manager.h"
#include"Customer.h"
#include"Catalogue.h"
#include"Feedback.h"
#include"Cart.h"
#include"Menu.h"
using namespace std;
class Main {
private:
	User* users[3];

public:


	Main() {
		for (int i = 0; i < 3; i++) {
			this->users[i] = new User[i];
		}
	}

	void Display() {
		Admin a;
		string name, n;
		Manager m;
		Customer c24(n);
		Feedback f24;
		Cart ctr;
	

		int REPEAT;
		int ENTER;

		do {
			cout << "Welcome to the Store!" << endl;
			cout << "Select options from the following menu: " << endl;
			cout << "1. Login as Admin" << endl;
			cout << "2. Register as Manager" << endl;
			cout << "3. Login as Manager" << endl;
			cout << "4. Register as Customer" << endl;
			cout << "5. Login as Customer" << endl;
			cout << "Close window to end process.\n";
			cin >> ENTER;
			system("CLS");
			switch (ENTER)
			{
			case 1:
				int y;
				a.Admin_Create();
				cout << "Enter admin credentials" << endl;
				cout << endl;
				a.Admin_Login();
				cout << "enter 1 to go to manager control.\n";
				cout << "enter 2 to go to Catalogue menu\n";
				cout << "enter 3 to go to customer control menu\n";
				cout << "Press 4 to Logout\n";
				cout << "5. Logout" << endl;
				cin >> y;
				if (y == 1) {
					a.control_Manager();
				}
				else if (y == 2) {
					a.control_Catalogue();
				}
				else if (y == 3) {
					a.control_Customer();
				}
				else if (y == 5) {
					a.Logout();
				}
				break;
			case 2:
				cout << "Manager Registeration" << endl;
				cout << endl;
				m.Register();
				break;
			case 3:
				int z;
				cout << "Welcome to login as a Manager" << endl;
				cout << endl;
				cout << "Please enter Manager credentials to login" << endl;
				m.MANAGER_LOGIN();
			/*	cout << "enter 1 for entering items in Inventory: \n";
				cout << "enter 2 for modifying/editing items\n";
				cout << "enter 3 for deleting items\n";*/
				cout << "enter 1 for controlling inventory\n";
				cout << "enter 2 for logging out\n";
				cin >> z;
				if (z == 1) {
					m.control_inventory();

				}
				else if (z == 2) {
					m.Logout_manager();
				}
				
				
				
				cout << endl;
				break;


			case 4:
				cout << "Please enter customer details to register" << endl;
				cout << endl;
				c24.Register();
				break;
			case 5:
				int num;
				cout << "Welcome to Login as a customer" << endl;
				cout << endl;
				cout << "Please enter Customer credentials foer login" << endl;
				cout << endl;
				c24.Login();

				cout << "Select from the following menu" << endl;
				cout << "press 1 to buy items: \n";
				cout << "press 2 for feedback\n";
				cout << "press 3 for viewing cart\n";
				cout << "enter 4 for payemnt method: \n";
				cout << "press 5 for logging out" << endl;
				cin >> num;
				if (num == 1) {
					c24.buy_items();
				}
				else if (num == 2) {
					f24.give_feedback();
				}
				else if (num == 3) {
					ctr.showcart();
				}
				else if (num == 4) {
					c24.Payment();
				}
				else if (num == 5) {
					c24.Logout_customer();
				}


				break;
			default:
				cout << "Wrong menu! Select Again." << endl;
				Display();
				break;
			}

			cout << "If you want to perform any other action please press 1, press any key to exit" << endl;
			cin >> REPEAT;
			system("CLS");
		} while (REPEAT == 1);



	}
};