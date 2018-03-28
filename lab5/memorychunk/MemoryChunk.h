//
// Created by kilimich on 28.03.18.
//

#ifndef JIMP_EXERCISES_MEMORYCHUNK_H
#define JIMP_EXERCISES_MEMORYCHUNK_H

#include <cstdint>
#include <algorithm>

namespace memorychunk {
    class MemoryChunk {
    public:
        MemoryChunk(size_t sz);
        int8_t *MemoryAt(size_t offset) const;
        size_t ChunkSize() const;
    private:
        size_t sz_;


    };
}


#endif //JIMP_EXERCISES_MEMORYCHUNK_H
