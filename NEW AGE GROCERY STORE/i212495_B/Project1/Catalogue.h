#pragma once
#include<iostream>
#include<string>
#include"User.h"
#include"Admin.h"
#include"Manager.h"
#include"Customer.h"
#include"Menu.h"
using namespace std;


class Catalogue {


public:

	char product_id[10], product_name[20], product_type[20], product_company[20];
	int product_quantity;
	float product_price;

	Catalogue() {

	}




	Catalogue(string id, string _name, string type, string company) {

		strcpy_s(product_id, id.c_str());
		strcpy_s(product_name, _name.c_str());
		strcpy_s(product_type, type.c_str());
		strcpy_s(product_company, company.c_str());
	}

	void set_quantity(int quantity) {
		product_quantity = quantity;
	}

	void set_price(float price) {
		product_price = price;
	}
	int get_quantity() {
		return product_quantity;
	}
	float get_price() {
		return product_price;
	}


	void set_items() {
		Catalogue c;
		string s;
		int q;
		int p;

		cout << "Enter product id:";
		cin >> s;
		strcpy_s(c.product_id, 10, s.c_str());

		cout << "Enter product name:";
		cin >> s;
		strcpy_s(c.product_name, 20, s.c_str());

		cout << "Enter product type:";
		cin >> s;
		strcpy_s(c.product_type, 20, s.c_str());

		cout << "Enter product company:";
		cin >> s;
		strcpy_s(c.product_company, 20, s.c_str());

		cout << "Enter product quantity(0): ";
		cin >> q;
		product_quantity = q;

		cout << "enter product price: ";
		cin >> p;
		product_price = p;

		write_catalogue("Catalogue.dat", c);

	}


	void write_catalogue(string file_name, Catalogue c5)
	{

		ofstream fout(file_name, ios::binary | ios::app);
		fout.write((char*)&c5, sizeof(c5));
		fout.close();

	}



	void read_catalogue() {

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
	}

	void display_catalogue() {

		Catalogue obj2;

		cout << "product id :";
		cout << obj2.product_id;
		cout << "\n";
		cout << "product name: ";
		cout << obj2.product_name;
		cout << "\n";
		cout << "product type: ";
		cout << obj2.product_type << endl;
		cout << "product company: ";
		cout << obj2.product_company;
		cout << "product price ";
		cout << obj2.product_price;
		cout << "product quantity: ";
		cout << obj2.product_quantity;
		cout << endl;



	}
//	void control_Catalogue(){
//	int input;
//	Catalogue cc;
//
//	cout << "Welcome to the Catalogue: \n";
//	cout << "Enter 1 to add items to Catalogue.\n";
//	cout << "Enter 2 to Display items in the Catalogue.\n";
//	cout << "Enter 3 to modify items in the Catalogue.\n";
//
//	cin >> input;
//	if (input == 1) {
//		cc.set_items();
//	}
//	else if (input == 2) {
//		cc.display_catalogue();
//	}
//
//}

};
