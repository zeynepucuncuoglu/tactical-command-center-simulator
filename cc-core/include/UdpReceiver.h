#pragma once
#include <atomic>
#include <thread>
#include "TargetManager.h"

class UdpReceiver{
    public:
        UdpReceiver(int port, TargetManager& targetManager);
        ~UdpReceiver();
        void start();
        void stop(); 
    private:
        void receiveLoop();
        Target parseTargetMessage(const std::string& message);

    private:
        int m_port;
        int m_sockfd;
        TargetManager& m_targetManager;
        
        std::atomic<bool> m_running;
        std::thread m_thread;

};