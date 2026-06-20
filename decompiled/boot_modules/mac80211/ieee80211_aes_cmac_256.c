__int64 __fastcall ieee80211_aes_cmac_256(__int64 a1, _WORD *a2, __int64 a3, int a4, __int64 a5)
{
  char v10; // w8
  void (__fastcall *v11)(_QWORD); // x8
  int v12; // w8
  __int64 result; // x0
  _QWORD v14[48]; // [xsp+0h] [xbp-180h] BYREF

  v14[47] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  memset(&v14[1], 0, 0x170u);
  v10 = *(_BYTE *)(a1 + 12);
  v14[0] = a1;
  if ( (v10 & 1) == 0 )
  {
    v11 = *(void (__fastcall **)(_QWORD))(*(_QWORD *)(a1 + 32) - 112LL);
    if ( *((_DWORD *)v11 - 1) != 1272602849 )
      __break(0x8228u);
    v11(v14);
  }
  crypto_shash_update(v14, a2, 20);
  if ( (*a2 & 0xFC) == 0x80 )
  {
    crypto_shash_update(v14, &zero, 8);
    a3 += 8;
    v12 = -24;
  }
  else
  {
    v12 = -16;
  }
  crypto_shash_update(v14, a3, (unsigned int)(v12 + a4));
  result = crypto_shash_finup(v14, &zero, 16, a5);
  _ReadStatusReg(SP_EL0);
  return result;
}
