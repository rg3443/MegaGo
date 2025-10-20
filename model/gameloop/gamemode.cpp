#include "gamemode.h"

using namespace MegaGo::Model;

GameMode::GameMode(int fieldSizeX,int fieldSizeY,int teamAmmount, QObject * parent)
    : ModelObject(parent), field(fieldSizeX,fieldSizeY,ID_FIELD_CLASSIC,this)
{


}

GameMode::~GameMode()
{
    if(IsDebuging_) Log("It is gamemode");
}
