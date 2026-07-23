#pragma once

#include "krnl/krnl.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef struct _PCI_HEADER_TYPE_0 {
    ULONG   BaseAddress[6];
    ULONG   CIS;
    USHORT  SubVendorID;
    USHORT  SubSystemID;
    ULONG   ROMBaseAddress;
    UCHAR   CapabilitiesPtr;
    UCHAR   Reserved1[3];
    ULONG   Reserved2;
    UCHAR   InterruptLine;
    UCHAR   InterruptPin;
    UCHAR   MinimumGrant;
    UCHAR   MaximumLatency;
} PCI_HEADER_TYPE_0, *PPCI_HEADER_TYPE_0;
STATIC_ASSERT(sizeof(PCI_HEADER_TYPE_0) == 0x30, "PCI_HEADER_TYPE_0 size mismatch");

typedef struct _PCI_HEADER_TYPE_1 {
    ULONG   BaseAddresses[2];
    UCHAR	PrimaryBus;
    UCHAR	SecondaryBus;
    UCHAR	SubordinateBus;
    UCHAR	SecondaryLatency;
    UCHAR	IOBase;
    UCHAR	IOLimit;
    USHORT	SecondaryStatus;
    USHORT	MemoryBase;
    USHORT	MemoryLimit;
    USHORT	PrefetchBase;
    USHORT	PrefetchLimit;
    ULONG	PrefetchBaseUpper32;
    ULONG	PrefetchLimitUpper32;
    USHORT	IOBaseUpper16;
    USHORT	IOLimitUpper16;
    UCHAR	CapabilitiesPtr;
    UCHAR   Reserved1[3];
    ULONG	ROMBaseAddress;
    UCHAR	InterruptLine;
    UCHAR	InterruptPin;
    USHORT	BridgeControl;
} PCI_HEADER_TYPE_1, *PPCI_HEADER_TYPE_1;
STATIC_ASSERT(sizeof(PCI_HEADER_TYPE_1) == 0x30, "PCI_HEADER_TYPE_1 size mismatch");

typedef struct _PCI_HEADER_TYPE_2 {
    ULONG	SocketRegistersBaseAddress;
    UCHAR	CapabilitiesPtr;
    UCHAR	Reserved;
    USHORT	SecondaryStatus;
    UCHAR	PrimaryBus;
    UCHAR	SecondaryBus;
    UCHAR	SubordinateBus;
    UCHAR	SecondaryLatency;
    struct {
        ULONG Base;
        ULONG Limit;
    } Range[4];
    UCHAR	InterruptLine;
    UCHAR	InterruptPin;
    USHORT	BridgeControl;
} PCI_HEADER_TYPE_2, *PPCI_HEADER_TYPE_2;
STATIC_ASSERT(sizeof(PCI_HEADER_TYPE_2) == 0x30, "PCI_HEADER_TYPE_2 size mismatch");

typedef struct _PCI_COMMON_CONFIG {
    USHORT  VendorID;
    USHORT  DeviceID;
    USHORT  Command;
    USHORT  Status;
    UCHAR   RevisionID;
    UCHAR   ProgIf;
    UCHAR   SubClass;
    UCHAR   BaseClass;
    UCHAR   CacheLineSize;
    UCHAR   LatencyTimer;
    UCHAR   HeaderType;
    UCHAR   BIST;
    union {
        PCI_HEADER_TYPE_0 type0;
        PCI_HEADER_TYPE_1 type1;
        PCI_HEADER_TYPE_2 type2;
    } u;
    UCHAR   DeviceSpecific[192];
} PCI_COMMON_CONFIG, *PPCI_COMMON_CONFIG;
STATIC_ASSERT(sizeof(PCI_COMMON_CONFIG) == 0x100, "PCI_COMMON_CONFIG size mismatch");

typedef union _PCI_SLOT_NUMBER {
    ULONG ul;
    struct {
        ULONG Device : 5;
        ULONG Function : 3;
        ULONG Reserved : 24;
    };
} PCI_SLOT_NUMBER, *PPCI_SLOT_NUMBER;
STATIC_ASSERT(sizeof(PCI_SLOT_NUMBER) == 4, "PCI_SLOT_NUMBER size mismatch");

#ifdef __cplusplus
}
#endif
