#include <string>
#include <SFML/Network.hpp>
#include <iostream>

using namespace std;
using namespace sf;

const sf::IpAddress IP = IpAddress::getLocalAddress();
const int SERVER_PORT = 55000;
const int CLIENT_PORT = 55001;


int main() {

    setlocale(LC_ALL, "RU");

    TcpSocket socket;
    IpAddress serverIp = IP;
    string action_msg = "��������: 1 - ��������� ���������, 2 - ��������� ���: ";
    char choise;
    size_t size;

    Packet out_pack;
    Packet in_pack;
    string check, message;

    std::cout << IP << std::endl;

    if (socket.connect(IP, SERVER_PORT) == TcpSocket::Done)
    {
        cout << "Connection - OK" << endl;
    }
    else
    {
        cout << "Connection - ERROR" << endl;
    }

    cout << action_msg << endl;
    cin >> choise;
    if (choise == '1')
    {
        cout << "������� ���������: " << endl;
        cin >> message;

        do {
            out_pack.clear();
            out_pack << message;

            socket.send(out_pack);
            out_pack.clear();

            socket.receive(in_pack);

            in_pack >> check;
            in_pack.clear();
        } while (check != "Done");

        socket.disconnect();
    }
    else if (choise == '2')
    {   
        socket.disconnect();
        exit(0);
    }


}

