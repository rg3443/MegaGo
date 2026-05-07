#ifndef FIELD_H
#define FIELD_H

#include "model/actors/tile.h"
#include "model/actors/allience.h"


namespace MegaGo {
namespace Model {

    enum FieldType {
        ID_FIELD_CLASSIC,
        ID_FIELD_CUSTOM
    };
    class Field : public ModelObject {
    Q_OBJECT
    private:
        QVector<QVector<Tile*>> tileMatrix;
        QVector<Allience*> ldAlliences;
        QVector<Allience*> lRecentDestroyedAlliences; // all alliences who was captured sent here until method GetDestroyedAlliences called
        QVector<Allience*> ldDestroyedAlliences;      // than the move here to be deleted in desctructor

        uint64_t sizeX, sizeY;
        uint8_t type;
    public:
        Field(uint64_t sizeX_, uint64_t sizeY_, uint8_t type_, QObject * parent = nullptr);
        ~Field();

        Tile*                      GetTile(uint64_t posX_, uint64_t posY_);
        QVector<QVector<Tile*>>*   GetTileMatrix();
        
        // // in-game methods
        // place token
        bool PlaceToken(Token * token, Pos2d pos);
        // unplace token byt token
        bool UnplaceToken(Token* token);
        // unplace token by coordinates
        bool ClearTile(Pos2d pos);
        // check if allience is alive
        bool CheckAllianceLifeness(Allience* allience);
        // check if token is alive
        bool CheckTokenLifenessByTile(Tile* tile);
        // unplace all allience-related tokens
        bool ClearAllience(Allience* allience);

        // // analyse methods
        // get closest allience to position
        QVector<Allience*> CheckAlliencesCloseBy(Pos2d pos);
        //
        void ClearEmptyAlliences();
        // recalculate all alliences breathe points
        void RecalcAlliencesBreathe();

        // get recent destroyed alliences and
        QVector<Allience*> GetDestroyedAlliences();
    private:
        void _InitTileMatrix();

        //
        bool _PosIsValid(Pos2d pos);

        // find allience for token and set it
        void _AllocateTokenToAllience(Tile * ocupiedTile);

    };

}
}

#endif // FIELD_H
