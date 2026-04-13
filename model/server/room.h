#ifndef ROOM_H
#define ROOM_H

#include "model/gameloop/gamemode.h"

namespace MegaGo {
namespace Model {
    enum RoomType {
        ID_ROOMSTATE_DEFAULT = 0,
        ID_ROOMTYPE_OPEN,
        ID_ROOMTYPE_PRIVATE
    };

    struct RoomSettings {
        int8_t type;
        QString password;
        int64_t slotAmmount;
    };

    class Room : public ModelObject {
    Q_OBJECT
    private:
        int64_t hostClientId;
        QVector<int64_t> playersClientId;
        int64_t gameloopId;
        RoomSettings settings;
    public:
        Room();
        ~Room();
        bool AddPlayerId(int64_t id);
        bool DeletePlayerId(int64_t id);
        // setters
        bool SetHostId(int64_t id);
        bool SetGameloopId(int64_t id);
        // getters
        // // static
        int64_t GetHostId() { return hostClientId; }
        QVector<int64_t> GetPlayersIds() { return playersClientId; }
        int64_t GetGameloopId() { return gameLoopId; }
        // // pointer
        RoomSettings * GetSettings() { return &settings; }
    };
}
}

#endif // ROOM_H
