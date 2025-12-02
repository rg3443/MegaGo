#ifndef TEAM_H
#define TEAM_H

#include "model/gameloop/player.h"

namespace MegaGo {
namespace Model {
    enum TeamColor {
        ID_TEAM_NONE,
        ID_TEAM_BLACK,
        ID_TEAM_WHITE,
        ID_TEAM_RED,
        ID_TEAM_BLUE
    };

    class Team : public ModelObject {
    Q_OBJECT
    private:
        uint16_t maxPlayersAmmount;
        uint8_t currentPlayerTurnIndex;
        QVector<Player*> ldPlayers;
    public:
        Team(QObject * parent = nullptr);
        ~Team();
        // setters
        void SetMaxPlayers(uint16_t maxAmmount);
        void AssignClient(QString login);

        // turn
        Player* GetCurrentTurnPlayer();
        bool TurnMade(uint64_t playerId);

        // getters
        uint16_t GetMaxPlayers() { return maxPlayersAmmount; }
        Player* GetPlayer(uint16_t internalId);
        Player* GetPlayer(QString login);
    };
}
}

#endif // TEAM_H
