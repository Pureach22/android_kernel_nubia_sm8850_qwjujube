__int64 __fastcall hif_pci_ce_send_done(
        __int64 a1,
        __int64 a2,
        __int64 a3,
        __int64 a4,
        int a5,
        unsigned int a6,
        int a7,
        int a8,
        unsigned int a9)
{
  __int64 v10; // x8
  unsigned __int64 StatusReg; // x22
  __int64 v13; // x1
  __int64 v14; // x0
  void (__fastcall *v15)(__int64, __int64, __int64, __int64); // x8
  __int64 v16; // x2
  __int64 v17; // x3
  __int64 v18; // x8
  __int64 result; // x0
  int v20; // [xsp+10h] [xbp-30h] BYREF
  int v21; // [xsp+14h] [xbp-2Ch] BYREF
  unsigned int v22; // [xsp+18h] [xbp-28h] BYREF
  int v23; // [xsp+1Ch] [xbp-24h] BYREF
  __int64 v24; // [xsp+20h] [xbp-20h] BYREF
  __int64 v25; // [xsp+28h] [xbp-18h] BYREF
  _QWORD v26[2]; // [xsp+30h] [xbp-10h] BYREF

  v10 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  StatusReg = _ReadStatusReg(SP_EL0);
  v26[1] = v10;
  v25 = a3;
  v26[0] = a2;
  v24 = a4;
  v22 = a6;
  v23 = a5;
  v20 = a8;
  v21 = a7;
  do
  {
    v13 = v25;
    if ( v25 != 3469655791LL )
    {
      v14 = *(_QWORD *)(a2 + 88);
      v15 = *(void (__fastcall **)(__int64, __int64, __int64, __int64))(a2 + 96);
      v16 = v22;
      v17 = a9;
      if ( *((_DWORD *)v15 - 1) != 1016259708 )
        __break(0x8228u);
      v15(v14, v13, v16, v17);
    }
    if ( (_ReadStatusReg(DAIF) & 0x80) != 0
      || (*(_DWORD *)(StatusReg + 16) & 0xF0000) != 0
      || (*(_DWORD *)(StatusReg + 16) & 0xFF00) != 0 )
    {
      raw_spin_lock(a2 + 56);
      v18 = *(_QWORD *)(a2 + 64);
    }
    else
    {
      raw_spin_lock_bh(a2 + 56);
      v18 = *(_QWORD *)(a2 + 64) | 1LL;
      *(_QWORD *)(a2 + 64) = v18;
    }
    ++*(_DWORD *)(a2 + 72);
    if ( (v18 & 1) != 0 )
    {
      *(_QWORD *)(a2 + 64) = v18 & 0xFFFFFFFFFFFFFFFELL;
      raw_spin_unlock_bh(a2 + 56);
    }
    else
    {
      raw_spin_unlock(a2 + 56);
    }
    result = ce_completed_send_next(a1, v26, &v25, &v24, &v23, &v22, &v21, &v20, &a9);
  }
  while ( !(_DWORD)result );
  _ReadStatusReg(SP_EL0);
  return result;
}
