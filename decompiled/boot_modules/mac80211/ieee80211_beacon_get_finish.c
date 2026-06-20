__int64 __fastcall ieee80211_beacon_get_finish(
        __int64 a1,
        __int64 a2,
        __int64 a3,
        __int64 a4,
        __int64 a5,
        __int64 a6,
        unsigned int **a7,
        __int16 a8)
{
  int v11; // w9
  int v12; // w10
  __int64 v13; // x8
  int v14; // w10
  __int64 v15; // x9
  __int64 v16; // x8
  __int64 v17; // x9
  int v18; // w9
  __int64 result; // x0
  int v20; // w10
  _QWORD v21[4]; // [xsp+8h] [xbp-48h] BYREF
  __int64 v22; // [xsp+28h] [xbp-28h]
  __int64 v23; // [xsp+30h] [xbp-20h]
  __int64 v24; // [xsp+38h] [xbp-18h]
  __int64 v25; // [xsp+40h] [xbp-10h]
  __int64 v26; // [xsp+48h] [xbp-8h]

  v26 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( a4 )
  {
    if ( *(_WORD *)(a5 + 32) )
      *(_WORD *)(a4 + 4) = *(_WORD *)(a5 + 32) + a8;
    if ( *(_WORD *)(a5 + 34) )
      *(_WORD *)(a4 + 6) = *(_WORD *)(a5 + 34) + a8;
  }
  v11 = *(_DWORD *)(a6 + 40);
  v12 = *(_DWORD *)(a6 + 44);
  v13 = **a7;
  v23 = 0;
  v24 = 0;
  v25 = 0;
  v22 = 0;
  *(_DWORD *)(a6 + 40) = v11 | 0x10004;
  *(_DWORD *)(a6 + 44) = v12 & 0xFFFFFFF8 | v13 & 7;
  v21[0] = a1;
  if ( (unsigned int)v13 > 5 )
    __break(0x5512u);
  v14 = *(unsigned __int8 *)(a2 - 2464);
  v15 = *(_QWORD *)(a1 + 72) + 8 * v13;
  v16 = a2 + 4 * v13;
  v17 = *(_QWORD *)(v15 + 328);
  v21[2] = *(_QWORD *)(a3 + 944);
  v21[3] = a6;
  LOBYTE(v22) = -1;
  v21[1] = v17;
  if ( v14 != 1 || (v18 = *(_DWORD *)(v16 - 2488)) == 0 )
    v18 = *(_DWORD *)(v16 - 2680);
  LODWORD(v23) = v18;
  LOBYTE(v25) = 1;
  result = rate_control_get_rate(a2 - 4720, 0, (__int64)v21);
  *(_QWORD *)(a6 + 64) = a2;
  v20 = *(_DWORD *)(a6 + 40);
  *(_DWORD *)(a6 + 80) |= *(_DWORD *)(a3 + 8) << 28;
  *(_DWORD *)(a6 + 40) = v20 | 0x1A;
  _ReadStatusReg(SP_EL0);
  return result;
}
