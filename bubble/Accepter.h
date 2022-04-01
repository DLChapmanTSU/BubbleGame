#pragma once
#include <memory>
#include <SFML/Network.hpp>

#include "List.h"
#include "Queue.h"

//class List;
//class Queue;

class Accepter{
private:
    List<std::shared_ptr<sf::TcpSocket>>& a_socket;
    Queue<std::string>& a_queue;
public:
    Accepter(List<std::shared_ptr<sf::TcpSocket>>& s, Queue<std::string>& q);
    void operator()();
    //void AcceptLoop();
};