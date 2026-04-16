#include "allience.h"

using namespace MegaGo::Model;

Allience::Allience(Tile* firstTile, uint64_t breathePoints_, QObject * parent)
    : ModelObject(parent)
{
    lTokens.append(firstTile);
    breathePoints = breathePoints_;
}

Allience::~Allience()
{
    if(IsDebuging_) Log("It is allience");
}

QVector<Tile*> & Allience::GetTokens()
{
    return lTokens;
}

uint64_t Allience::GetBreathe()
{
    return breathePoints;
}
