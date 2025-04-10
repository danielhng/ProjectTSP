#include <omnetpp.h>

#include “inet/common/INETDefs.h”
#include “inet/common/packet/Packet.h”

using namespace omnetpp;
using namespace inet;

class IDSModule : public cSimpleModule
{
    protected:
        virtual void initialize() override;
        virtual void handleMessage(cMessage *msg) override;
        void detectIntrusion(Packet *packet);
};

Define_Module(IDSModule);
void IDSModule::initialize()
{
    EV << "IDS Module Initialized" << endl;
}

void IDSModule::handleMessage(cMessage *msg)
{
    if (Packet *packet = dynamic_cast<Packet *>(msg)) {
        detectIntrusion(packet);
        send(packet, "ethgOut");
    }
    delete msg;
}

void IDSModule::detectIntrusion(Packet *packet)
{
    const auto &payload = packet->peekData();
    std::string data = payload->str();
    // Implement simple intrusion detection logic
    if (data.find("attack") != std::string::npos) {
        EV << "Intrusion detected! Taking action..." << endl;
        // Implement any action needed (e.g., alerting, blocking)
    }
}
