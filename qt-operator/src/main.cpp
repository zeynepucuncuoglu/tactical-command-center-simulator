#include "TargetManager.h"
#include "UdpReceiver.h"

#include <chrono>
#include <iostream>
#include <thread>

int main()
{
    TargetManager targetManager;

    UdpReceiver receiver(9000, targetManager);

    receiver.start();

    std::cout << "Receiver is running for 10 seconds...\n";

    std::this_thread::sleep_for(std::chrono::seconds(10));

    receiver.stop();

    std::cout << "Program finished\n";

    return 0;
}