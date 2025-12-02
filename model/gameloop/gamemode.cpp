#include "gamemode.h"

using namespace MegaGo::Model;

GameMode::GameMode(int fieldSizeX,int fieldSizeY,int teamAmmount, uint16_t teamSize, QObject * parent)
    : ModelObject(parent)//, field(fieldSizeX,fieldSizeY,ID_FIELD_CLASSIC,this)
{
    Init(fieldSizeX,fieldSizeY,teamAmmount,teamSize);

}

GameMode::~GameMode()
{
    if(IsDebuging_) Log("It is gamemode");
}

void GameMode::Init(int fieldSizeX, int fieldSizeY, int teamAmmount, uint16_t maxPlayersInTeam_)
{
    maxPlayersInTeam = maxPlayersInTeam_;
    field = new Field(fieldSizeX,fieldSizeY,ID_FIELD_CLASSIC,this);
    for(int i=0;i<teamAmmount;i++) {
        ldTeams.append(new Team(this));
        ldTeams.last()->SetMaxPlayers(maxPlayersInTeam);
    }
}

void GameMode::AssignClientToTeam(ClientAccount *client, int16_t teamId)
{
    if(teamId < 0) // its random
    {

    } else if(teamId >= ldTeams.size()) { // teamId too big -> random?

    } else {
        ldTeams[teamId]->AssignClient(client->GetLogin());
    }

}

void GameMode::TurnOn(int16_t firstTurnTeamId)
{
    if(firstTurnTeamId < 0)
        currentTeamTurnIndex = 0;
    else currentTeamTurnIndex = firstTurnTeamId;
}
