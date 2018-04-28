#ifndef JIMP_EXERCISES_ITERABLE_H
#define JIMP_EXERCISES_ITERABLE_H

#include <string>
#include <vector>
#include <bits/unique_ptr.h>
namespace utility {
    class IterableIterator {
    public:
        virtual std::pair<int, std::string> Dereference() const = 0;
        virtual IterableIterator &Next() = 0;
        virtual bool NotEquals(const std::unique_ptr<IterableIterator> &other) const = 0;
        virtual ~IterableIterator() = default;
    };

}

#endif //JIMP_EXERCISES_ITERABLE_H