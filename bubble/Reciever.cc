#include "Reciever.h"
//#include "Queue.h"
#include "List.h"

#include <SFML/Graphics.hpp>

#include <iostream>
#include <cstring>

Reciever::Reciever(std::shared_ptr<sf::TcpSocket>& s, Queue<std::string>& q) : r_socket(s), r_queue(q){
    //r_socket = s;
    //r_queue = q;
}

void Reciever::ReceiverLoop(){
    char buffer[256];
    while (true){
        std::memset(buffer, 0, 256);
        size_t recieved;

        if (r_socket->receive(buffer, 256, recieved) != sf::Socket::Done){
            std::cout << "FATAL RECIEVER ERROR" << std::endl;
            return;
        }
        else{
            std::cout << "Recieved " << buffer << std::endl;
        }

        r_queue.Push(std::string(buffer));
    }
}