#ifndef CLIENTACCOUNT_H
#define CLIENTACCOUNT_H

#include "model/basemodelobject.h"

namespace MegaGo {
namespace Model {
    struct ClientStatistic {
        int64_t playedGames,
                wonGames,
                lostGames,
                eatenTokens;
        int16_t firstSurrender;
    };

    class ClientAccount : public ModelObject {
    private:
        QString
        login,
        password,
        nickname;

        int avatarImgId;
        ClientStatistic statistics;
    public:
        ClientAccount();
        ~ClientAccount() {}

        void Set(QString login_,QString password_,QString nickname_, int avatarImgId_);

        QString GetLogin() { return login; }
        QString GetPassword() { return password; }
        QString GetNickname() { return nickname; }

        int GetAvatarId() { return avatarImgId; }

        ClientStatistic * GetStatistics_P() { return &statistics; }
    };
}
}

#endif // CLIENTACCOUNT_H
