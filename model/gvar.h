#ifndef GVAR_H
#define GVAR_H

#include "ginclude.h"
namespace MegaGo {
namespace Model {
    static bool IsDebuging_;

    static const uint64_t gNullPos_ = 9999;
    struct Pos2d {
        int64_t x, y;

        Pos2d(int64_t posX_ = 0, int64_t posY_ = 0) {
            Set(posX_,posY_);
        }
        void Set(int64_t posX_, int64_t posY_) {
            x = posX_;
            y = posY_;
        }

        bool IsValid() {
            if(x < 0 || y < 0) return false;
            else return true;
        }

        bool operator==(const Pos2d& other) {
            if(this->_Equals(other)) return true;
            else return false;
        }
        bool operator!=(const Pos2d& other) {
            if(!this->_Equals(other)) return true;
            else return false;
        }
        
        uint64_t CalcDistance(Pos2d pos) {
            uint64_t res;
            if(pos.x > x)
                res += (pos.x-x);
            else if(pos.x < x)
                res += (x-pos.x);
             // else  nothing
            if(pos.y > y) 
                res += (pos.y-y);
            else 
                res += (y-pos.y);
            
            return res;
        }

    private:
        bool _Equals(const Pos2d & other)
        {
            if(x != other.x ||
               y != other.y) return false;
            else return true;
        }
    };
}
}

#endif // GVAR_H
