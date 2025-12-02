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

void Player::Customise(QString newName, uint8_t newIconId)
{
    if(newName == "") name = QString("Player") + this->GetId();
    iconId = newIconId;
}

void Player::AssignClientLogin(QString login)
{
    clientLogin = login;
}
