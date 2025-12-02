#ifndef GAMEMODE_H
#define GAMEMODE_H

#include "model/actors/field.h"
#include "model/gameloop/team.h"
#include "model/accounts/clientaccount.h"

namespace MegaGo {
namespace Model {
    class GameMode : public ModelObject {
    Q_OBJECT
    private:
        // rules
        uint16_t maxPlayersInTeam;

        // data
        uint8_t currentTeamTurnIndex;
        Field * field;
        QVector<Team*> ldTeams;
    public:
        GameMode(int fieldSizeX,int fieldSizeY,int teamAmmount, uint16_t teamSize, QObject * parent = nullptr);
        ~GameMode();


        void Init(int fieldSizeX,int fieldSizeY,int teamAmmount, uint16_t maxPlayerInTeam);
        void AssignClientToTeam(ClientAccount * client, int16_t teamId);

        void TurnOn(int16_t firstTurnTeamId = 0);

       // bool ApplyTurn();

        uint8_t GetCurrentTeamTurnIndex() { return currentTeamTurnIndex; }
        Field * GetField() { return field; }
        QVector<Team*> GetTeams() { return ldTeams; }
    };
}
}

#endif // GAMEMODE_H
