#include "LoRaInterpreter.hpp"

bool LoRaInterpreter::checkSintax(std::string message){
    if(message.size() < 3){
        return false;
    }
    return true;
}