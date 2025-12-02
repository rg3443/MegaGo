#ifndef GVAR_H
#define GVAR_H

#include "ginclude.h"
namespace MegaGo {
namespace Model {
    static bool IsDebuging_;

    static const uint64_t gNullPos_ = 9999;
    struct Pos2d {
        uint64_t x, y;

        Pos2d(uint64_t posX_, uint64_t posY_) {
            Set(posX_,posY_);
        }
        void Set(uint64_t posX_, uint64_t posY_) {
            x = posX_;
            y = posY_;
        }
    };
}
}

#endif // GVAR_H
