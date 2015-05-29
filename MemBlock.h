//
// Created by Andrey Syvrachev on 29.05.15.
//

#ifndef FIFOTEST_MEMBLOCK_H
#define FIFOTEST_MEMBLOCK_H

#pragma pack(push, 1)
struct MemBlock {
    MemBlock(int count){
        for (int i = 0; i < sizeof(values)/ sizeof(values[0]); i++){
            values[i] = count++;
        }
    }
    bool check(int count){
        for (int i = 0; i < sizeof(values)/ sizeof(values[0]); i++){
            if (values[i] != count++)
                return false;
        }
        return true;
    }
    int values[123];
};
#pragma pack(pop)

#endif //FIFOTEST_MEMBLOCK_H
