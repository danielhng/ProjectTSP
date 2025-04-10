#include <omnetpp.h>

#include "inet/applications/tcpapp/TcpAppBase.h"

using namespace omnetpp;
using namespace inet;

class AttackerNode : public TcpAppBase
{
    protected:
        virtual void initialize(int stage) override;
        virtual void handleMessageWhenUp(cMessage *msg) override;
        void launchDoSAttack();
        void launchInterception();
};

Define_Module(AttackerNode);
void AttackerNode::initialize(int stage)
{
    TcpAppBase::initialize(stage);
    if (stage == inet::INITSTAGE_APPLICATION_LAYER) {
        scheduleAt(simTime() + 2, new cMessage("launchDoSAttack"));
        scheduleAt(simTime() + 5, new cMessage("launchInterception"));
    }
}

void AttackerNode::handleMessageWhenUp(cMessage *msg)
{
    if (strcmp(msg->getName(), "launchDoSAttack") == 0) {
        launchDoSAttack();
        delete msg;
    } else if (strcmp(msg->getName(), "launchInterception") == 0) {
        launchInterception();
        delete msg;
    } else {
        TcpAppBase::handleMessageWhenUp(msg);
    }
}

void AttackerNode::launchDoSAttack()
{
    EV << "Launching DoS attack on gNodeB..." << endl;
    for (int i = 0; i < 100; i++) {
        Packet *packet = new Packet("DoSPacket");
        sendToUDP(packet, localPort, Ipv4AddressResolver().resolve("gnb1"), 5000);
    }
}

void AttackerNode::launchInterception()
{
    EV << "Launching interception attempt..." << endl;
    // Send a packet to intercept communication between UE and gNodeB
    Packet *packet = new Packet("InterceptionPacket");
    packet->insertAtBack(makeShared<Chunk>(std::vector<int>{999, 999, 999})); // Example malicious data
    sendToUDP(packet, localPort, Ipv4AddressResolver().resolve("gnb1"), 5000);
}
