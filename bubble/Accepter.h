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
public:
    Accepter(List<std::shared_ptr<sf::TcpSocket>>& s, Queue<ClientData>& q);
    void operator()();
    //void AcceptLoop();
};