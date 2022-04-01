#pragma once
#include <SFML/Network.hpp>

#include <memory>

#include "Queue.h"

class Reciever{
private:
    std::shared_ptr<sf::TcpSocket> r_socket;
    Queue<std::string>& r_queue;
public:
    Reciever(std::shared_ptr<sf::TcpSocket>& s, Queue<std::string>& q);
    void ReceiverLoop();
};