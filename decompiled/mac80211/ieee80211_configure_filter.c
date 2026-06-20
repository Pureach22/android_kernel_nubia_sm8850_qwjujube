__int64 __fastcall ieee80211_configure_filter(__int64 a1)
{
  int v2; // w21
  unsigned int v3; // w22
  __int64 v4; // x2
  __int64 (__fastcall *v5)(__int64, __int64, __int64); // x8
  __int64 v6; // x20
  _DWORD *v7; // x8
  __int64 result; // x0
  int v9; // w8
  int v10; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v11; // [xsp+8h] [xbp-8h]

  v11 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v10 = 0;
  if ( *(_DWORD *)(a1 + 2528) )
  {
    v2 = 2;
    v10 = 2;
    if ( !*(_DWORD *)(a1 + 1320) )
      goto LABEL_5;
LABEL_7:
    v2 |= 0x10u;
    v10 = v2;
    goto LABEL_8;
  }
  v2 = 0;
  if ( *(_DWORD *)(a1 + 1320) )
    goto LABEL_7;
LABEL_5:
  if ( (*(_QWORD *)(a1 + 4696) & 1) != 0 || (*(_QWORD *)(a1 + 4696) & 4) != 0 )
    goto LABEL_7;
LABEL_8:
  if ( *(_DWORD *)(a1 + 1348) || *(_BYTE *)(a1 + 1352) == 1 )
  {
    v2 |= 0x100u;
    v10 = v2;
  }
  if ( *(_DWORD *)(a1 + 1328) )
  {
    v2 |= 4u;
    v10 = v2;
  }
  if ( *(_DWORD *)(a1 + 1332) )
  {
    v2 |= 8u;
    v10 = v2;
  }
  if ( *(_DWORD *)(a1 + 1336) )
  {
    v2 |= 0x20u;
    v10 = v2;
  }
  if ( *(_DWORD *)(a1 + 1340) )
  {
    v2 |= 0x40u;
    v10 = v2;
  }
  if ( *(_DWORD *)(a1 + 1344) )
  {
    v2 |= 0x80u;
    v10 = v2;
  }
  if ( *(_BYTE *)(a1 + 1353) == 1 )
  {
    v2 |= 0x200u;
    v10 = v2;
  }
  raw_spin_lock_bh(a1 + 1404);
  v3 = *(_DWORD *)(a1 + 1356);
  v4 = *(unsigned int *)(a1 + 1448);
  v5 = *(__int64 (__fastcall **)(__int64, __int64, __int64))(*(_QWORD *)(a1 + 464) + 120LL);
  if ( v5 )
  {
    if ( *((_DWORD *)v5 - 1) != 780091347 )
      __break(0x8228u);
    v6 = v5(a1, a1 + 1432, v4);
  }
  else
  {
    v6 = 0;
  }
  raw_spin_unlock_bh(a1 + 1404);
  v10 |= 0x80000000;
  v7 = *(_DWORD **)(*(_QWORD *)(a1 + 464) + 128LL);
  if ( *(v7 - 1) != -35991898 )
    __break(0x8228u);
  result = ((__int64 (__fastcall *)(__int64, _QWORD, int *, __int64))v7)(a1, v2 ^ v3, &v10, v6);
  v9 = v10;
  if ( v10 < 0 )
  {
    __break(0x800u);
    v9 = v10;
  }
  *(_DWORD *)(a1 + 1356) = v9 & 0x7FFFFFFF;
  _ReadStatusReg(SP_EL0);
  return result;
}
