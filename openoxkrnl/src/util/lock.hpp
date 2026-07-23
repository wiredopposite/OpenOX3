// #pragma once

// #include "krnl/krnl.h"
// #include "ex/ex.hpp"
// #include "ke/ke.hpp"
// #include "rtl/rtl.hpp"
// #include "krnl/helpers.hpp"
// #include <assert.h>

// namespace Lock {

// class HIrqlToDpc {
// public: 
//     explicit HIrqlToDpc() 
//         : OldIrql(KeRaiseIrqlToDpcLevel()), Locked(TRUE) { }

//     ~HIrqlToDpc() 
//     {
//         Unlock();
//     }

//     inline VOID Lock()
//     {
//         if (!Locked)
//         {
//             Locked = TRUE;
//             OldIrql = KeRaiseIrqlToDpcLevel();
//         }
//     }

//     inline VOID Unlock() 
//     {
//         if (Locked) {
//             Locked = FALSE;
//             KfLowerIrql(OldIrql);
//         }
//     }

//     inline BOOLEAN IsLocked() const
//     {
//         return Locked;
//     }

//     HIrqlToDpc(const HIrqlToDpc&) = delete;
//     HIrqlToDpc& operator=(const HIrqlToDpc&) = delete;

//     HIrqlToDpc(HIrqlToDpc&&) = delete;
//     HIrqlToDpc& operator=(HIrqlToDpc&&) = delete;

// private:
//     KIRQL OldIrql;
//     BOOLEAN Locked;
// };

// class LIrqlToDpc {
// public: 
//     explicit LIrqlToDpc() 
//         : OldIrql(KeRaiseIrqlToDpcLevel()) { }

//     ~LIrqlToDpc() 
//     {
//         KfLowerIrql(OldIrql);
//     }

//     LIrqlToDpc(const LIrqlToDpc&) = delete;
//     LIrqlToDpc& operator=(const LIrqlToDpc&) = delete;

//     LIrqlToDpc(LIrqlToDpc&&) = delete;
//     LIrqlToDpc& operator=(LIrqlToDpc&&) = delete;

// private:
//     KIRQL OldIrql;
// };

// class LCriticalSection {
// public:
//     explicit LCriticalSection(PRTL_CRITICAL_SECTION CriticalSection) 
//         : Cs(CriticalSection) 
//     {
//         assert(Cs);
//         RtlEnterCriticalSectionAndRegion(Cs);
//     }

//     ~LCriticalSection() 
//     {
//         RtlLeaveCriticalSectionAndRegion(Cs);
//     }

//     LCriticalSection(const LCriticalSection&) = delete;
//     LCriticalSection& operator=(const LCriticalSection&) = delete;

//     LCriticalSection(LCriticalSection&&) = delete;
//     LCriticalSection& operator=(LCriticalSection&&) = delete;

// private:
//     PRTL_CRITICAL_SECTION Cs;
// };

// class HCriticalSection {
// public:
//     explicit HCriticalSection(PRTL_CRITICAL_SECTION CriticalSection) 
//         : Cs(CriticalSection), Locked(TRUE)
//     {
//         assert(Cs);
//         RtlEnterCriticalSectionAndRegion(Cs);
//     }

//     ~HCriticalSection() 
//     {
//         Unlock();
//     }

//     inline VOID Lock()
//     {
//         if (!Locked) {
//             Locked = TRUE;
//             RtlEnterCriticalSectionAndRegion(Cs);
//         }
//     }

//     inline VOID Unlock()
//     {
//         if (Locked) {
//             Locked = FALSE;
//             RtlLeaveCriticalSectionAndRegion(Cs);
//         }
//     }

//     inline BOOLEAN IsLocked() const
//     {
//         return Locked;
//     }

//     HCriticalSection(const HCriticalSection&) = delete;
//     HCriticalSection& operator=(const HCriticalSection&) = delete;

//     HCriticalSection(HCriticalSection&&) = delete;
//     HCriticalSection& operator=(HCriticalSection&&) = delete;

// private:
//     PRTL_CRITICAL_SECTION Cs;
//     BOOLEAN Locked;
// };

// class LInterrupts {
// public:
//     explicit LInterrupts()
//     {
//         __asm cli
//     }

//     ~LInterrupts() 
//     {
//         __asm sti
//     }

//     LInterrupts(const LInterrupts&) = delete;
//     LInterrupts& operator=(const LInterrupts&) = delete;

//     LInterrupts(LInterrupts&&) = delete;
//     LInterrupts& operator=(LInterrupts&&) = delete;
// };

// class HInterrupts {
// public:
//     explicit HInterrupts()
//         : Locked(TRUE)
//     {
//         __asm cli
//     }

//     ~HInterrupts() {
//         __asm sti
//     }

//     inline VOID Disable()
//     {
//         if (!Locked) {
//             Locked = TRUE;
//             __asm cli
//         }
//     }

//     inline VOID Enable()
//     {
//         if (Locked) {
//             Locked = FALSE;
//             __asm sti
//         }
//     }

//     inline BOOLEAN IsLocked() const
//     {
//         return Locked;
//     }

//     HInterrupts(const HInterrupts&) = delete;
//     HInterrupts& operator=(const HInterrupts&) = delete;

//     HInterrupts(HInterrupts&&) = delete;
//     HInterrupts& operator=(HInterrupts&&) = delete;

// private:
//     BOOLEAN Locked;
// };

// static inline DWORD SaveAndDisableInterrupts()
// {
//     DWORD EFlags;

//     __asm {
//         pushfd
//         cli
//         pop EFlags
//     }

//     return EFlags;
// }

// static inline VOID RestoreInterrupts(DWORD EFlags)
// {
//     __asm {
//         push EFlags
//         popfd
//     }
// }

// class LSaveInterrupts {
// public:
//     explicit LSaveInterrupts()
//         : EFlags(SaveAndDisableInterrupts()) {}

//     ~LSaveInterrupts() 
//     {
//         RestoreInterrupts(EFlags);
//     }

//     LSaveInterrupts(const LSaveInterrupts&) = delete;
//     LSaveInterrupts& operator=(const LSaveInterrupts&) = delete;

//     LSaveInterrupts(LSaveInterrupts&&) = delete;
//     LSaveInterrupts& operator=(LSaveInterrupts&&) = delete;

// private:
//     DWORD EFlags;
// };

// class HSaveInterrupts {
// public:
//     explicit HSaveInterrupts()
//         : Saved(TRUE), EFlags(SaveAndDisableInterrupts()) {}

//     ~HSaveInterrupts() {
//         Restore();
//     }

//     inline VOID Save()
//     {
//         if (!Saved) {
//             Saved = TRUE;
//             EFlags = SaveAndDisableInterrupts();
//         }
//     }

//     inline VOID Restore()
//     {
//         if (Saved) {
//             Saved = FALSE;
//             RestoreInterrupts(EFlags);
//         }
//     }

//     inline BOOLEAN IsSaved() const
//     {
//         return Saved;
//     }

//     HSaveInterrupts(const HSaveInterrupts&) = delete;
//     HSaveInterrupts& operator=(const HSaveInterrupts&) = delete;

//     HSaveInterrupts(HSaveInterrupts&&) = delete;
//     HSaveInterrupts& operator=(HSaveInterrupts&&) = delete;

// private:
//     DWORD EFlags;
//     BOOLEAN Saved;
// };

// }