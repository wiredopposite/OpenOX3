#pragma once

#include <win32types/ntdef.h>

namespace List {

static inline void InitializeHead(PLIST_ENTRY pListHead)
{
	pListHead->Flink = pListHead->Blink = pListHead;
}

static inline BOOLEAN IsEmpty(PLIST_ENTRY pListHead)
{
	return (pListHead->Flink == pListHead);
}

static inline void InsertTail(PLIST_ENTRY pListHead, PLIST_ENTRY pEntry)
{
	PLIST_ENTRY _EX_ListHead = pListHead;
	PLIST_ENTRY _EX_Blink = _EX_ListHead->Blink;

	pEntry->Flink = _EX_ListHead;
	pEntry->Blink = _EX_Blink;
	_EX_Blink->Flink = pEntry;
	_EX_ListHead->Blink = pEntry;
}

static inline void InsertHead(PLIST_ENTRY pListHead, PLIST_ENTRY pEntry)
{
	PLIST_ENTRY _EX_ListHead = pListHead;
	PLIST_ENTRY _EX_Flink = _EX_ListHead->Flink;

	pEntry->Flink = _EX_Flink;
	pEntry->Blink = _EX_ListHead;
	_EX_Flink->Blink = pEntry;
	_EX_ListHead->Flink = pEntry;
}

static inline void RemoveEntry(PLIST_ENTRY pEntry)
{
	PLIST_ENTRY _EX_Flink = pEntry->Flink;
	PLIST_ENTRY _EX_Blink = pEntry->Blink;
	_EX_Blink->Flink = _EX_Flink;
	_EX_Flink->Blink = _EX_Blink;
}

static inline PLIST_ENTRY RemoveTail(PLIST_ENTRY pListHead)
{
	PLIST_ENTRY pList = pListHead->Blink;
	RemoveEntry(pList);
	return pList;
}

static inline PLIST_ENTRY RemoveHead(PLIST_ENTRY pListHead)
{
	PLIST_ENTRY pList = pListHead->Flink;
	RemoveEntry(pList);
	return pList;
}

}
