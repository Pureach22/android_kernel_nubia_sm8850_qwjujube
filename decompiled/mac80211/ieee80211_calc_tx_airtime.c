__int64 __fastcall ieee80211_calc_tx_airtime(__int64 a1, __int64 a2, int a3)
{
  char v6; // w8
  __int64 result; // x0
  char v8; // w8
  unsigned int v9; // w22
  char v10; // w8
  int v11; // w8
  char v12; // w9
  char v13; // w8
  int v14; // w8
  char v15; // w9
  char v16; // w8
  int v17; // w8
  __int64 v18; // [xsp+8h] [xbp-38h] BYREF
  __int64 v19; // [xsp+10h] [xbp-30h]
  __int64 v20; // [xsp+18h] [xbp-28h]
  __int64 v21; // [xsp+20h] [xbp-20h]
  __int64 v22; // [xsp+28h] [xbp-18h]
  __int64 v23; // [xsp+30h] [xbp-10h]
  __int64 v24; // [xsp+38h] [xbp-8h]

  v24 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v6 = *(_BYTE *)(a2 + 4);
  v22 = 0;
  v23 = 0;
  v20 = 0;
  v21 = 0;
  v18 = 0;
  v19 = 0;
  if ( (unsigned int)((__int64 (__fastcall *)(__int64 *, __int64, __int64, _QWORD, _QWORD))ieee80211_fill_rx_status)(
                       &v18,
                       a1,
                       a2 + 8,
                       0,
                       v6 & 7) )
  {
    result = 0;
  }
  else
  {
    result = ieee80211_calc_rx_airtime(a1, &v18, a3);
    if ( (_DWORD)result )
    {
      v8 = *(_WORD *)(a2 + 9);
      v22 = 0;
      v23 = 0;
      v20 = 0;
      v21 = 0;
      v9 = result * (v8 & 0x1F);
      v10 = *(_BYTE *)(a2 + 4);
      v18 = 0;
      v19 = 0;
      if ( (unsigned int)((__int64 (__fastcall *)(__int64 *, __int64, __int64, _QWORD, _QWORD))ieee80211_fill_rx_status)(
                           &v18,
                           a1,
                           a2 + 11,
                           0,
                           v10 & 7) )
        goto LABEL_5;
      v11 = ieee80211_calc_rx_airtime(a1, &v18, a3);
      result = v9;
      if ( !v11 )
        goto LABEL_6;
      v12 = *(_WORD *)(a2 + 12);
      v22 = 0;
      v23 = 0;
      v20 = 0;
      v21 = 0;
      v9 += v11 * (v12 & 0x1F);
      v13 = *(_BYTE *)(a2 + 4);
      v18 = 0;
      v19 = 0;
      if ( (unsigned int)((__int64 (__fastcall *)(__int64 *, __int64, __int64, _QWORD, _QWORD))ieee80211_fill_rx_status)(
                           &v18,
                           a1,
                           a2 + 14,
                           0,
                           v13 & 7) )
        goto LABEL_5;
      v14 = ieee80211_calc_rx_airtime(a1, &v18, a3);
      result = v9;
      if ( !v14 )
        goto LABEL_6;
      v15 = *(_WORD *)(a2 + 15);
      v22 = 0;
      v23 = 0;
      v20 = 0;
      v21 = 0;
      v9 += v14 * (v15 & 0x1F);
      v16 = *(_BYTE *)(a2 + 4);
      v18 = 0;
      v19 = 0;
      if ( (unsigned int)((__int64 (__fastcall *)(__int64 *, __int64, __int64, _QWORD, _QWORD))ieee80211_fill_rx_status)(
                           &v18,
                           a1,
                           a2 + 17,
                           0,
                           v16 & 7) )
      {
LABEL_5:
        result = v9;
      }
      else
      {
        v17 = ieee80211_calc_rx_airtime(a1, &v18, a3);
        result = v9;
        if ( v17 )
          result = v9 + v17 * (*(_WORD *)(a2 + 18) & 0x1F);
      }
    }
  }
LABEL_6:
  _ReadStatusReg(SP_EL0);
  return result;
}
