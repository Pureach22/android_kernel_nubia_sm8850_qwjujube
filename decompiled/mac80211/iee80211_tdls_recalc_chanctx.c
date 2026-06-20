__int64 __fastcall iee80211_tdls_recalc_chanctx(__int64 result, __int64 a2)
{
  unsigned int **v2; // x23
  __int64 v3; // x8
  __int64 v4; // x20
  unsigned int **v5; // x21
  int v7; // w24
  __int64 v8; // x22
  unsigned int v9; // w23
  int v10; // w8

  v2 = *(unsigned int ***)(result + 5640);
  if ( v2 )
  {
    v3 = **v2;
    if ( (unsigned int)v3 >= 6 )
    {
      __break(0x5512u);
      return iee80211_tdls_recalc_ht_protection(result, a2);
    }
    else
    {
      v4 = *(_QWORD *)(result + 1616);
      v5 = v2 - 19;
      v7 = *((_DWORD *)v2 + 2);
      v8 = *(_QWORD *)(*(_QWORD *)(v4 + 72) + 8 * v3 + 328);
      result = ((__int64 (__fastcall *)(__int64, unsigned int **))ieee80211_recalc_chanctx_chantype)(v4, v2 - 19);
      if ( a2 )
      {
        result = *((unsigned int *)v2 + 2);
        if ( v7 != (_DWORD)result && (*(_QWORD *)(a2 + 216) & 0x10000) != 0 )
        {
          v9 = ieee80211_chan_width_to_rx_bw();
          result = ((__int64 (__fastcall *)(__int64, _QWORD))ieee80211_sta_cap_rx_bw)(a2 + 1640, 0);
          if ( v9 >= (unsigned int)result )
            v10 = result;
          else
            v10 = v9;
          if ( v10 != *(_DWORD *)(a2 + 3112) )
          {
            *(_DWORD *)(a2 + 3112) = v10;
            rate_control_rate_update(v4, v8, a2, 0, 1u);
            return ((__int64 (__fastcall *)(__int64, unsigned int **))ieee80211_recalc_chanctx_chantype)(v4, v5);
          }
        }
      }
    }
  }
  return result;
}
