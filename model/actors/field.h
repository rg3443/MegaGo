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

        uint64_t sizeX, sizeY;
        uint8_t type;
    public:
        Field(uint64_t sizeX_, uint64_t sizeY_, uint8_t type_, QObject * parent = nullptr);
        ~Field();

        Tile*                      GetTile(uint64_t posX_, uint64_t posY_);
        QVector<QVector<Tile*>>*   GetTileMatrix();
        
        // in-game methods
        bool PlaceToken();
    private:
        void _InitTileMatrix();

    };

}
}

#endif // FIELD_H
