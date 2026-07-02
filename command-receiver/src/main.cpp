#include <arpa/inet.h>
#include <csignal>
#include <cstring>
#include <iostream>
#include <unistd.h>

volatile sig_atomic_t g_running = 1;

void handle_signal() {
    g_running = 0;
}

int main(){

}