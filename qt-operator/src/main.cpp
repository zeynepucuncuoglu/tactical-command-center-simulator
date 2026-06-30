#include "TargetManager.h"
#include "UdpReceiver.h"
#include "MainWindow.h"

#include <QApplication>

#include <chrono>
#include <iostream>
#include <thread>


int main(int argc, char* argv[])
{
    QApplication app(argc, argv);

    MainWindow window;
    window.setWindowTitle("Qt Operator");
    window.resize(800, 600);
    window.show();
    
    TargetManager targetManager;
    UdpReceiver* receiver = new UdpReceiver(9000, targetManager, &window);
    QObject::connect(receiver, &UdpReceiver::targetReceived,
                 &window,  &MainWindow::onTargetReceived);

    receiver->start();
    return app.exec();
}