#include "Reciever.h"
//#include "Queue.h"
#include "List.h"
#include "ClientData.h"

#include <SFML/Graphics.hpp>

#include <iostream>
#include <cstring>

Reciever::Reciever(std::shared_ptr<sf::TcpSocket>& s, Queue<ClientData>& q) : r_socket(s), r_queue(q){
    //r_socket = s;
    //r_queue = q;
}

void Reciever::ReceiverLoop(){
    char buffer[256];
    sf::Packet packet;
    std::string name;
    int points;
    u_int8_t input;
    std::string message;

    while (true){
        std::memset(buffer, 0, 256);
        size_t recieved;

        if (r_socket->receive(packet) != sf::Socket::Done){
            std::cout << "FATAL RECIEVER ERROR" << std::endl;
            return;
        }
        else{
            std::cout << "Reciever Loop Recieved " << buffer << std::endl;
        }

        if (packet >> name >> points >> input >> message){
            std::cout << "Reciever Loop Recieved:\n" << name << "\n" << points << "\n" << input << "\n" << message << std::endl;
        }

        ClientData d;
        d.c_name = name;
        d.c_points = points;
        d.c_input = input;
        d.c_message = message;

        //std::pair<ClientData, bool> p;
        //p.first = d;
        //p.second = isP1;

        r_queue.Push(d);
    }
}