__int64 __fastcall reg_compute_chan_to_freq_for_chlist(
        __int64 a1,
        unsigned __int8 a2,
        unsigned int a3,
        unsigned int a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10,
        double a11,
        double a12)
{
  unsigned __int16 v12; // w10
  unsigned int v13; // w9
  __int64 v14; // x20
  __int64 result; // x0
  __int64 v16; // x20
  __int64 v17; // x12
  unsigned int v18; // w12
  _BYTE *v19; // x19

  if ( a3 > 0x65 || a4 >= 0x66 )
  {
    v16 = jiffies;
    if ( reg_compute_chan_to_freq_for_chlist___last_ticks - jiffies + 125 < 0 )
    {
      qdf_trace_msg(
        0x51u,
        8u,
        "%s: Invalid channel range: min_chan_range: 0x%X max_chan_range: 0x%X",
        a5,
        a6,
        a7,
        a8,
        a9,
        a10,
        a11,
        a12,
        "reg_compute_chan_to_freq_for_chlist",
        a3,
        a4);
      result = 0;
      reg_compute_chan_to_freq_for_chlist___last_ticks = v16;
      return result;
    }
    return 0;
  }
  v12 = a3;
  v13 = a3;
  if ( a3 <= a4 )
  {
    v13 = a3;
    v12 = a3;
    do
    {
      v17 = a1 + 36LL * v12;
      if ( *(_DWORD *)(v17 + 8) )
      {
        if ( (*(_BYTE *)(v17 + 12) & 1) == 0 )
        {
          v18 = *(unsigned __int8 *)(v17 + 4);
          if ( v18 >= a2 )
          {
            if ( v18 )
              break;
          }
        }
      }
      v13 = ++v12;
    }
    while ( v12 <= (unsigned int)(unsigned __int16)a4 );
  }
  if ( a4 + 1 == v13 )
  {
LABEL_5:
    v14 = jiffies;
    if ( reg_compute_chan_to_freq_for_chlist___last_ticks_110 - jiffies + 125 < 0 )
    {
      qdf_trace_msg(
        0x51u,
        8u,
        "%s: Invalid channel %d",
        a5,
        a6,
        a7,
        a8,
        a9,
        a10,
        a11,
        a12,
        "reg_compute_chan_to_freq_for_chlist",
        a2);
      reg_compute_chan_to_freq_for_chlist___last_ticks_110 = v14;
      return 0;
    }
    return 0;
  }
  v19 = (_BYTE *)(a1 + 36LL * v12);
  if ( (unsigned __int8)v19[4] != a2 )
  {
    if ( v13 == a3 )
      goto LABEL_5;
    if ( v19[4] && *(v19 - 32) )
      return *((_DWORD *)v19 - 9) + 5 * (a2 - (unsigned int)(unsigned __int8)*(v19 - 32));
    qdf_trace_msg(
      0x51u,
      2u,
      "%s: Channel %d invalid in current reg domain",
      a5,
      a6,
      a7,
      a8,
      a9,
      a10,
      a11,
      a12,
      "reg_compute_chan_to_freq_for_chlist",
      a2);
    return 0;
  }
  if ( (v19[12] & 1) != 0 )
    qdf_trace_msg(
      0x51u,
      2u,
      "%s: Channel %d disabled in current reg domain",
      a5,
      a6,
      a7,
      a8,
      a9,
      a10,
      a11,
      a12,
      "reg_compute_chan_to_freq_for_chlist",
      a2);
  return *(unsigned int *)v19;
}
