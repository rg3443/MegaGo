#ifndef TEAM_H
#define TEAM_H

#include "model/gameloop/player.h"

namespace MegaGo {
namespace Model {
    class Team : public ModelObject {
    Q_OBJECT
    private:
    public:
        Team( QObject * parent = nullptr);
        ~Team();
    };
}
}

#endif // TEAM_H
