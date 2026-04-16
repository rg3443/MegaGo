#ifndef TOKEN_H
#define TOKEN_H

#include "model/basemodelobject.h"

namespace MegaGo {
namespace Model {

    class Token : public ModelObject {
    Q_OBJECT
    private:
        Pos2d position;
        uint64_t playerId;
    public:
        Token(uint64_t posX, uint64_t posY, QObject * parent = nullptr);
        ~Token();

        void SetPlayerId(uint64_t id) { playerId = id; }

        void SetPos(uint64_t posX_, uint64_t posY_);
        void SetPos(Pos2d pos) { position = pos; }
        void SetPos(Pos2d * pos) { if(pos!=nullptr) position = *pos; }

        Pos2d* GetPos();

    };

}
}

#endif // TOKEN_H
