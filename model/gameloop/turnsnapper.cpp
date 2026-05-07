#include "turnsnapper.h"

using namespace MegaGo::Model;

TurnSnapper::TurnSnapper()
{
    
}

TurnSnapper::~TurnSnapper()
{
    
}

void TurnSnapper::SaveTurn(GameMode * snappet)
{
    ldSnappets.append(new GameMode(*snappet));
}