#include "UdpReceiver.h"

#include <iostream>
#include <sstream>
#include <vector>
#include <cstring>

#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>

UdpReceiver::UdpReceiver(int port, TargetManager& targetManager)
    : m_port(port),
      m_sockfd(-1),
      m_targetManager(targetManager),
      m_running(false)
{
}

UdpReceiver::~UdpReceiver()
{
    stop();
}

void UdpReceiver::start()
{
    if (m_running) {
        return;
    }

    m_sockfd = socket(AF_INET, SOCK_DGRAM, 0);

    if (m_sockfd < 0) {
        std::cerr << "Failed to create UDP socket\n";
        return;
    }

    sockaddr_in serverAddr{};
    serverAddr.sin_family = AF_INET;
    serverAddr.sin_addr.s_addr = INADDR_ANY;
    serverAddr.sin_port = htons(m_port);

    if (bind(
            m_sockfd,
            reinterpret_cast<sockaddr*>(&serverAddr),
            sizeof(serverAddr)
        ) < 0) {
        std::cerr << "Failed to bind UDP socket on port " << m_port << "\n";
        close(m_sockfd);
        m_sockfd = -1;
        return;
    }

    m_running = true;

    m_thread = std::thread(&UdpReceiver::receiveLoop, this);

    std::cout << "UDP Receiver started on port " << m_port << "\n";
}

void UdpReceiver::stop()
{
    if (!m_running) {
        return;
    }

    m_running = false;

    if (m_sockfd >= 0) {
        close(m_sockfd);
        m_sockfd = -1;
    }

    if (m_thread.joinable()) {
        m_thread.join();
    }

    std::cout << "UDP Receiver stopped\n";
}

void UdpReceiver::receiveLoop()
{
    char buffer[1024];

    while (m_running) {
        sockaddr_in senderAddr{};
        socklen_t senderLen = sizeof(senderAddr);

        ssize_t receivedBytes = recvfrom(
            m_sockfd,
            buffer,
            sizeof(buffer) - 1,
            0,
            reinterpret_cast<sockaddr*>(&senderAddr),
            &senderLen
        );

        if (receivedBytes < 0) {
            if (m_running) {
                std::cerr << "Failed to receive UDP packet\n";
            }
            continue;
        }

        buffer[receivedBytes] = '\0';

        std::string message(buffer);

        try {
            Target target = parseTargetMessage(message);

            m_targetManager.addTarget(target);

            std::cout << "Received target: " << message << "\n";
        } catch (const std::exception& e) {
            std::cerr << "Failed to parse target message: "
                      << message
                      << " error: "
                      << e.what()
                      << "\n";
        }
    }
}

Target UdpReceiver::parseTargetMessage(const std::string& message)
{
    std::stringstream ss(message);
    std::string token;
    std::vector<std::string> tokens;

    while (std::getline(ss, token, ',')) {
        tokens.push_back(token);
    }

    if (tokens.size() != 5) {
        throw std::runtime_error("Invalid target message format");
    }

    std::string id = tokens[0];
    double x = std::stod(tokens[1]);
    double y = std::stod(tokens[2]);
    double speed = std::stod(tokens[3]);

    TargetType type;

    if (tokens[4] == "AIRCRAFT") {
        type = TargetType::AIRCRAFT;
    } else if (tokens[4] == "DRONE") {
        type = TargetType::DRONE;
    } else if (tokens[4] == "SHIP") {
        type = TargetType::SHIP;
    } else {
        throw std::runtime_error("Unknown target type");
    }

    return Target(id, x, y, speed, type);
}