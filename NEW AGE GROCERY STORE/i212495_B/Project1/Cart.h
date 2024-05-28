#pragma once
#include<iostream>
#include<fstream>
#include<string>
#include<cstring>
#include"Manager.h"
//#include"Customer.h"
#include"Catalogue.h"
#include"Inventory.h"
#include"User.h"
using namespace std;

class Cart {

public:
	Cart() {

	}

	void cart_fill()
	{
		fstream ef;


		char ch;

		int t = 0;


		Inventory i21;

		char str8[35];

		string str3;


		int n24;
		

		do {
			system("cls");
			showcart();
			cout << endl << endl;
			cout << "Choose id numeber you want to buy: ";
			cin >> str3;
			int n1;
			int pos = 0;
			int flag = 0;
			ef.open("Inventory.dat", ios::in | ios::out | ios::binary);
			ofstream fcart("Cart.dat", ios::app);


			while (ef.read((char*)&i21, sizeof(i21)))
			{
				if (str3 == i21.product_id)
				{

					
					ef.seekg(pos - sizeof(i21));
			
					cout<<endl;
					cout << "required= ";
					cin >> n1;
					t+=n1;
			
					i21.product_quantity-= n1;

					fcart.write((char*)&i21, sizeof(i21));
					ef.write((char*)&i21, sizeof(i21));
					flag+=1;







				}
			}
			ef.close();
			fcart.close();
			if (flag == 0)
			{
				cout << "no such item in the file\n";
			}

			cout << "if you want to continuye buying press 1\n";
			cin >> n24;


		} while (ch == n24);

		system("cls");
		cout << "Bill is 120$\n";



	}

	void showcart() {
		Inventory i15;
		i15.display_inventory();
	}


};