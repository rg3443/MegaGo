#include "clientaccount.h"

using namespace MegaGo::Model;

ClientAccount::ClientAccount()
    : ModelObject()
{
    login = "default_login";
    password = "default_password";
    nickname = "default_nickname";
}

void ClientAccount::Set(QString login_, QString password_, QString nickname_, int avatarImgId_)
{
    if(login_ != NULL) login = login_;
    if(password_ != NULL) password = password_;
    if(nickname_ != NULL) nickname = nickname_;
    if(avatarImgId_ != NULL) avatarImgId = avatarImgId_;

    try {

    } catch(const char * err) { if(IsDebuging_) qDebug(err); }
}



