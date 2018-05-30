# Electric-Net-

#pragma once
#include "ElectricDevice.h"
class ElectricNet
{
public:
	ElectricNet();
	ElectricNet(ElectricDevice* net, int maxConsumedPower, int connectedDevices);
	~ElectricNet();
	ElectricNet(const ElectricNet& eN);
	ElectricNet& operator=(const ElectricNet& eN);

	ElectricNet& operator+(const ElectricDevice& eD);
	ElectricNet& operator+=(const ElectricDevice& eD);
	ElectricNet& operator-(const ElectricDevice& eD);
	ElectricNet& operator-=(const ElectricDevice& eD);
	bool operator!() { return m_connectedDevices == 0; }
	void operator++() { m_maxConsumedPower *= 2; }
	ElectricNet& operator--();
	void operator[](const char* name);

	void print() const;

private:
	ElectricDevice * m_net;
	int m_maxConsumedPower;
	int m_connectedDevices;
};

