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

void Player::AssignClient(uint64_t clientId_)
{
    clientId = clientId_;
}

Token* Player::CreateToken( )
{
    try {
        Token * newToken = new Token(-1,-1, this);
        newToken->SetPlayerId(this->GetId());
        ldTokens.push_back(newToken);
        return newToken;
    } catch(const char * err) { if(IsDebuging_) Log(err); }
}

bool Player::DeleteToken(Token *token)
{
    for(int tokid=0;tokid<ldTokens.size();tokid++) {
        if(ldTokens[tokid] == token) {
            ldTokens.erase(ldTokens.begin()+tokid);
            delete token;
        }
    }
}
