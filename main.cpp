#include <iostream>
#include "./serial/SerialCom.hpp"
#include "./interpreters/LoRa/LoRaInterpreter.hpp"

#define TTY_NAME "/dev/ttyS2"
#define TTY_BAUD_RATE 115200

int main()
{
    SerialCom serialCom;
    serialCom.init(TTY_NAME, TTY_BAUD_RATE);
    serialCom.send("Teste Jean");

    if(LoRaInterpreter::checkSintax("Teste Jean"))
    {
        std::cout << "Sintax is correct" << std::endl;
    }
    else
    {
        std::cout << "Sintax is incorrect" << std::endl;
    }

    while (true)
    {
        while (serialCom.available())
        {
            std::string receivedData = serialCom.readString();
            std::cout << receivedData << std::endl;
            serialCom.send(receivedData.c_str());
        }
    }

    return 0;
}
