#ifndef TOKEN_H
#define TOKEN_H

#include "model/basemodelobject.h"

namespace MegaGo {
namespace Model {

    class Token : public ModelObject {
    Q_OBJECT
    private:
        Pos2d position;

    public:
        Token(uint64_t posX, uint64_t posY, QObject * parent = nullptr);
        ~Token();

        void SetPos(uint64_t posX_, uint64_t posY_);

        Pos2d* GetPos();

    };

}
}

#endif // TOKEN_H
