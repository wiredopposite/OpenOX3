#pragma once

#include "krnl/krnl.h"

#ifdef __cplusplus
extern "C" {
#endif

// Source: Cxbx-Reloaded
/* Function pointers which point to all the kernel crypto functions. Used by PCRYPTO_VECTOR. */
typedef VOID(XBOXAPI *pfXcSHAInit)(PUCHAR pbSHAContext);
typedef VOID(XBOXAPI *pfXcSHAUpdate)(PUCHAR pbSHAContext, PUCHAR pbInput, ULONG dwInputLength);
typedef VOID(XBOXAPI *pfXcSHAFinal)(PUCHAR pbSHAContext, PUCHAR pbDigest);
typedef VOID(XBOXAPI *pfXcRC4Key)(PUCHAR pbKeyStruct, ULONG dwKeyLength, PUCHAR pbKey);
typedef VOID(XBOXAPI *pfXcRC4Crypt)(PUCHAR pbKeyStruct, ULONG dwInputLength, PUCHAR pbInput);
typedef VOID(XBOXAPI *pfXcHMAC)(PBYTE pbKeyMaterial, ULONG cbKeyMaterial, PBYTE pbData, ULONG cbData, PBYTE pbData2, ULONG cbData2, PBYTE HmacData);
typedef ULONG(XBOXAPI *pfXcPKEncPublic)(PUCHAR pbPubKey, PUCHAR pbInput, PUCHAR pbOutput);
typedef ULONG(XBOXAPI *pfXcPKDecPrivate)(PUCHAR pbPrvKey, PUCHAR pbInput, PUCHAR pbOutput);
typedef ULONG(XBOXAPI *pfXcPKGetKeyLen)(PUCHAR pbPubKey);
typedef BOOLEAN(XBOXAPI *pfXcVerifyPKCS1Signature)(PUCHAR pbSig, PUCHAR pbPubKey, PUCHAR pbDigest);
typedef ULONG(XBOXAPI *pfXcModExp)(LPDWORD pA, LPDWORD pB, LPDWORD pC, LPDWORD pD, ULONG dwN);
typedef VOID(XBOXAPI *pfXcDESKeyParity)(PUCHAR pbKey, ULONG dwKeyLength);
typedef VOID(XBOXAPI *pfXcKeyTable)(ULONG dwCipher, PUCHAR pbKeyTable, PUCHAR pbKey);
typedef VOID(XBOXAPI *pfXcBlockCrypt)(ULONG dwCipher, PUCHAR pbOutput, PUCHAR pbInput, PUCHAR pbKeyTable, ULONG dwOp);
typedef VOID(XBOXAPI *pfXcBlockCryptCBC)(ULONG dwCipher, ULONG dwInputLength, PUCHAR pbOutput, PUCHAR pbInput, PUCHAR pbKeyTable, ULONG dwOp, PUCHAR pbFeedback);
typedef ULONG(XBOXAPI *pfXcCryptService)(ULONG dwOp, PVOID pArgs);

typedef struct _CRYPTO_VECTOR {
	pfXcSHAInit pXcSHAInit;
	pfXcSHAUpdate pXcSHAUpdate;
	pfXcSHAFinal pXcSHAFinal;
	pfXcRC4Key pXcRC4Key;
	pfXcRC4Crypt pXcRC4Crypt;
	pfXcHMAC pXcHMAC;
	pfXcPKEncPublic pXcPKEncPublic;
	pfXcPKDecPrivate pXcPKDecPrivate;
	pfXcPKGetKeyLen pXcPKGetKeyLen;
	pfXcVerifyPKCS1Signature pXcVerifyPKCS1Signature;
	pfXcModExp pXcModExp;
	pfXcDESKeyParity pXcDESKeyParity;
	pfXcKeyTable pXcKeyTable;
	pfXcBlockCrypt pXcBlockCrypt;
	pfXcBlockCryptCBC pXcBlockCryptCBC;
	pfXcCryptService pXcCryptService;
} CRYPTO_VECTOR, *PCRYPTO_VECTOR;

EXPORTNUM(335) DLLEXPORT VOID XBOXAPI XcSHAInit
(
	PUCHAR pbSHAContext
);

EXPORTNUM(336) DLLEXPORT VOID XBOXAPI XcSHAUpdate
(
	PUCHAR pbSHAContext,
	PUCHAR pbInput,
	ULONG dwInputLength
);

EXPORTNUM(337) DLLEXPORT VOID XBOXAPI XcSHAFinal
(
	PUCHAR pbSHAContext,
	PUCHAR pbDigest
);

// Disassembly: _XcHMAC@28, 0x800f6162
// Disassembly: _XcRC4Key@12, 0x80040052 — thunk through updatedCryptoVector.pXcRC4Key
EXPORTNUM(338) DLLEXPORT VOID XBOXAPI XcRC4Key
(
	PUCHAR pbKeyStruct,
	ULONG dwKeyLength,
	PUCHAR pbKey
);

// Disassembly: _XcRC4Crypt@12, 0x8004005c — thunk through updatedCryptoVector.pXcRC4Crypt
EXPORTNUM(339) DLLEXPORT VOID XBOXAPI XcRC4Crypt
(
	PUCHAR pbKeyStruct,
	ULONG dwInputLength,
	PUCHAR pbInput
);

EXPORTNUM(340) DLLEXPORT VOID XBOXAPI XcHMAC
(
	PBYTE pbKeyMaterial,
	ULONG cbKeyMaterial,
	PBYTE pbData,
	ULONG cbData,
	PBYTE pbData2,
	ULONG cbData2,
	PBYTE HmacData
);

EXPORTNUM(341) DLLEXPORT ULONG XBOXAPI XcPKEncPublic
(
	PUCHAR pbPubKey,
	PUCHAR pbInput,
	PUCHAR pbOutput
);

EXPORTNUM(342) DLLEXPORT ULONG XBOXAPI XcPKDecPrivate
(
	PUCHAR pbPrvKey,
	PUCHAR pbInput,
	PUCHAR pbOutput
);

EXPORTNUM(343) DLLEXPORT ULONG XBOXAPI XcPKGetKeyLen
(
	PUCHAR pbPubKey
);

EXPORTNUM(344) DLLEXPORT BOOLEAN XBOXAPI XcVerifyPKCS1Signature
(
	PUCHAR pbSig,
	PUCHAR pbPubKey,
	PUCHAR pbDigest
);

EXPORTNUM(345) DLLEXPORT ULONG XBOXAPI XcModExp
(
	LPDWORD pA,
	LPDWORD pB,
	LPDWORD pC,
	LPDWORD pD,
	ULONG dwN
);

EXPORTNUM(346) DLLEXPORT VOID XBOXAPI XcDESKeyParity
(
	PUCHAR pbKey,
	ULONG dwKeyLength
);

EXPORTNUM(347) DLLEXPORT VOID XBOXAPI XcKeyTable
(
	ULONG dwCipher,
	PUCHAR pbKeyTable,
	PUCHAR pbKey
);

EXPORTNUM(348) DLLEXPORT VOID XBOXAPI XcBlockCrypt
(
	ULONG dwCipher,
	PUCHAR pbOutput,
	PUCHAR pbInput,
	PUCHAR pbKeyTable,
	ULONG dwOp
);

EXPORTNUM(349) DLLEXPORT VOID XBOXAPI XcBlockCryptCBC
(
	ULONG dwCipher,
	ULONG dwInputLength,
	PUCHAR pbOutput,
	PUCHAR pbInput,
	PUCHAR pbKeyTable,
	ULONG dwOp,
	PUCHAR pbFeedback
);

EXPORTNUM(350) DLLEXPORT ULONG XBOXAPI XcCryptService
(
	ULONG dwOp,
	PVOID pArgs
);

EXPORTNUM(351) DLLEXPORT VOID XBOXAPI XcUpdateCrypto
(
	PCRYPTO_VECTOR pNewVector,
	PCRYPTO_VECTOR pROMVector
);

#ifdef __cplusplus
}
#endif
