#pragma once
#include <SFML/Network.hpp>

#include <memory>

#include "Queue.h"

struct ClientData;

class Reciever{
private:
    std::shared_ptr<sf::TcpSocket> r_socket;
    Queue<ClientData>& r_queue;
public:
    Reciever(std::shared_ptr<sf::TcpSocket>& s, Queue<ClientData>& q);
    void ReceiverLoop();
};