#include <string>

class SerialCom {
    private:
        int oppening_serial;
        void flush();
    public:
        void init(const char* tty_name, int baud_rate);
        void send(const char* data);
        int readByte();
        std::string readString();
        int available();
};