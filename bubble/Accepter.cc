#include "Accepter.h"
#include "Reciever.h"
//#include "Queue.h"
#include "List.h"
#include "ClientData.h"

#include <SFML/Graphics.hpp>
#include <SFML/Network.hpp>

#include <iostream>
#include <thread>


Accepter::Accepter(List<std::shared_ptr<sf::TcpSocket>>& s, Queue<ClientData>& q, unsigned short& p) : a_socket(s), a_queue(q), a_port(p){ }

void Accepter::operator()(){
    std::cout << "Trying To Accept" << std::endl;
    sf::TcpListener listener;
    if (listener.listen(a_port) != sf::Socket::Done){
        std::cout << "FATAL ACCEPTER ERROR" << std::endl;
        return;
    }

    //std::cout << "Should be connected" << std::endl;

    while(true){
        std::cout << "Looping" << std::endl;
        std::shared_ptr<sf::TcpSocket> socket = std::make_shared<sf::TcpSocket>();
        if (listener.accept(*socket) != sf::Socket::Done){
            std::cout << "Could not accept" << std::endl;
            return;
        }
        else{
            std::cout << "Connection accepted" << std::endl;
            if (socket == nullptr){
                std::cout << "Socket is null" << std::endl;
            }
            else{
                std::cout << "Reciever thread generated" << std::endl;
                a_socket.Push(socket);
                std::shared_ptr<Reciever> r = std::make_shared<Reciever>(socket, a_queue);
                std::thread(&Reciever::ReceiverLoop, r).detach();
            }
        }
    }

    listener.close();

    std::cout << "Done" << std::endl;
}