__int64 __fastcall ieee80211_tdls_add_subband(
        __int64 a1,
        __int64 a2,
        unsigned __int16 a3,
        unsigned __int16 a4,
        unsigned __int16 a5)
{
  unsigned int v5; // w26
  __int64 result; // x0
  unsigned int v7; // w27
  int v8; // w28
  unsigned int v9; // w22
  int v11; // w20
  __int64 v12; // x23
  char v13; // w25
  unsigned int v14; // w24
  unsigned int v15; // w19
  __int64 channel_khz; // x0
  int v17; // w8
  __int64 v18; // x0
  unsigned int v19; // w8
  _BYTE *v20; // x24
  char v21; // w0
  _BYTE *v22; // x20
  unsigned int v24; // [xsp+14h] [xbp-3Ch]
  _QWORD v25[4]; // [xsp+18h] [xbp-38h] BYREF
  _DWORD v26[2]; // [xsp+3Ch] [xbp-14h] BYREF
  char v27; // [xsp+44h] [xbp-Ch]
  __int16 v28; // [xsp+45h] [xbp-Bh]
  char v29; // [xsp+47h] [xbp-9h]
  __int64 v30; // [xsp+48h] [xbp-8h]

  v5 = a4;
  v30 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( a4 >= (unsigned int)a3 )
  {
    v7 = a3;
    v8 = a5;
    v9 = 1000 * a3;
    v11 = 1000 * a5;
    v12 = *(_QWORD *)(*(_QWORD *)(a1 + 1616) + 72LL);
    v13 = 0;
    v14 = 0;
    v24 = 0;
    memset(v25, 0, sizeof(v25));
    do
    {
      if ( v13 )
        v15 = v14;
      else
        v15 = v7;
      channel_khz = ieee80211_get_channel_khz(*(_QWORD *)(*(_QWORD *)(a1 + 1616) + 72LL), v9);
      if ( channel_khz
        && (cfg80211_chandef_create(v25, channel_khz, 0),
            v17 = *(_DWORD *)(a1 + 24),
            v27 = 1,
            v26[0] = v17,
            v26[1] = 0,
            v28 = 0,
            v29 = 0,
            (cfg80211_reg_check_beaconing(v12, v25, v26) & 1) != 0) )
      {
        ++v13;
      }
      else
      {
        if ( v13 )
        {
          v18 = skb_put(a2, 2);
          v19 = 1000 * v14;
          v20 = (_BYTE *)v18;
          v21 = ieee80211_freq_khz_to_channel(v19);
          v20[1] = v13;
          *v20 = v21;
          ++v24;
        }
        v13 = 0;
      }
      v7 += v8;
      v9 += v11;
      v14 = v15;
    }
    while ( v7 <= v5 );
    if ( v13 )
    {
      v22 = (_BYTE *)skb_put(a2, 2);
      *v22 = ieee80211_freq_khz_to_channel(1000 * v15);
      v22[1] = v13;
      result = v24 + 1;
    }
    else
    {
      result = v24;
    }
  }
  else
  {
    result = 0;
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
