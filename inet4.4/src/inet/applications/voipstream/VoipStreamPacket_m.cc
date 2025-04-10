//
// Generated file, do not edit! Created by opp_msgtool 6.0 from inet/applications/voipstream/VoipStreamPacket.msg.
//

// Disable warnings about unused variables, empty switch stmts, etc:
#ifdef _MSC_VER
#  pragma warning(disable:4101)
#  pragma warning(disable:4065)
#endif

#if defined(__clang__)
#  pragma clang diagnostic ignored "-Wshadow"
#  pragma clang diagnostic ignored "-Wconversion"
#  pragma clang diagnostic ignored "-Wunused-parameter"
#  pragma clang diagnostic ignored "-Wc++98-compat"
#  pragma clang diagnostic ignored "-Wunreachable-code-break"
#  pragma clang diagnostic ignored "-Wold-style-cast"
#elif defined(__GNUC__)
#  pragma GCC diagnostic ignored "-Wshadow"
#  pragma GCC diagnostic ignored "-Wconversion"
#  pragma GCC diagnostic ignored "-Wunused-parameter"
#  pragma GCC diagnostic ignored "-Wold-style-cast"
#  pragma GCC diagnostic ignored "-Wsuggest-attribute=noreturn"
#  pragma GCC diagnostic ignored "-Wfloat-conversion"
#endif

#include <iostream>
#include <sstream>
#include <memory>
#include <type_traits>
#include "VoipStreamPacket_m.h"

namespace omnetpp {

// Template pack/unpack rules. They are declared *after* a1l type-specific pack functions for multiple reasons.
// They are in the omnetpp namespace, to allow them to be found by argument-dependent lookup via the cCommBuffer argument

// Packing/unpacking an std::vector
template<typename T, typename A>
void doParsimPacking(omnetpp::cCommBuffer *buffer, const std::vector<T,A>& v)
{
    int n = v.size();
    doParsimPacking(buffer, n);
    for (int i = 0; i < n; i++)
        doParsimPacking(buffer, v[i]);
}

template<typename T, typename A>
void doParsimUnpacking(omnetpp::cCommBuffer *buffer, std::vector<T,A>& v)
{
    int n;
    doParsimUnpacking(buffer, n);
    v.resize(n);
    for (int i = 0; i < n; i++)
        doParsimUnpacking(buffer, v[i]);
}

// Packing/unpacking an std::list
template<typename T, typename A>
void doParsimPacking(omnetpp::cCommBuffer *buffer, const std::list<T,A>& l)
{
    doParsimPacking(buffer, (int)l.size());
    for (typename std::list<T,A>::const_iterator it = l.begin(); it != l.end(); ++it)
        doParsimPacking(buffer, (T&)*it);
}

template<typename T, typename A>
void doParsimUnpacking(omnetpp::cCommBuffer *buffer, std::list<T,A>& l)
{
    int n;
    doParsimUnpacking(buffer, n);
    for (int i = 0; i < n; i++) {
        l.push_back(T());
        doParsimUnpacking(buffer, l.back());
    }
}

// Packing/unpacking an std::set
template<typename T, typename Tr, typename A>
void doParsimPacking(omnetpp::cCommBuffer *buffer, const std::set<T,Tr,A>& s)
{
    doParsimPacking(buffer, (int)s.size());
    for (typename std::set<T,Tr,A>::const_iterator it = s.begin(); it != s.end(); ++it)
        doParsimPacking(buffer, *it);
}

template<typename T, typename Tr, typename A>
void doParsimUnpacking(omnetpp::cCommBuffer *buffer, std::set<T,Tr,A>& s)
{
    int n;
    doParsimUnpacking(buffer, n);
    for (int i = 0; i < n; i++) {
        T x;
        doParsimUnpacking(buffer, x);
        s.insert(x);
    }
}

// Packing/unpacking an std::map
template<typename K, typename V, typename Tr, typename A>
void doParsimPacking(omnetpp::cCommBuffer *buffer, const std::map<K,V,Tr,A>& m)
{
    doParsimPacking(buffer, (int)m.size());
    for (typename std::map<K,V,Tr,A>::const_iterator it = m.begin(); it != m.end(); ++it) {
        doParsimPacking(buffer, it->first);
        doParsimPacking(buffer, it->second);
    }
}

template<typename K, typename V, typename Tr, typename A>
void doParsimUnpacking(omnetpp::cCommBuffer *buffer, std::map<K,V,Tr,A>& m)
{
    int n;
    doParsimUnpacking(buffer, n);
    for (int i = 0; i < n; i++) {
        K k; V v;
        doParsimUnpacking(buffer, k);
        doParsimUnpacking(buffer, v);
        m[k] = v;
    }
}

// Default pack/unpack function for arrays
template<typename T>
void doParsimArrayPacking(omnetpp::cCommBuffer *b, const T *t, int n)
{
    for (int i = 0; i < n; i++)
        doParsimPacking(b, t[i]);
}

template<typename T>
void doParsimArrayUnpacking(omnetpp::cCommBuffer *b, T *t, int n)
{
    for (int i = 0; i < n; i++)
        doParsimUnpacking(b, t[i]);
}

// Default rule to prevent compiler from choosing base class' doParsimPacking() function
template<typename T>
void doParsimPacking(omnetpp::cCommBuffer *, const T& t)
{
    throw omnetpp::cRuntimeError("Parsim error: No doParsimPacking() function for type %s", omnetpp::opp_typename(typeid(t)));
}

template<typename T>
void doParsimUnpacking(omnetpp::cCommBuffer *, T& t)
{
    throw omnetpp::cRuntimeError("Parsim error: No doParsimUnpacking() function for type %s", omnetpp::opp_typename(typeid(t)));
}

}  // namespace omnetpp

namespace inet {

Register_Enum(inet::VoipStreamPacketType, (inet::VoipStreamPacketType::VOICE, inet::VoipStreamPacketType::SILENCE));

Register_Class(VoipStreamPacket)

VoipStreamPacket::VoipStreamPacket() : ::inet::FieldsChunk()
{
}

VoipStreamPacket::VoipStreamPacket(const VoipStreamPacket& other) : ::inet::FieldsChunk(other)
{
    copy(other);
}

VoipStreamPacket::~VoipStreamPacket()
{
}

VoipStreamPacket& VoipStreamPacket::operator=(const VoipStreamPacket& other)
{
    if (this == &other) return *this;
    ::inet::FieldsChunk::operator=(other);
    copy(other);
    return *this;
}

void VoipStreamPacket::copy(const VoipStreamPacket& other)
{
    this->headerLength = other.headerLength;
    this->type = other.type;
    this->codec = other.codec;
    this->sampleBits = other.sampleBits;
    this->sampleRate = other.sampleRate;
    this->transmitBitrate = other.transmitBitrate;
    this->samplesPerPacket = other.samplesPerPacket;
    this->seqNo = other.seqNo;
    this->timeStamp = other.timeStamp;
    this->ssrc = other.ssrc;
    this->dataLength = other.dataLength;
}

void VoipStreamPacket::parsimPack(omnetpp::cCommBuffer *b) const
{
    ::inet::FieldsChunk::parsimPack(b);
    doParsimPacking(b,this->headerLength);
    doParsimPacking(b,this->type);
    doParsimPacking(b,this->codec);
    doParsimPacking(b,this->sampleBits);
    doParsimPacking(b,this->sampleRate);
    doParsimPacking(b,this->transmitBitrate);
    doParsimPacking(b,this->samplesPerPacket);
    doParsimPacking(b,this->seqNo);
    doParsimPacking(b,this->timeStamp);
    doParsimPacking(b,this->ssrc);
    doParsimPacking(b,this->dataLength);
}

void VoipStreamPacket::parsimUnpack(omnetpp::cCommBuffer *b)
{
    ::inet::FieldsChunk::parsimUnpack(b);
    doParsimUnpacking(b,this->headerLength);
    doParsimUnpacking(b,this->type);
    doParsimUnpacking(b,this->codec);
    doParsimUnpacking(b,this->sampleBits);
    doParsimUnpacking(b,this->sampleRate);
    doParsimUnpacking(b,this->transmitBitrate);
    doParsimUnpacking(b,this->samplesPerPacket);
    doParsimUnpacking(b,this->seqNo);
    doParsimUnpacking(b,this->timeStamp);
    doParsimUnpacking(b,this->ssrc);
    doParsimUnpacking(b,this->dataLength);
}

short VoipStreamPacket::getHeaderLength() const
{
    return this->headerLength;
}

void VoipStreamPacket::setHeaderLength(short headerLength)
{
    handleChange();
    this->headerLength = headerLength;
}

VoipStreamPacketType VoipStreamPacket::getType() const
{
    return this->type;
}

void VoipStreamPacket::setType(VoipStreamPacketType type)
{
    handleChange();
    this->type = type;
}

int VoipStreamPacket::getCodec() const
{
    return this->codec;
}

void VoipStreamPacket::setCodec(int codec)
{
    handleChange();
    this->codec = codec;
}

short VoipStreamPacket::getSampleBits() const
{
    return this->sampleBits;
}

void VoipStreamPacket::setSampleBits(short sampleBits)
{
    handleChange();
    this->sampleBits = sampleBits;
}

int VoipStreamPacket::getSampleRate() const
{
    return this->sampleRate;
}

void VoipStreamPacket::setSampleRate(int sampleRate)
{
    handleChange();
    this->sampleRate = sampleRate;
}

int VoipStreamPacket::getTransmitBitrate() const
{
    return this->transmitBitrate;
}

void VoipStreamPacket::setTransmitBitrate(int transmitBitrate)
{
    handleChange();
    this->transmitBitrate = transmitBitrate;
}

int VoipStreamPacket::getSamplesPerPacket() const
{
    return this->samplesPerPacket;
}

void VoipStreamPacket::setSamplesPerPacket(int samplesPerPacket)
{
    handleChange();
    this->samplesPerPacket = samplesPerPacket;
}

uint16_t VoipStreamPacket::getSeqNo() const
{
    return this->seqNo;
}

void VoipStreamPacket::setSeqNo(uint16_t seqNo)
{
    handleChange();
    this->seqNo = seqNo;
}

uint32_t VoipStreamPacket::getTimeStamp() const
{
    return this->timeStamp;
}

void VoipStreamPacket::setTimeStamp(uint32_t timeStamp)
{
    handleChange();
    this->timeStamp = timeStamp;
}

uint32_t VoipStreamPacket::getSsrc() const
{
    return this->ssrc;
}

void VoipStreamPacket::setSsrc(uint32_t ssrc)
{
    handleChange();
    this->ssrc = ssrc;
}

uint16_t VoipStreamPacket::getDataLength() const
{
    return this->dataLength;
}

void VoipStreamPacket::setDataLength(uint16_t dataLength)
{
    handleChange();
    this->dataLength = dataLength;
}

class VoipStreamPacketDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertyNames;
    enum FieldConstants {
        FIELD_headerLength,
        FIELD_type,
        FIELD_codec,
        FIELD_sampleBits,
        FIELD_sampleRate,
        FIELD_transmitBitrate,
        FIELD_samplesPerPacket,
        FIELD_seqNo,
        FIELD_timeStamp,
        FIELD_ssrc,
        FIELD_dataLength,
    };
  public:
    VoipStreamPacketDescriptor();
    virtual ~VoipStreamPacketDescriptor();

    virtual bool doesSupport(omnetpp::cObject *obj) const override;
    virtual const char **getPropertyNames() const override;
    virtual const char *getProperty(const char *propertyName) const override;
    virtual int getFieldCount() const override;
    virtual const char *getFieldName(int field) const override;
    virtual int findField(const char *fieldName) const override;
    virtual unsigned int getFieldTypeFlags(int field) const override;
    virtual const char *getFieldTypeString(int field) const override;
    virtual const char **getFieldPropertyNames(int field) const override;
    virtual const char *getFieldProperty(int field, const char *propertyName) const override;
    virtual int getFieldArraySize(omnetpp::any_ptr object, int field) const override;
    virtual void setFieldArraySize(omnetpp::any_ptr object, int field, int size) const override;

    virtual const char *getFieldDynamicTypeString(omnetpp::any_ptr object, int field, int i) const override;
    virtual std::string getFieldValueAsString(omnetpp::any_ptr object, int field, int i) const override;
    virtual void setFieldValueAsString(omnetpp::any_ptr object, int field, int i, const char *value) const override;
    virtual omnetpp::cValue getFieldValue(omnetpp::any_ptr object, int field, int i) const override;
    virtual void setFieldValue(omnetpp::any_ptr object, int field, int i, const omnetpp::cValue& value) const override;

    virtual const char *getFieldStructName(int field) const override;
    virtual omnetpp::any_ptr getFieldStructValuePointer(omnetpp::any_ptr object, int field, int i) const override;
    virtual void setFieldStructValuePointer(omnetpp::any_ptr object, int field, int i, omnetpp::any_ptr ptr) const override;
};

Register_ClassDescriptor(VoipStreamPacketDescriptor)

VoipStreamPacketDescriptor::VoipStreamPacketDescriptor() : omnetpp::cClassDescriptor(omnetpp::opp_typename(typeid(inet::VoipStreamPacket)), "inet::FieldsChunk")
{
    propertyNames = nullptr;
}

VoipStreamPacketDescriptor::~VoipStreamPacketDescriptor()
{
    delete[] propertyNames;
}

bool VoipStreamPacketDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<VoipStreamPacket *>(obj)!=nullptr;
}

const char **VoipStreamPacketDescriptor::getPropertyNames() const
{
    if (!propertyNames) {
        static const char *names[] = {  nullptr };
        omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
        const char **baseNames = base ? base->getPropertyNames() : nullptr;
        propertyNames = mergeLists(baseNames, names);
    }
    return propertyNames;
}

const char *VoipStreamPacketDescriptor::getProperty(const char *propertyName) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    return base ? base->getProperty(propertyName) : nullptr;
}

int VoipStreamPacketDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    return base ? 11+base->getFieldCount() : 11;
}

unsigned int VoipStreamPacketDescriptor::getFieldTypeFlags(int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldTypeFlags(field);
        field -= base->getFieldCount();
    }
    static unsigned int fieldTypeFlags[] = {
        FD_ISEDITABLE,    // FIELD_headerLength
        0,    // FIELD_type
        FD_ISEDITABLE,    // FIELD_codec
        FD_ISEDITABLE,    // FIELD_sampleBits
        FD_ISEDITABLE,    // FIELD_sampleRate
        FD_ISEDITABLE,    // FIELD_transmitBitrate
        FD_ISEDITABLE,    // FIELD_samplesPerPacket
        FD_ISEDITABLE,    // FIELD_seqNo
        FD_ISEDITABLE,    // FIELD_timeStamp
        FD_ISEDITABLE,    // FIELD_ssrc
        FD_ISEDITABLE,    // FIELD_dataLength
    };
    return (field >= 0 && field < 11) ? fieldTypeFlags[field] : 0;
}

const char *VoipStreamPacketDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldName(field);
        field -= base->getFieldCount();
    }
    static const char *fieldNames[] = {
        "headerLength",
        "type",
        "codec",
        "sampleBits",
        "sampleRate",
        "transmitBitrate",
        "samplesPerPacket",
        "seqNo",
        "timeStamp",
        "ssrc",
        "dataLength",
    };
    return (field >= 0 && field < 11) ? fieldNames[field] : nullptr;
}

int VoipStreamPacketDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    int baseIndex = base ? base->getFieldCount() : 0;
    if (strcmp(fieldName, "headerLength") == 0) return baseIndex + 0;
    if (strcmp(fieldName, "type") == 0) return baseIndex + 1;
    if (strcmp(fieldName, "codec") == 0) return baseIndex + 2;
    if (strcmp(fieldName, "sampleBits") == 0) return baseIndex + 3;
    if (strcmp(fieldName, "sampleRate") == 0) return baseIndex + 4;
    if (strcmp(fieldName, "transmitBitrate") == 0) return baseIndex + 5;
    if (strcmp(fieldName, "samplesPerPacket") == 0) return baseIndex + 6;
    if (strcmp(fieldName, "seqNo") == 0) return baseIndex + 7;
    if (strcmp(fieldName, "timeStamp") == 0) return baseIndex + 8;
    if (strcmp(fieldName, "ssrc") == 0) return baseIndex + 9;
    if (strcmp(fieldName, "dataLength") == 0) return baseIndex + 10;
    return base ? base->findField(fieldName) : -1;
}

const char *VoipStreamPacketDescriptor::getFieldTypeString(int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldTypeString(field);
        field -= base->getFieldCount();
    }
    static const char *fieldTypeStrings[] = {
        "short",    // FIELD_headerLength
        "inet::VoipStreamPacketType",    // FIELD_type
        "int",    // FIELD_codec
        "short",    // FIELD_sampleBits
        "int",    // FIELD_sampleRate
        "int",    // FIELD_transmitBitrate
        "int",    // FIELD_samplesPerPacket
        "uint16_t",    // FIELD_seqNo
        "uint32_t",    // FIELD_timeStamp
        "uint32_t",    // FIELD_ssrc
        "uint16_t",    // FIELD_dataLength
    };
    return (field >= 0 && field < 11) ? fieldTypeStrings[field] : nullptr;
}

const char **VoipStreamPacketDescriptor::getFieldPropertyNames(int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldPropertyNames(field);
        field -= base->getFieldCount();
    }
    switch (field) {
        case FIELD_type: {
            static const char *names[] = { "enum",  nullptr };
            return names;
        }
        default: return nullptr;
    }
}

const char *VoipStreamPacketDescriptor::getFieldProperty(int field, const char *propertyName) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldProperty(field, propertyName);
        field -= base->getFieldCount();
    }
    switch (field) {
        case FIELD_type:
            if (!strcmp(propertyName, "enum")) return "inet::VoipStreamPacketType";
            return nullptr;
        default: return nullptr;
    }
}

int VoipStreamPacketDescriptor::getFieldArraySize(omnetpp::any_ptr object, int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldArraySize(object, field);
        field -= base->getFieldCount();
    }
    VoipStreamPacket *pp = omnetpp::fromAnyPtr<VoipStreamPacket>(object); (void)pp;
    switch (field) {
        default: return 0;
    }
}

void VoipStreamPacketDescriptor::setFieldArraySize(omnetpp::any_ptr object, int field, int size) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount()){
            base->setFieldArraySize(object, field, size);
            return;
        }
        field -= base->getFieldCount();
    }
    VoipStreamPacket *pp = omnetpp::fromAnyPtr<VoipStreamPacket>(object); (void)pp;
    switch (field) {
        default: throw omnetpp::cRuntimeError("Cannot set array size of field %d of class 'VoipStreamPacket'", field);
    }
}

const char *VoipStreamPacketDescriptor::getFieldDynamicTypeString(omnetpp::any_ptr object, int field, int i) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldDynamicTypeString(object,field,i);
        field -= base->getFieldCount();
    }
    VoipStreamPacket *pp = omnetpp::fromAnyPtr<VoipStreamPacket>(object); (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

std::string VoipStreamPacketDescriptor::getFieldValueAsString(omnetpp::any_ptr object, int field, int i) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldValueAsString(object,field,i);
        field -= base->getFieldCount();
    }
    VoipStreamPacket *pp = omnetpp::fromAnyPtr<VoipStreamPacket>(object); (void)pp;
    switch (field) {
        case FIELD_headerLength: return long2string(pp->getHeaderLength());
        case FIELD_type: return enum2string(pp->getType(), "inet::VoipStreamPacketType");
        case FIELD_codec: return long2string(pp->getCodec());
        case FIELD_sampleBits: return long2string(pp->getSampleBits());
        case FIELD_sampleRate: return long2string(pp->getSampleRate());
        case FIELD_transmitBitrate: return long2string(pp->getTransmitBitrate());
        case FIELD_samplesPerPacket: return long2string(pp->getSamplesPerPacket());
        case FIELD_seqNo: return ulong2string(pp->getSeqNo());
        case FIELD_timeStamp: return ulong2string(pp->getTimeStamp());
        case FIELD_ssrc: return ulong2string(pp->getSsrc());
        case FIELD_dataLength: return ulong2string(pp->getDataLength());
        default: return "";
    }
}

void VoipStreamPacketDescriptor::setFieldValueAsString(omnetpp::any_ptr object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount()){
            base->setFieldValueAsString(object, field, i, value);
            return;
        }
        field -= base->getFieldCount();
    }
    VoipStreamPacket *pp = omnetpp::fromAnyPtr<VoipStreamPacket>(object); (void)pp;
    switch (field) {
        case FIELD_headerLength: pp->setHeaderLength(string2long(value)); break;
        case FIELD_codec: pp->setCodec(string2long(value)); break;
        case FIELD_sampleBits: pp->setSampleBits(string2long(value)); break;
        case FIELD_sampleRate: pp->setSampleRate(string2long(value)); break;
        case FIELD_transmitBitrate: pp->setTransmitBitrate(string2long(value)); break;
        case FIELD_samplesPerPacket: pp->setSamplesPerPacket(string2long(value)); break;
        case FIELD_seqNo: pp->setSeqNo(string2ulong(value)); break;
        case FIELD_timeStamp: pp->setTimeStamp(string2ulong(value)); break;
        case FIELD_ssrc: pp->setSsrc(string2ulong(value)); break;
        case FIELD_dataLength: pp->setDataLength(string2ulong(value)); break;
        default: throw omnetpp::cRuntimeError("Cannot set field %d of class 'VoipStreamPacket'", field);
    }
}

omnetpp::cValue VoipStreamPacketDescriptor::getFieldValue(omnetpp::any_ptr object, int field, int i) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldValue(object,field,i);
        field -= base->getFieldCount();
    }
    VoipStreamPacket *pp = omnetpp::fromAnyPtr<VoipStreamPacket>(object); (void)pp;
    switch (field) {
        case FIELD_headerLength: return pp->getHeaderLength();
        case FIELD_type: return static_cast<int>(pp->getType());
        case FIELD_codec: return pp->getCodec();
        case FIELD_sampleBits: return pp->getSampleBits();
        case FIELD_sampleRate: return pp->getSampleRate();
        case FIELD_transmitBitrate: return pp->getTransmitBitrate();
        case FIELD_samplesPerPacket: return pp->getSamplesPerPacket();
        case FIELD_seqNo: return (omnetpp::intval_t)(pp->getSeqNo());
        case FIELD_timeStamp: return (omnetpp::intval_t)(pp->getTimeStamp());
        case FIELD_ssrc: return (omnetpp::intval_t)(pp->getSsrc());
        case FIELD_dataLength: return (omnetpp::intval_t)(pp->getDataLength());
        default: throw omnetpp::cRuntimeError("Cannot return field %d of class 'VoipStreamPacket' as cValue -- field index out of range?", field);
    }
}

void VoipStreamPacketDescriptor::setFieldValue(omnetpp::any_ptr object, int field, int i, const omnetpp::cValue& value) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount()){
            base->setFieldValue(object, field, i, value);
            return;
        }
        field -= base->getFieldCount();
    }
    VoipStreamPacket *pp = omnetpp::fromAnyPtr<VoipStreamPacket>(object); (void)pp;
    switch (field) {
        case FIELD_headerLength: pp->setHeaderLength(omnetpp::checked_int_cast<short>(value.intValue())); break;
        case FIELD_codec: pp->setCodec(omnetpp::checked_int_cast<int>(value.intValue())); break;
        case FIELD_sampleBits: pp->setSampleBits(omnetpp::checked_int_cast<short>(value.intValue())); break;
        case FIELD_sampleRate: pp->setSampleRate(omnetpp::checked_int_cast<int>(value.intValue())); break;
        case FIELD_transmitBitrate: pp->setTransmitBitrate(omnetpp::checked_int_cast<int>(value.intValue())); break;
        case FIELD_samplesPerPacket: pp->setSamplesPerPacket(omnetpp::checked_int_cast<int>(value.intValue())); break;
        case FIELD_seqNo: pp->setSeqNo(omnetpp::checked_int_cast<uint16_t>(value.intValue())); break;
        case FIELD_timeStamp: pp->setTimeStamp(omnetpp::checked_int_cast<uint32_t>(value.intValue())); break;
        case FIELD_ssrc: pp->setSsrc(omnetpp::checked_int_cast<uint32_t>(value.intValue())); break;
        case FIELD_dataLength: pp->setDataLength(omnetpp::checked_int_cast<uint16_t>(value.intValue())); break;
        default: throw omnetpp::cRuntimeError("Cannot set field %d of class 'VoipStreamPacket'", field);
    }
}

const char *VoipStreamPacketDescriptor::getFieldStructName(int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldStructName(field);
        field -= base->getFieldCount();
    }
    switch (field) {
        default: return nullptr;
    };
}

omnetpp::any_ptr VoipStreamPacketDescriptor::getFieldStructValuePointer(omnetpp::any_ptr object, int field, int i) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldStructValuePointer(object, field, i);
        field -= base->getFieldCount();
    }
    VoipStreamPacket *pp = omnetpp::fromAnyPtr<VoipStreamPacket>(object); (void)pp;
    switch (field) {
        default: return omnetpp::any_ptr(nullptr);
    }
}

void VoipStreamPacketDescriptor::setFieldStructValuePointer(omnetpp::any_ptr object, int field, int i, omnetpp::any_ptr ptr) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount()){
            base->setFieldStructValuePointer(object, field, i, ptr);
            return;
        }
        field -= base->getFieldCount();
    }
    VoipStreamPacket *pp = omnetpp::fromAnyPtr<VoipStreamPacket>(object); (void)pp;
    switch (field) {
        default: throw omnetpp::cRuntimeError("Cannot set field %d of class 'VoipStreamPacket'", field);
    }
}

}  // namespace inet

namespace omnetpp {

}  // namespace omnetpp

