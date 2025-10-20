#include "tile.h"

using namespace MegaGo::Model;

Tile::Tile(uint64_t posX, uint64_t posY, Token * tokenContainer_, QObject * parent)
    : ModelObject(parent),position(posX,posY)
{
    tokenContainer = tokenContainer_;
}

Tile::~Tile()
{
    if(IsDebuging_) Log("It is tile");
}

void Tile::SetPos(uint64_t posX_, uint64_t posY_) { position.Set(posX_,posY_); }

Pos2d* Tile::GetPos() { return &position; }

void Tile::SetToken(Token *token) { tokenContainer = token; }

Token* Tile::GetToken() { return tokenContainer; }
