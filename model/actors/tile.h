#ifndef TILE_H
#define TILE_H

#include "model/actors/token.h"

namespace MegaGo {
namespace Model {

    class Tile : public ModelObject {
    Q_OBJECT
    private:
        Pos2d position;
        Token * tokenContainer;
    public:
        Tile(uint64_t posX = gNullPos_, uint64_t posY = gNullPos_, Token * tokenContainer_ = nullptr, QObject * parent = nullptr);
        ~Tile();

        void SetPos(uint64_t posX_, uint64_t posY_);
        Pos2d* GetPos();

        void SetToken(Token * token);
        Token* GetToken();
    };

}
}

#endif // TILE_H
