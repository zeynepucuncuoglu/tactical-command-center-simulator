#pragma once
#include <atomic>
#include <thread>
#include "TargetManager.h"
#include <QObject>
#include <QString>

class UdpReceiver: public QObject
{
    
        Q_OBJECT

    public:
        UdpReceiver(int port, TargetManager& targetManager, QObject* parent = nullptr);
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
    signals:
        void targetReceived(const QString& id, double x, double y, 
                            double speed, const QString& type);

};