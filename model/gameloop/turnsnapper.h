#ifndef TURNSNAPPER_H
#define TURNSNAPPER_H

#include "model/basemodelobject.h"
#include "model/gameloop/gamemode.h"

namespace MegaGo {
    namespace Model {
        class TurnSnapper : public ModelObject {
        private:
            QVector<GameMode*> ldSnappets;
        public:
            TurnSnapper();
            ~TurnSnapper();
            
            void SaveTurn(GameMode * snappet);
            QVector<GameMode*> GetSnappets() { return ldSnappets; }
        };            
    }
}

#endif TURNSNAPPER_H
