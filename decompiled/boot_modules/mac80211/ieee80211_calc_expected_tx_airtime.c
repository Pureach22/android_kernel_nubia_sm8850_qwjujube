__int64 __fastcall ieee80211_calc_expected_tx_airtime(__int64 a1, __int64 a2, __int64 a3, int a4, char a5)
{
  int v7; // w19
  _DWORD **v8; // x8
  __int64 v9; // x4
  __int64 v10; // x8
  int v11; // w10
  char v12; // w8
  int v13; // w9
  int v14; // w10
  int v15; // w8
  __int64 result; // x0
  int v17; // w8
  unsigned int v18; // w0
  char v19; // w8
  unsigned int v21; // w8
  unsigned int v22; // [xsp+4h] [xbp-3Ch] BYREF
  _QWORD v23[3]; // [xsp+8h] [xbp-38h] BYREF
  __int64 v24; // [xsp+20h] [xbp-20h]
  __int64 v25; // [xsp+28h] [xbp-18h]
  __int64 v26; // [xsp+30h] [xbp-10h]
  __int64 v27; // [xsp+38h] [xbp-8h]

  v7 = a4 + 38;
  v27 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v8 = *(_DWORD ***)(a2 + 920);
  if ( v8 )
  {
    v9 = (unsigned int)**v8;
    if ( !a3 )
    {
      if ( (unsigned __int8)**v8 >= 6u )
      {
        __break(0x5512u);
        JUMPOUT(0x33950);
      }
      v10 = *(_QWORD *)(*(_QWORD *)(*(_QWORD *)(a1 + 72) + 8 * (v9 & 7) + 328) + 8LL)
          + 12LL * (__clz(__rbit32(*(_DWORD *)(a2 + 160))) & 0x1F);
      v11 = *(unsigned __int16 *)(v10 + 4);
      v12 = *(_BYTE *)v10;
      v13 = 80 * v7 / v11;
      if ( *(_BYTE *)(a2 + 134) )
        v14 = 106;
      else
        v14 = 202;
      if ( (v12 & 4) != 0 )
        v15 = v14;
      else
        v15 = 36;
      result = (unsigned int)(v15 + v13);
      goto LABEL_34;
    }
  }
  else
  {
    v9 = 0;
    if ( !a3 )
    {
      result = 0;
      goto LABEL_34;
    }
  }
  v25 = 0;
  v26 = 0;
  v24 = 0;
  memset(v23, 0, sizeof(v23));
  v22 = 0;
  v17 = ((__int64 (__fastcall *)(_QWORD *, __int64, __int64, __int64, __int64))ieee80211_fill_rx_status)(
          v23,
          a1,
          a3 - 296,
          a3 - 292,
          v9);
  result = 0;
  if ( !v17 )
  {
    if ( (v24 & 0x700000000000000LL) != 0 && (a5 & 1) != 0 )
    {
      v18 = ((__int64 (__fastcall *)(_QWORD *, unsigned int *))ieee80211_get_rate_duration)(v23, &v22);
      if ( v18 <= 0x64000 )
      {
        if ( v18 <= 0x3E800 )
        {
          if ( v18 <= 0x25800 )
          {
            if ( v18 <= 0x11800 )
            {
              if ( (HIBYTE(v24) & 7) != 3 || v18 > 0x5000 )
                v19 = 5;
              else
                v19 = 6;
            }
            else
            {
              v19 = 4;
            }
          }
          else
          {
            v19 = 3;
          }
        }
        else
        {
          v19 = 2;
        }
      }
      else
      {
        v19 = 1;
      }
      v21 = (v22 >> v19) + ((v18 * v7) >> 20);
      if ( v21 <= 4 )
        result = 4;
      else
        result = v21;
    }
    else
    {
      result = ieee80211_calc_rx_airtime(a1, v23, v7);
    }
  }
LABEL_34:
  _ReadStatusReg(SP_EL0);
  return result;
}
