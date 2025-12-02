#ifndef ALLIENCE_H
#define ALLIENCE_H

#include "model/actors/tile.h"

namespace MegaGo {
namespace Model {
    class Allience : public ModelObject {
    Q_OBJECT
    private:
        QVector<Tile*> lTokens;
        uint64_t breathePoints;
    public:
        Allience(Tile* firstTile, uint64_t breathePoints_, QObject * parent = nullptr);
        ~Allience();

        void SetBreathe(uint64_t breathePoints_);

        QVector<Tile*>& GetTokens();
        uint64_t        GetBreathe();

    };
}
}

#endif // ALLIENCE_H
