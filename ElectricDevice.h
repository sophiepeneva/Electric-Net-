# Electric-Net-

#pragma once
#include<iostream>


class ElectricDevice
{
public:
	ElectricDevice(const char* name = "NO NAME",int consumedPower = 0);
	~ElectricDevice();
	ElectricDevice(const ElectricDevice& eD);
	ElectricDevice& operator=(const ElectricDevice& eD);

	int getPower() const { return m_consumedPower; }
	char* getName() const { return m_name; }

	void print() const { std::cout << "Name : " << m_name << ", power : " << m_consumedPower << std::endl; }
private:
	void Destroy();
	void Copy(const ElectricDevice& eD);
	char* m_name;
	int m_consumedPower;
};

