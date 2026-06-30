#include "TargetManager.h"
#include "UdpReceiver.h"
#include <QApplication>
#include <QMainWindow>
#include <chrono>
#include <iostream>
#include <thread>


int main(int argc, char* argv[])
{
    QApplication app(argc, argv);

    QMainWindow window;
    window.setWindowTitle("Qt Operator");
    window.resize(800, 600);
    window.show();

    return app.exec();
}