# Electric-Net-

#include "ElectricNet.h"
#include<iostream>


ElectricNet::ElectricNet()
{
	m_maxConsumedPower = 50;
	m_connectedDevices = 0;
	m_net = nullptr;
}


ElectricNet::ElectricNet(ElectricDevice* net, int maxConsumedPower, int connectedDevices) : m_maxConsumedPower(maxConsumedPower), m_connectedDevices(connectedDevices)
{
	int sumConsumedPower = 0;
	m_net = new ElectricDevice[m_connectedDevices];
	for (int i = 0;i < m_connectedDevices;i++)
	{
		sumConsumedPower += net[i].getPower();
		if (sumConsumedPower <= maxConsumedPower)
		{
			m_net[i] = net[i];
		}
		else {
			i = m_connectedDevices;
		}
	}
}


ElectricNet::~ElectricNet()
{
	delete[] m_net;
}


ElectricNet::ElectricNet(const ElectricNet& eN) : m_connectedDevices(eN.m_connectedDevices), m_maxConsumedPower(eN.m_maxConsumedPower)
{
	m_net = new ElectricDevice[m_connectedDevices];
	for(int i=0;i<m_connectedDevices;i++)
	{
		m_net[i] = eN.m_net[i];
	}
}

ElectricNet& ElectricNet::operator=(const ElectricNet& eN)
{
	m_connectedDevices = eN.m_connectedDevices;
	m_maxConsumedPower = eN.m_maxConsumedPower;
	m_net = new ElectricDevice[m_connectedDevices];
	for (int i = 0;i<m_connectedDevices;i++)
	{
		m_net[i] = eN.m_net[i];
	}
	return *this;
}


ElectricNet& ElectricNet::operator+(const ElectricDevice& eD)
{
	int sumConsumedPower = 0;
	for (int i = 0;i < m_connectedDevices;i++)
	{
		sumConsumedPower += m_net[i].getPower();
	}
	if (sumConsumedPower + eD.getPower() > m_maxConsumedPower)
	{
		std::cout << "Couldn't connect device because it would overpower the network" << std::endl;
		return *this;
	}
	ElectricDevice* temp = m_net;
	m_net = new ElectricDevice[++m_connectedDevices];
	for (int i = 0;i < m_connectedDevices - 1;i++) {
		m_net[i] = temp[i];
	}
	m_net[m_connectedDevices - 1] = eD;
	return *this;
}

ElectricNet& ElectricNet::operator+=(const ElectricDevice& eD)
{
	return (*this + eD);
}


ElectricNet& ElectricNet::operator-(const ElectricDevice& eD)
{
	int deviceIndex = -1;
	for (int i = 0;i < m_connectedDevices;i++)
	{
		if (strcmp(m_net[i].getName(), eD.getName()) == 0)
		{
			deviceIndex = i;
			i = m_connectedDevices;
		}
	}
	if (deviceIndex == -1) 
	{
		std::cout << "This device wasn't in the network" << std::endl;
		return *this;
	}
	for (int i = deviceIndex;i < m_connectedDevices - 1;i++)
	{
		m_net[i] = m_net[i + 1];
	}
	m_connectedDevices--;
	return *this;
}


ElectricNet& ElectricNet::operator-=(const ElectricDevice& eD)
{
	return (*this - eD);
}


ElectricNet& ElectricNet::operator--()
{
	int sumConsumedPower = 0;
	for(int i=0;i<m_connectedDevices;i++)
	{
		sumConsumedPower += m_net[i].getPower();
	}
	if (m_maxConsumedPower / 2 >= sumConsumedPower)m_maxConsumedPower /= 2;
	else
	{
		std::cout << "Couldn't go through with the action. Risk of overpowering the network." << std::endl;
	}
	return *this;
}

void ElectricNet::operator[](const char* name)
{
	for (int i = 0;i < m_connectedDevices;i++)
	{
		if (strcmp(m_net[i].getName(), name) == 0)
		{
			std::cout << name << " consumes : " << m_net[i].getPower() << " power." << std::endl;
		}
	}
}

void ElectricNet::print() const
{
	for(int i=0;i<m_connectedDevices;i++)
	{
		m_net[i].print();
	}
}

