#ifndef GAMEMODE_H
#define GAMEMODE_H

#include "model/actors/field.h"
#include "model/gameloop/team.h"
#include "model/accounts/clientaccount.h"

namespace MegaGo {
namespace Model {
    struct GameModeSettings {
        int32_t maxSlotsInTeam;
        int32_t teamsAmmount;
        Pos2d fieldSize;

        GameModeSettings() {}
    };

    class GameMode : public ModelObject {
    Q_OBJECT
    private:
        // rules
        GameModeSettings settings;
        // data
        uint8_t currentTeamTurnIndex;
        Field * field;
        QVector<Team*> ldTeams;
    public:
        GameMode(QObject * parent = nullptr);
        ~GameMode();


        void InitRoom(int fieldSizeX,int fieldSizeY,int teamAmmount, uint16_t maxPlayerInTeam);
        bool AssignClientToTeam(ClientAccount * client, uint64_t teamId);

        
        // in-play methods
        bool TurnOn(uint64_t firstTurnTeamId = 0);
        bool PlaceToken(Player* player, Pos2d pos);
        bool PassTurn(Player* player);

        // pointer getters
        Field * GetField_P() { return field; }
        GameModeSettings * GetSettings_P() { return &settings; }
        QVector<Team*> GetTeamList_P() { return ldTeams; }
        // static getters
        uint8_t GetCurrentTeamTurnIndex() { return currentTeamTurnIndex; }
        uint64_t GetCurrentPlayerTurnId();
        
    private:
        void _CycleTurnIndex();
    };
}
}

#endif // GAMEMODE_H
