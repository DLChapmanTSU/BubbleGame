#pragma once
#include <memory>
#include <SFML/Network.hpp>

#include "List.h"
#include "Queue.h"

struct ClientData;
//class List;
//class Queue;

class Accepter{
private:
    List<std::shared_ptr<sf::TcpSocket>>& a_socket;
    Queue<ClientData>& a_queue;
    unsigned short a_port;
public:
    Accepter(List<std::shared_ptr<sf::TcpSocket>>& s, Queue<ClientData>& q, unsigned short& p);
    void operator()();
    //void AcceptLoop();
};