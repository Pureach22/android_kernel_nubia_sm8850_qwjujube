__int64 __fastcall add_chlist_to_pcl(
        __int64 a1,
        __int64 a2,
        unsigned int a3,
        unsigned int *a4,
        char a5,
        _DWORD *a6,
        unsigned __int8 a7,
        char a8,
        double a9,
        double a10,
        double a11,
        double a12,
        double a13,
        double a14,
        double a15,
        double a16)
{
  unsigned __int64 v23; // x26
  __int64 i; // x27
  unsigned __int64 v25; // x8

  if ( a7 )
  {
    v23 = a3;
    for ( i = a7; i; --i )
    {
      v25 = *a4;
      if ( v25 >= v23 )
        return qdf_trace_msg(
                 0x4Fu,
                 8u,
                 "%s: Add chlist len %d index %d",
                 a9,
                 a10,
                 a11,
                 a12,
                 a13,
                 a14,
                 a15,
                 a16,
                 "add_chlist_to_pcl",
                 a7,
                 *a4);
      if ( (a8 & 1) != 0 )
      {
        if ( wlan_reg_is_6ghz_chan_freq(*a6) )
          goto LABEL_4;
        v25 = *a4;
      }
      *(_DWORD *)(a1 + 4 * v25) = *a6;
      *(_BYTE *)(a2 + (*a4)++) = a5;
LABEL_4:
      ++a6;
    }
  }
  return qdf_trace_msg(
           0x4Fu,
           8u,
           "%s: Add chlist len %d index %d",
           a9,
           a10,
           a11,
           a12,
           a13,
           a14,
           a15,
           a16,
           "add_chlist_to_pcl",
           a7,
           *a4);
}
