#include "XXX.h"
#include <algorithm>
using std::move;

XXX make_copy(XXX xxx) {
    return xxx;
}

int main() {

    XXX old_xxx{};

    XXX new_xxx{move(old_xxx)};

    XXX another_xxx{};

    another_xxx = std::move(new_xxx);

    XXX one_more = make_copy(another_xxx);
}