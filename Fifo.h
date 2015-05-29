//
// Created by Andrey Syvrachev on 29.05.15.
//

#ifndef FIFOTEST_FIFO_H
#define FIFOTEST_FIFO_H


class Fifo {
public:
    Fifo(int size);
    ~Fifo();
    bool write(int val);
    bool read(int* val);

private:
    unsigned int mRd;
    unsigned int mWr;
    unsigned int mMask;
    int* mBuf;
};


#endif //FIFOTEST_FIFO_H
