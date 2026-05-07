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

void Allience::SetBreathe(uint64_t breathePoints_)
{
    breathePoints = breathePoints_;
}

bool Allience::PosIsNearby(Pos2d pos)
{
    for(int tokid=0;tokid<lTokens.size();tokid++) {
        if(lTokens[tokid]->GetPos()->CalcDistance(pos) == 1) 
            return true;
    }
    return false;
}

QVector<Tile*> * Allience::GetTokens()
{
    return &lTokens;
}

uint64_t Allience::GetBreathe()
{
    return breathePoints;
}
