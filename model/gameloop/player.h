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
        uint64_t clientId;
    public:
        Player(QObject * parent = nullptr);
        ~Player();

        void Customise(QString newName, uint8_t newIconId = ID_PLAYER_NONE);
        void AssignClient(uint64_t clientId_);
        Token* CreateToken();
        bool DeleteToken(Token * token);

        // getters
        QString GetName() { return name; }
        uint8_t GetIconId() { return iconId; }
        QVector<Token*> GetTokens() { return ldTokens; }
        uint64_t GetClientId() { return clientId; }
    };
}
}

#endif // PLAYER_H
