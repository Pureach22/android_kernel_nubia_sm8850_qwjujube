unsigned __int64 __fastcall cfg80211_calculate_bitrate_he(unsigned __int8 *a1)
{
  unsigned __int64 v1; // x8
  unsigned __int64 v2; // x10
  unsigned int v3; // w2
  int v4; // w9
  unsigned int v5; // w1
  unsigned int *v6; // x11
  unsigned int v7; // w8
  char v8; // w9

  v1 = a1[4];
  if ( v1 >= 0xE || (v2 = a1[7], v2 >= 3) || (v3 = a1[9], v3 >= 7) || (v4 = a1[5], (unsigned int)(v4 - 9) <= 0xFFFFFFF7) )
  {
    __break(0x800u);
    return 0;
  }
  v5 = a1[6];
  if ( v5 <= 3 )
  {
    if ( !a1[6] )
      goto LABEL_16;
    if ( v5 == 3 )
    {
LABEL_15:
      v6 = (unsigned int *)&cfg80211_calculate_bitrate_eht_rates_484;
      goto LABEL_23;
    }
    goto LABEL_27;
  }
  if ( v5 == 4 )
    goto LABEL_22;
  if ( v5 == 5 )
    goto LABEL_21;
  if ( v5 != 6 )
  {
LABEL_27:
    _warn_printk("invalid HE MCS: bw:%d, ru:%d\n", v5, v3);
    __break(0x800u);
    return 0;
  }
  if ( a1[9] > 2u )
  {
    if ( a1[9] <= 4u )
    {
      if ( v3 != 3 )
        goto LABEL_15;
LABEL_16:
      v6 = (unsigned int *)&cfg80211_calculate_bitrate_eht_rates_242;
      goto LABEL_23;
    }
    if ( v3 != 5 )
    {
LABEL_21:
      v6 = (unsigned int *)&unk_BE754;
      goto LABEL_23;
    }
LABEL_22:
    v6 = (unsigned int *)&cfg80211_calculate_bitrate_eht_rates_996;
    goto LABEL_23;
  }
  if ( a1[9] )
  {
    if ( v3 == 1 )
      v6 = (unsigned int *)&cfg80211_calculate_bitrate_eht_rates_52;
    else
      v6 = (unsigned int *)&cfg80211_calculate_bitrate_eht_rates_106;
  }
  else
  {
    v6 = (unsigned int *)&cfg80211_calculate_bitrate_eht_rates_26;
  }
LABEL_23:
  v7 = 6144 * (unsigned __int64)v6[v2] / dword_BE71C[v1] * v4;
  if ( a1[8] )
    v8 = 4;
  else
    v8 = 3;
  return (v7 >> v8) / 0x2710uLL;
}
