#ifndef CLIENTACCOUNT_H
#define CLIENTACCOUNT_H

#include "model/basemodelobject.h"

namespace MegaGo {
namespace Model {
    class ClientAccount : public ModelObject {
    private:
        QString login;

    public:
        ClientAccount() { login = "test_login"; }
        ~ClientAccount() {}

        QString GetLogin() { return login; }
    };
}
}

#endif // CLIENTACCOUNT_H
