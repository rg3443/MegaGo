#include "allience.h"

using namespace MegaGo::Model;

Allience::Allience(Tile* firstTile, uint64_t breathePoints_, QObject * parent)
    : ModelObject(parent)
{
    vTokens.append(firstTile);
    breathePoints = breathePoints_;
}

Allience::~Allience()
{
    if(IsDebuging_) Log("It is allience");
}
