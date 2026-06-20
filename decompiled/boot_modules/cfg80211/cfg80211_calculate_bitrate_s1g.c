unsigned __int64 __fastcall cfg80211_calculate_bitrate_s1g(__int64 a1, int a2, __int64 a3, void *a4)
{
  unsigned __int64 v4; // x2
  unsigned int v5; // w8
  int v7; // w1
  int v8; // w3

  v4 = *(unsigned __int8 *)(a1 + 4);
  if ( v4 > 0xA || (unsigned int)*(unsigned __int8 *)(a1 + 6) - 9 > 4 )
  {
    if ( (cfg80211_calculate_bitrate_s1g___already_done & 1) == 0 )
    {
      v7 = *(unsigned __int8 *)(a1 + 6);
      v8 = *(unsigned __int8 *)(a1 + 5);
      cfg80211_calculate_bitrate_s1g___already_done = 1;
      _warn_printk("invalid rate bw=%d, mcs=%d, nss=%d\n", v7, v4, v8);
      __break(0x800u);
    }
    return 0;
  }
  else if ( 4 * v4 + 44LL * (unsigned __int8)(*(_BYTE *)(a1 + 6) - 9) > 0xDB )
  {
    __break(1u);
    return cfg80211_get_p2p_attr(a1, a2, v4, a4);
  }
  else
  {
    v5 = cfg80211_calculate_bitrate_s1g_base[11 * (unsigned __int8)(*(_BYTE *)(a1 + 6) - 9) + v4]
       * *(unsigned __int8 *)(a1 + 5);
    if ( (*(_WORD *)a1 & 4) != 0 )
      v5 = 10 * (v5 / 9);
    return (v5 + 50000) / 0x186A0uLL;
  }
}
