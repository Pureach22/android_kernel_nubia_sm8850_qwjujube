__int64 __fastcall nl80211_set_pmk(__int64 a1, _QWORD *a2)
{
  __int64 v3; // x1
  __int64 v4; // x0
  __int64 v5; // x9
  int v6; // w10
  bool v7; // zf
  __int64 result; // x0
  __int64 v9; // x11
  __int64 v10; // x10
  int v11; // w12
  int v12; // w11
  int v13; // w10
  int v14; // w9
  bool v15; // zf
  __int64 v16; // x8
  _BYTE *v17; // x9
  __int64 v18; // x8
  __int64 v19; // [xsp+8h] [xbp-28h]
  __int64 v20; // [xsp+10h] [xbp-20h]
  _BYTE *v21; // [xsp+18h] [xbp-18h]
  __int64 v22; // [xsp+20h] [xbp-10h]
  __int64 v23; // [xsp+28h] [xbp-8h]

  v23 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v3 = a2[7];
  v21 = nullptr;
  v22 = 0;
  v4 = a2[6];
  v20 = 0;
  v5 = *(_QWORD *)(v3 + 992);
  v6 = *(_DWORD *)(v5 + 8);
  v7 = v6 == 8 || v6 == 2;
  if ( v7 && (*(_BYTE *)(v4 + 1106) & 1) != 0 )
  {
    v9 = a2[4];
    v10 = *(_QWORD *)(v9 + 48);
    if ( !v10 || !*(_QWORD *)(v9 + 2032) )
      goto LABEL_21;
    if ( (*(_BYTE *)(v5 + 164) & 1) == 0 )
    {
      result = 4294967189LL;
      goto LABEL_22;
    }
    v11 = *(_DWORD *)(v5 + 280);
    v19 = v10 + 4;
    v12 = *(_DWORD *)(v10 + 4);
    v13 = *(unsigned __int16 *)(v10 + 8);
    v14 = *(unsigned __int16 *)(v5 + 284);
    v15 = v12 == v11 && v13 == v14;
    if ( !v15
      || (v16 = a2[4], v17 = *(_BYTE **)(v16 + 2032), v21 = v17 + 4, LOBYTE(v20) = *v17 - 4, (v20 & 0xEF) != 0x20) )
    {
LABEL_21:
      result = 4294967274LL;
      goto LABEL_22;
    }
    v18 = *(_QWORD *)(v16 + 2064);
    if ( v18 )
      v22 = v18 + 4;
    result = rdev_set_pmk();
  }
  else
  {
    result = 4294967201LL;
  }
LABEL_22:
  _ReadStatusReg(SP_EL0);
  return result;
}
