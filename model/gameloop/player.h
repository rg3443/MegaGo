#ifndef PLAYER_H
#define PLAYER_H

#include "model/actors/token.h"

namespace MegaGo {
namespace Model {
    class Player : public ModelObject {
    Q_OBJECT
    private:
        QString name;
        QVector<Token*> vTokens;
    public:
        Player(sQObject * parent = nullptr);
        ~Player();
    };
}
}

#endif // PLAYER_H
