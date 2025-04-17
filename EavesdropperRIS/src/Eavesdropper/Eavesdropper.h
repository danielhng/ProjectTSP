
#include "inet/common/INETDefs.h"
#include "inet/common/ModuleAccess.h"
#include "inet/common/geometry/common/Coord.h"
#include "inet/physicallayer/common/Signal.h"
#include "inet/common/packet/Packet.h"
#include "inet/mobility/contract/IMobility.h"
#include "inet/physicallayer/wireless/common/contract/packetlevel/ITransmission.h"
#include "inet/physicallayer/wireless/common/contract/packetlevel/IRadioSignal.h"

using namespace inet;
using namespace inet::physicallayer;

class Eavesdropper : public cSimpleModule, public cListener
{

  public:
    Eavesdropper();           // Explicit constructor declaration
    virtual ~Eavesdropper();  // Explicit destructor declaration


  protected:
    IMobility *mobility = nullptr;

    virtual void initialize(int stage) override {
        if (stage == INITSTAGE_LOCAL) {
            mobility = check_and_cast<IMobility *>(getSubmodule("mobility"));
        }
    }

    virtual void receiveSignal(cComponent *source, simsignal_t signalID, cObject *obj, cObject *details) override {

        const auto * transmission = check_and_cast<const ITransmission*>(obj);
        Coord senderPos = transmission->getStartPosition();
        Coord receiverPos = transmission->getEndPosition(); // Estimated or fallback
        auto myPos = mobility->getCurrentPosition();

        if (isOnPath(senderPos, receiverPos, myPos)) {
            EV_INFO << "[Eavesdropper] Packet intercepted on path between sender and receiver.\n";
        }
    }

    bool isOnPath(const Coord& a, const Coord& b, const Coord& c, double tolerance = 5.0) {
        // Distance from point c to line ab
        double coefA = (b.x - a.x) / (b.y - a.y);
        double coefB = -1;
        double coefC = b.y - (coefA * b.x);
        double dist = fabs(coefA * c.x + coefB * c.y + coefC)/sqrt(coefA*coefA + coefB*coefB);
        // double num = fabs((b.y - a.y) * c.x - (b.x - a.x) * c.y + b.x * a.y - b.y * a.x);
        // double denom = a.distance(b);
        // double d = dist == 0 ? c.distance(a) : num / denom;
        return dist < tolerance;
    }
};

Define_Module(Eavesdropper);
