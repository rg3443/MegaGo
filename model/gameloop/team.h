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
        int points;
    public:
        Team(QObject * parent = nullptr);
        ~Team();

        // set maximum player ammount in team
        void SetMaxPlayers(uint16_t maxAmmount);
        // create player and assign client to it
        void AssignClient(uint64_t clientId);
        // delete player object via clientId
        bool DeletePlayer(uint64_t clientId);
        //
        void SetPoints(int points_) { points = points_; }

        // turn
        Player* GetCurrentTurnPlayer();
        bool TurnMade(uint64_t playerId);

        // getters
        uint16_t GetMaxPlayers() { return maxPlayersAmmount; }
        Player* GetPlayer(uint64_t clientId);
        Player* GetPlayer(unsigned long int playerId);
        int GetPoints() { return points; }
    };
}
}

#endif // TEAM_H
