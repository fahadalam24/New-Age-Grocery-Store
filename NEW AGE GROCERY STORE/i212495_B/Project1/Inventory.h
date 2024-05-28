#pragma once
#include<iostream>
#include<fstream>
#include<string>
#include<cstring>
#include"Manager.h"
#include"Customer.h"
#include"Catalogue.h"
#include"User.h"
using namespace std;


class Inventory :public Catalogue {

public:


	Inventory() {

}
	void set_items() {

		Inventory i;
		string s;
		int q;
		int p;

		cout << "Enter product id:";
		cin >> s;
		strcpy_s(i.product_id, 10, s.c_str());

		cout << "Enter product name:";
		cin >> s;
		strcpy_s(i.product_name, 20, s.c_str());

		cout << "Enter product type:";
		cin >> s;
		strcpy_s(i.product_type, 20, s.c_str());

		cout << "Enter product company:";
		cin >> s;
		strcpy_s(i.product_company, 20, s.c_str());

		cout << "Enter product quantity(0): ";
		cin >> q;
		product_quantity = q;

		cout << "enter product price: ";
		cin >> p;
		product_price = p;

		write_inventory("Inventory.dat", i);

	}


	void write_inventory(string file_name, Inventory i1)
	{

		ofstream fout(file_name, ios::binary | ios::app);
		fout.write((char*)&i1, sizeof(i1));
		fout.close();

	}


	void read_inventory() {

		Inventory i2;

		ifstream fin("Inventory.dat", ios::binary);

		while (fin.read((char*)&i2, sizeof(i2))) {

			cout << "product id :";
			cout << i2.product_id;
			cout << "\n";
			cout << "product name: ";
			cout << i2.product_name;
			cout << "\n";
			cout << "product type: ";
			cout << i2.product_type << endl;
			cout << "product company: ";
			cout << i2.product_company;
			cout << "product price ";
			cout << i2.product_price;
			cout << "product quantity: ";
			cout << i2.product_quantity;
			cout << endl;

		}
		fin.close();
	}

	void display_inventory() {

		Catalogue i3;

		cout << "product id :";
		cout << i3.product_id;
		cout << "\n";
		cout << "product name: ";
		cout << i3.product_name;
		cout << "\n";
		cout << "product type: ";
		cout << i3.product_type << endl;
		cout << "product company: ";
		cout << i3.product_company;
		cout << "product price ";
		cout << i3.product_price;
		cout << "product quantity: ";
		cout << i3.product_quantity;
		cout << endl;

	}

	void fun()
	{

		Catalogue c15;

		ifstream fin;
		fin.open("Inventory.dat", ios::in | ios::binary);

		ofstream fbout2("Inventory.dat", ios::app);

		while (fin.read((char*)&c15, sizeof(c15))) {

			fbout2.write((char*)&c15, sizeof(c15));
		}


		fin.close();

		fbout2.close();

	}

	//void control_Inventory() {
	//	int input;
	//	Inventory i3;

	//	cout << "Welcome to the Inventory: \n";
	//	cout << "Enter 1 to add items to Inventory.\n";
	//	cout << "Enter 2 to Display items in the Inventory.\n";
	//	cout << "Enter 3 to modify items in the Inventory.\n";
	//	cin >> input;
	//	if (input == 1) {
	//		i3.set_items();
	//	}
	//	else if (input == 2) {
	//		i3.display_inventory();
	//	}

	//}


};