//
// Created by Andrey Syvrachev on 29.05.15.
//

#ifndef FIFOTEST_FIFO_H
#define FIFOTEST_FIFO_H

#include <assert.h>
#include <atomic>
#include <mutex>

template <class T>
class Fifo {
public:
    std::mutex mMutex;
    Fifo(int size): mWr(0), mRd (0),mMask(size -1)
    {
        assert((mMask & size) == 0); // check size = 2^n
        mBuf = (T*)malloc(size * sizeof(T));
    }

    ~Fifo(){
        free(mBuf);
    }

    bool write(T val) {
 //       std::lock_guard<std::mutex> lock(mMutex);

        unsigned int wr = (mWr + 1) & mMask;
        if (wr == mRd){
            return false;
        }
        mBuf[mWr] = val;
        mWr = wr;
        return true;
    }

    bool read(T* val) {
 //       std::lock_guard<std::mutex> lock(mMutex);

        if (mWr == mRd){
            return false;
        }
        *val = mBuf[mRd];
        mRd = (mRd + 1) & mMask;

        return true;
    }

private:
    unsigned int mRd;
    unsigned int mWr;
    unsigned int mMask;
    T* mBuf;
};


#endif //FIFOTEST_FIFO_H
