#include "token.h"

using namespace MegaGo::Model;

Token::Token(uint64_t posX, uint64_t posY, QObject * parent)
    : ModelObject(parent), position(posX,posY)
{}

Token::~Token()
{
    if(IsDebuging_) Log("It is token");
}

void Token::SetPos(uint64_t posX_, uint64_t posY_) { position.Set(posX_,posY_); }

Pos2d* Token::GetPos() { return &position; }
