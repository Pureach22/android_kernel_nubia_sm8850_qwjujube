__int64 __fastcall cfg80211_calculate_bitrate(__int16 *a1)
{
  __int16 v1; // w8
  unsigned int v3; // w9
  unsigned int v4; // w10
  unsigned int v5; // w9
  int v6; // w11
  int v7; // w12
  int v8; // w10
  unsigned int v9; // w9
  unsigned __int64 v10; // x8
  __int64 v11; // x8
  __int64 v12; // x8
  unsigned __int64 v13; // x8
  unsigned __int64 v14; // x2
  unsigned __int64 v15; // x9
  __int64 v16; // x9
  unsigned int v17; // w9
  int v18; // w1
  int v19; // w3

  v1 = *a1;
  if ( (*a1 & 1) != 0 )
  {
    v3 = *((unsigned __int8 *)a1 + 4);
    if ( v3 < 0x20 )
    {
      v4 = v3 & 7;
      v5 = v3 >> 3;
      if ( *((_BYTE *)a1 + 6) == 3 )
        v6 = 13500000;
      else
        v6 = 6500000;
      v7 = v4 + 3;
      if ( v4 == 4 )
        v7 = 6;
      if ( v4 < 4 )
        v8 = v4 + 1;
      else
        v8 = v7;
      v9 = (v8 + v8 * v5) * v6;
      if ( (v1 & 4) != 0 )
        v9 = 10 * (v9 / 9);
      return (v9 + 50000) / 0x186A0uLL;
    }
LABEL_43:
    __break(0x800u);
    return 0;
  }
  if ( (v1 & 8) != 0 )
  {
    v10 = *((unsigned __int8 *)a1 + 4);
    if ( v10 < 0x20 )
      return cfg80211_calculate_bitrate_dmg___mcs2bitrate[v10];
    goto LABEL_43;
  }
  if ( (v1 & 0x40) != 0 )
  {
    v11 = *((unsigned __int8 *)a1 + 4);
    if ( (unsigned int)(v11 - 13) > 0xFFFFFFF8 )
    {
      v12 = v11 - 6;
      if ( (unsigned __int64)(4 * v12) <= 0x1C && v12 != 7 )
        return cfg80211_calculate_bitrate_extended_sc_dmg___mcs2bitrate[v12];
      goto LABEL_45;
    }
    goto LABEL_43;
  }
  if ( (v1 & 0x20) != 0 )
  {
    v13 = *((unsigned __int8 *)a1 + 4);
    if ( v13 < 0x15 )
      return cfg80211_calculate_bitrate_edmg___mcs2bitrate[v13] * (unsigned int)*((unsigned __int8 *)a1 + 10);
    goto LABEL_43;
  }
  if ( (v1 & 2) == 0 )
  {
    if ( (v1 & 0x10) != 0 )
      return cfg80211_calculate_bitrate_he();
    if ( (v1 & 0x80) != 0 )
      return cfg80211_calculate_bitrate_eht();
    if ( (*a1 & 0x100) != 0 )
      return cfg80211_calculate_bitrate_s1g();
    return (unsigned __int16)a1[1];
  }
  v14 = *((unsigned __int8 *)a1 + 4);
  if ( v14 <= 0xB )
  {
    v15 = *((unsigned __int8 *)a1 + 6);
    if ( v15 <= 5 && ((0x39u >> v15) & 1) != 0 )
    {
      v16 = qword_BE918[v15];
      if ( 48 * v16 + 4 * v14 <= 0xBF )
      {
        v17 = cfg80211_calculate_bitrate_vht_base[12 * v16 + v14] * *((unsigned __int8 *)a1 + 5);
        if ( (v1 & 4) != 0 )
          v17 = 10 * (v17 / 9);
        return (v17 + 50000) / 0x186A0uLL;
      }
LABEL_45:
      __break(1u);
      return cfg80211_calculate_bitrate_he();
    }
  }
  if ( (cfg80211_calculate_bitrate_vht___already_done & 1) == 0 )
  {
    v18 = *((unsigned __int8 *)a1 + 6);
    v19 = *((unsigned __int8 *)a1 + 5);
    cfg80211_calculate_bitrate_vht___already_done = 1;
    _warn_printk("invalid rate bw=%d, mcs=%d, nss=%d\n", v18, v14, v19);
    __break(0x800u);
  }
  return 0;
}
