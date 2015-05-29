#include <iostream>
#include <thread>
#include <assert.h>
#include "Fifo.h"

using namespace std;

volatile static bool stop = false;
static Fifo<int> fifo(64);

void writer(){
    std::cout << "writer started... \n";

    int count = 0;
    while (!stop){
        bool ok = fifo.write(count);
        if (ok){
            count++;
        }

    }

    std::cout << "writer ...stopped\n";
}



void reader(){
    std::cout << "reader started... \n";

    int count = 0;
    int val;
    while (!stop){
        bool read = fifo.read(&val);
        if (read){
            assert(val == count);
            count++;
        }
    }

    std::cout << "reader ...stopped\n";
}

int main() {
    cout << "Hello, World!" << endl;

    std::thread readerThread(reader);
    std::thread writerThread(writer);

    std::this_thread::sleep_for(std::chrono::seconds(20));

    stop = true;
    writerThread.join();
    readerThread.join();

    return 0;
}