__int64 __fastcall cqhci_crypto_keyslot_evict(__int64 a1, __int64 a2, __int64 a3)
{
  __int64 v3; // x0
  __int64 result; // x0
  _QWORD v5[17]; // [xsp+8h] [xbp-88h] BYREF

  v5[16] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v3 = *(_QWORD *)(a1 - 16);
  memset(v5, 0, 128);
  result = cqhci_crypto_program_key(v3, v5, a3);
  _ReadStatusReg(SP_EL0);
  return result;
}
