#ifndef BASEMODELOBJECT_H
#define BASEMODELOBJECT_H

#include "ginclude.h"
#include "model/gvar.h"

namespace MegaGo {
namespace Model {
    class ModelObject : public QObject {
        Q_OBJECT
    private:
        uint64_t internalId;
        static uint64_t internalIdCounter;
    public:
        ModelObject(QObject * parent = nullptr);
        ~ModelObject();

        void SetId(unsigned long long int id);
        uint64_t GetId();

        void Log(QString str);

    };
}
}

#endif // BASEMODELOBJECT_H
