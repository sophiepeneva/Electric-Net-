# Electric-Net-

#include "ElectricDevice.h"
#include<iostream>


ElectricDevice::ElectricDevice(const char* name, int consumedPower) : m_consumedPower(consumedPower)
{
	m_name = new char[strlen(name) + 1];
	strcpy_s(m_name, strlen(name) + 1, name);
}


ElectricDevice::~ElectricDevice()
{
	Destroy();
}

ElectricDevice::ElectricDevice(const ElectricDevice& eD)
{
	Copy(eD);
}

ElectricDevice& ElectricDevice::operator=(const ElectricDevice& eD)
{
	if (this != &eD)
	{
		Destroy();
		Copy(eD);
	}
	return *this;
}

void ElectricDevice::Destroy()
{
	delete[] m_name;
}

void ElectricDevice::Copy(const ElectricDevice& eD)
{
	m_consumedPower = eD.m_consumedPower;
	m_name = new char[strlen(eD.m_name) + 1];
	strcpy_s(m_name, strlen(eD.m_name) + 1, eD.m_name);
}


