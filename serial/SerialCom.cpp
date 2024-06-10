#include "SerialCom.hpp"

#include <iostream>
#include <wiringPi.h>
#include <wiringSerial.h>
#include <string>

void SerialCom::init(const char *tty_name, int baud_rate)
{
	std::cout << "Initializing Serial Communication." << std::endl;

	int oppening_serial = serialOpen(tty_name, baud_rate);
	int count;

	if (oppening_serial < 0)
	{
		std::cout << "Unable to open serial device: " << std::endl;
		return;
	}

	if (wiringPiSetup() == -1)
	{
		std::cout << "Unable to start wiringPi: " << std::endl;
		return;
	}

	std::cout << "Serial communication successfully initialized" << std::endl;
	this->oppening_serial = oppening_serial;
}

void SerialCom::send(const char *data)
{
	serialPrintf(this->oppening_serial, data); //
	// // Colocar isso dentro de algum método depois
	// struct timespec sleeper, dummy;
	// sleeper.tv_sec = (time_t)(3 / 1000);
	// sleeper.tv_nsec = (long)(3 % 1000) * 1000000;
	// nanosleep(&sleeper, &dummy);
}

int SerialCom::readByte()
{
	return serialGetchar(this->oppening_serial);
}

std::string SerialCom::readString()
{
	std::string data = "";
	int c;
	do
	{
		c = this->readByte();
		data += (char)c;
	} while (this->available());
	this->flush();
	return data;
}

int SerialCom::available()
{
	return serialDataAvail(this->oppening_serial);
}

void SerialCom::flush()
{
	serialFlush(this->oppening_serial);
}
