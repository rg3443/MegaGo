#include "field.h"

using namespace MegaGo::Model;

Field::Field(uint64_t sizeX_, uint64_t sizeY_, uint8_t type_, QObject * parent)
    : ModelObject(parent)
{
    type = type_;
    sizeX = sizeX_;
    sizeY = sizeY_;
    this->_InitTileMatrix();
}

Field::~Field()
{
    if(IsDebuging_) Log("It is field");
}

Tile* Field::GetTile(uint64_t posX_, uint64_t posY_)
{
    try {
        if(posX_ > tileMatrix.size())
            throw "Field::GetTile: wrong x";
        else if(posY_ > tileMatrix.first().size())
            throw "Field::GetTile: wrong y";
        else
            return tileMatrix[posX_][posY_];
    } catch(const char* err) { if(IsDebuging_) Log(err);  return nullptr; }
}

QVector<QVector<Tile*>> * Field::GetTileMatrix() { return &tileMatrix; }

void Field::_InitTileMatrix()
{
    for(int x=0;x<sizeX;x++) {
        tileMatrix.append(QVector<Tile*>());
        for(int y=0;y<sizeY;y++) {
            tileMatrix[x].append(new Tile(x,y,nullptr,this));
        }
    }
}
