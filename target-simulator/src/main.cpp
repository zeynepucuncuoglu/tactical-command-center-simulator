#include <iostream>
#include <string>

#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <thread>
#include <chrono>
#include "Target.h"
#include <csignal>

volatile sig_atomic_t running = 1;

void signalHandler(int signal)
{
    running = 0;
}

std::string targetTypeToString(TargetType type) {
    switch (type) {
        case TargetType::AIRCRAFT:
            return "AIRCRAFT";
        case TargetType::DRONE:
            return "DRONE";
        case TargetType::SHIP:
            return "SHIP";
        default:
            return "UNKNOWN";
    }
}

int main() {

    signal(SIGINT, signalHandler);

    Target target(
        "1",
        120.5,
        300.0,
        850.0,
        TargetType::AIRCRAFT
    );

    int sockfd = socket(AF_INET, SOCK_DGRAM, 0);

    if (sockfd < 0) {
        std::cerr << "Failed to create UDP socket\n";
        return 1;
    }

    sockaddr_in receiverAddr{};
    receiverAddr.sin_family = AF_INET;
    receiverAddr.sin_port = htons(9000);

    if (inet_pton(AF_INET, "127.0.0.1", &receiverAddr.sin_addr) <= 0) {
        std::cerr << "Invalid IP address\n";
        close(sockfd);
        return 1;
    }

    while(running){

        std::string message =
            target.getId() + "," +
            std::to_string(target.getX()) + "," +
            std::to_string(target.getY()) + "," +
            std::to_string(target.getSpeed()) + "," +
            targetTypeToString(target.getType());

        sendto(
            sockfd,
            message.c_str(),
            message.size(),
            0,
            reinterpret_cast<sockaddr*>(&receiverAddr),
            sizeof(receiverAddr)
        );

        std::cout << "Sent message: " << message << "\n";
        std::this_thread::sleep_for(std::chrono::seconds(1));
    }
    close(sockfd);
    return 0;
}