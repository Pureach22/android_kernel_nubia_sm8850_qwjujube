__int64 __fastcall ieee80211_tkip_decrypt_data(
        __int64 a1,
        __int64 a2,
        unsigned __int8 *a3,
        unsigned __int64 a4,
        unsigned __int16 *a5,
        __int64 a6,
        int a7,
        unsigned int a8,
        unsigned int *a9,
        _WORD *a10)
{
  unsigned __int64 v10; // x21
  unsigned int v11; // w8
  __int64 result; // x0
  unsigned int v13; // w19
  __int64 v14; // x23
  unsigned int v15; // w8
  unsigned int v17; // w20
  unsigned int v18; // w9
  __int64 v20; // x25
  __int64 v21; // x25
  _QWORD v22[3]; // [xsp+8h] [xbp-18h] BYREF

  v22[2] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v22[0] = 0;
  v22[1] = 0;
  if ( a8 >= 0x11 )
    __break(0x5512u);
  v10 = a4 - 12;
  if ( a4 < 0xC || (v11 = a3[3], (v11 & 0x20) == 0) )
  {
    result = 0xFFFFFFFFLL;
    goto LABEL_5;
  }
  if ( *(char *)(a2 + 551) != v11 >> 6 )
  {
    result = 4294967294LL;
    goto LABEL_5;
  }
  v13 = *((_DWORD *)a3 + 1);
  v14 = a2 + 28LL * a8;
  v15 = *(_DWORD *)(v14 + 92);
  if ( v13 < v15 )
  {
LABEL_8:
    result = 4294967293LL;
    goto LABEL_5;
  }
  v17 = a3[2] | (*a3 << 8);
  if ( v13 != v15 )
    goto LABEL_11;
  v18 = *(unsigned __int16 *)(v14 + 96);
  if ( v17 < v18 )
    goto LABEL_8;
  if ( v17 != v18 || (result = 4294967293LL, !v13) && !*(_WORD *)(v14 + 96) && !*(_DWORD *)(v14 + 88) )
  {
LABEL_11:
    if ( a7 )
    {
      *(_DWORD *)(v14 + 88) = 2;
LABEL_13:
      result = 0;
      *a9 = v13;
      *a10 = v17;
      goto LABEL_5;
    }
    if ( v13 != v15 || !*(_DWORD *)(v14 + 88) )
    {
      v20 = a2;
      tkip_mixing_phase1(a2 + 556, v14 + 72, a5, v13);
      a2 = v20;
    }
    if ( *(_QWORD *)(*(_QWORD *)(*(_QWORD *)a2 + 464LL) + 160LL)
      && (*(_BYTE *)(a2 + 40) & 1) != 0
      && *(_DWORD *)(v14 + 88) != 2 )
    {
      v21 = a2;
      drv_update_tkip_key();
      a2 = v21;
      *(_DWORD *)(v14 + 88) = 2;
    }
    tkip_mixing_phase2((unsigned __int16 *)(a2 + 556), (unsigned __int16 *)(v14 + 72), v17, (__int64)v22);
    result = ieee80211_wep_decrypt_data(a1, v22, 16, a3 + 8, v10);
    if ( !(_DWORD)result )
      goto LABEL_13;
  }
LABEL_5:
  _ReadStatusReg(SP_EL0);
  return result;
}
