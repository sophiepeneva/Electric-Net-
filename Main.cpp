# Electric-Net-

#include<iostream>
#include "ElectricNet.h"
#include "ElectricDevice.h"

using namespace std;

int main() {

	ElectricDevice eD1("lamp",3);
	ElectricDevice eD2("fridge", 6);
	ElectricDevice eD3("charger", 1);
	ElectricDevice eD4("TV", 4);
	
	ElectricDevice* net = new ElectricDevice[2];
	net[0] = eD1;
	net[1] = eD2;

	ElectricNet myHouse(net, 46, 2);
	myHouse += eD3;
	myHouse + eD4;
	myHouse.print();
	myHouse -= eD3;
	myHouse.print();
	cout << !myHouse << endl;
	--myHouse;
	myHouse["TV"];
	system("pause");
}
