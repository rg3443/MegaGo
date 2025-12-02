#ifndef PLAYER_H
#define PLAYER_H

#include "model/actors/token.h"

namespace MegaGo {
namespace Model {
    enum PlayerIcon {
        ID_PLAYER_NONE,
        ID_PLAYER_LION,
        ID_PLAYER_EAGLE,
        ID_PLAYER_CAR,
        ID_PLAYER_HAT
    };

    class Player : public ModelObject {
    Q_OBJECT
    private:
        QString name;
        uint8_t iconId;
        QVector<Token*> ldTokens;
        QString clientLogin;
    public:
        Player(QObject * parent = nullptr);
        ~Player();

        void Customise(QString newName, uint8_t newIconId = ID_PLAYER_NONE);
        void AssignClientLogin(QString login);

        // getters
        QString GetName() { return name; }
        uint8_t GetIconId() { return iconId; }
        QVector<Token*>* GetTokens() { return &ldTokens; }
        QString GetClientLogin() { return clientLogin; }
    };
}
}

#endif // PLAYER_H
