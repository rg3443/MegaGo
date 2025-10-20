#include "player.h"

using namespace MegaGo::Model;

Player::Player(QObject * parent)
    : ModelObject(parent)
{

}

Player::~Player()
{
    if(IsDebuging_) Log("It is player");
}
