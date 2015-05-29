//
// Created by Andrey Syvrachev on 29.05.15.
//

#include <assert.h>
#include "Fifo.h"
//#include <atomic>


Fifo::Fifo(int size): mWr(0), mRd (0),mMask(size -1)
{
    assert((mMask & size) == 0); // check size = 2^n
    mBuf = (int*)malloc(size * sizeof(int));
}

Fifo::~Fifo(){
    free(mBuf);
}

bool Fifo::write(int val) {

    unsigned int wr = (mWr + 1) & mMask;
    if (wr == mRd){
        return false;
    }
    mBuf[mWr] = val;
//    atomic_thread_fence(std::memory_order_release);
    mWr = wr;
    return true;
}


bool Fifo::read(int *val) {
    if (mWr == mRd){
        return false;
    }
    *val = mBuf[mRd];
//    atomic_thread_fence(std::memory_order_release);
    mRd = (mRd + 1) & mMask;
    return true;
}