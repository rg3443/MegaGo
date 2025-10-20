#ifndef GAMEMODE_H
#define GAMEMODE_H

#include "model/actors/field.h"
#include "model/gameloop/team.h"

namespace MegaGo {
namespace Model {
    class GameMode : public ModelObject {
    Q_OBJECT
    private:
        Field field;
        //QVector<Team> vTeams;
    public:
        GameMode(int fieldSizeX,int fieldSizeY,int teamAmmount, QObject * parent = nullptr);
        ~GameMode();
    };
}
}

#endif // GAMEMODE_H
