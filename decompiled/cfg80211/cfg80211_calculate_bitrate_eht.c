unsigned __int64 __fastcall cfg80211_calculate_bitrate_eht(unsigned __int8 *a1)
{
  unsigned int v1; // w8
  unsigned __int64 v2; // x10
  unsigned int v3; // w2
  __int64 v4; // x9
  int v5; // w1
  _DWORD *v7; // x11
  unsigned int v8; // w10
  _DWORD *v9; // x11
  _DWORD *v10; // x12

  v1 = a1[4];
  if ( v1 >= 0x10
    || (v2 = a1[11], v2 >= 3)
    || (v3 = a1[12], v3 >= 0x10)
    || (v4 = a1[5], (unsigned int)(v4 - 9) <= 0xFFFFFFF7) )
  {
    __break(0x800u);
    return 0;
  }
  else
  {
    v5 = a1[6];
    if ( v1 == 14 )
    {
      if ( a1[6] <= 6u )
      {
        if ( v5 != 4 )
        {
          if ( v5 != 5 )
            goto LABEL_20;
          goto LABEL_26;
        }
        goto LABEL_27;
      }
      if ( v5 == 7 )
        goto LABEL_28;
      if ( v5 != 8 )
      {
LABEL_20:
        _warn_printk("invalid EHT BW for MCS 14: bw:%d, ru:%d\n", v5, v3);
        __break(0x800u);
        return 0;
      }
      if ( v3 != 8 )
      {
        if ( v3 != 11 )
        {
          if ( v3 != 15 )
            goto LABEL_20;
LABEL_28:
          v8 = 4 * cfg80211_calculate_bitrate_eht_rates_996[v2];
          return (unsigned int)((6144 * (unsigned __int64)v8 / cfg80211_calculate_bitrate_eht_mcs_divisors[a1[4]] * v4) >> 3)
               / 0x2710uLL;
        }
LABEL_26:
        v8 = 2 * cfg80211_calculate_bitrate_eht_rates_996[v2];
        return (unsigned int)((6144 * (unsigned __int64)v8 / cfg80211_calculate_bitrate_eht_mcs_divisors[a1[4]] * v4) >> 3)
             / 0x2710uLL;
      }
LABEL_27:
      v7 = cfg80211_calculate_bitrate_eht_rates_996;
LABEL_31:
      v8 = v7[v2];
      return (unsigned int)((6144 * (unsigned __int64)v8 / cfg80211_calculate_bitrate_eht_mcs_divisors[a1[4]] * v4) >> 3)
           / 0x2710uLL;
    }
    if ( a1[6] > 4u )
    {
      switch ( v5 )
      {
        case 5:
          goto LABEL_26;
        case 7:
          goto LABEL_28;
        case 8:
          switch ( a1[12] )
          {
            case 0u:
              v7 = &cfg80211_calculate_bitrate_eht_rates_26;
              goto LABEL_31;
            case 1u:
              v7 = &cfg80211_calculate_bitrate_eht_rates_52;
              goto LABEL_31;
            case 2u:
              v9 = &cfg80211_calculate_bitrate_eht_rates_26;
              v10 = &cfg80211_calculate_bitrate_eht_rates_52;
              goto LABEL_42;
            case 3u:
              v7 = &cfg80211_calculate_bitrate_eht_rates_106;
              goto LABEL_31;
            case 4u:
              v9 = &cfg80211_calculate_bitrate_eht_rates_26;
              v10 = &cfg80211_calculate_bitrate_eht_rates_106;
              goto LABEL_42;
            case 5u:
              goto LABEL_29;
            case 6u:
              goto LABEL_30;
            case 7u:
              v9 = cfg80211_calculate_bitrate_eht_rates_242;
              v10 = cfg80211_calculate_bitrate_eht_rates_484;
              goto LABEL_42;
            case 8u:
              goto LABEL_27;
            case 9u:
              v9 = cfg80211_calculate_bitrate_eht_rates_484;
              v10 = cfg80211_calculate_bitrate_eht_rates_996;
LABEL_42:
              v8 = v9[v2] + v10[v2];
              break;
            case 0xAu:
              v8 = cfg80211_calculate_bitrate_eht_rates_484[v2]
                 + cfg80211_calculate_bitrate_eht_rates_996[v2]
                 + cfg80211_calculate_bitrate_eht_rates_242[v2];
              break;
            case 0xBu:
              goto LABEL_26;
            case 0xCu:
              v8 = cfg80211_calculate_bitrate_eht_rates_484[v2] + 2 * cfg80211_calculate_bitrate_eht_rates_996[v2];
              break;
            case 0xDu:
              v8 = 3 * cfg80211_calculate_bitrate_eht_rates_996[v2];
              break;
            case 0xEu:
              v8 = 3 * cfg80211_calculate_bitrate_eht_rates_996[v2] + cfg80211_calculate_bitrate_eht_rates_484[v2];
              break;
            case 0xFu:
              goto LABEL_28;
          }
          return (unsigned int)((6144 * (unsigned __int64)v8 / cfg80211_calculate_bitrate_eht_mcs_divisors[a1[4]] * v4) >> 3)
               / 0x2710uLL;
      }
    }
    else
    {
      if ( !a1[6] )
      {
LABEL_29:
        v7 = cfg80211_calculate_bitrate_eht_rates_242;
        goto LABEL_31;
      }
      if ( v5 == 3 )
      {
LABEL_30:
        v7 = cfg80211_calculate_bitrate_eht_rates_484;
        goto LABEL_31;
      }
      if ( v5 == 4 )
        goto LABEL_27;
    }
    _warn_printk("invalid EHT MCS: bw:%d, ru:%d\n", v5, v3);
    __break(0x800u);
    return 0;
  }
}
