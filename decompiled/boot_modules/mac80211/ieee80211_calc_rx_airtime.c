__int64 __fastcall ieee80211_calc_rx_airtime(__int64 a1, _BYTE *a2, int a3)
{
  char v4; // w9
  int v5; // w0
  __int64 v6; // x9
  unsigned int v7; // w11
  __int64 v8; // x8
  int v9; // w11
  char v10; // w8
  int v11; // w10
  int v12; // w8
  int v14; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v15; // [xsp+8h] [xbp-8h]

  v15 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v4 = a2[31];
  v14 = 0;
  if ( (v4 & 7) != 0 )
  {
    v5 = ((__int64 (__fastcall *)(_BYTE *, int *))ieee80211_get_rate_duration)(a2, &v14);
    if ( v5 )
    {
      LODWORD(v6) = v14 + ((unsigned int)(v5 * a3) >> 20);
      goto LABEL_18;
    }
LABEL_17:
    LODWORD(v6) = 0;
    goto LABEL_18;
  }
  v7 = (unsigned __int8)a2[36];
  if ( v7 == 4 || v7 == 2 )
  {
    LODWORD(v6) = 0;
    __break(0x800u);
    goto LABEL_18;
  }
  if ( v7 >= 6 )
  {
    __break(0x5512u);
    JUMPOUT(0x3341C);
  }
  v6 = *(_QWORD *)(*(_QWORD *)(a1 + 72) + 8LL * (unsigned __int8)a2[36] + 328);
  if ( v6 )
  {
    if ( *(_DWORD *)(v6 + 24) <= (int)(unsigned __int8)a2[33] )
      goto LABEL_17;
    v8 = *(_QWORD *)(v6 + 8) + 12LL * (unsigned __int8)a2[33];
    v9 = *(unsigned __int16 *)(v8 + 4);
    v10 = *(_BYTE *)v8;
    if ( (a2[30] & 1) != 0 )
      v11 = 106;
    else
      v11 = 202;
    if ( (v10 & 4) != 0 )
      v12 = v11;
    else
      v12 = 36;
    LODWORD(v6) = v12 + 80 * a3 / v9;
  }
LABEL_18:
  _ReadStatusReg(SP_EL0);
  return (unsigned int)v6;
}
