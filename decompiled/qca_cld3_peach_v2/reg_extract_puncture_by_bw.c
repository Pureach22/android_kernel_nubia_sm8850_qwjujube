__int64 __fastcall reg_extract_puncture_by_bw(
        unsigned int a1,
        unsigned __int16 a2,
        unsigned int a3,
        int a4,
        unsigned int a5,
        unsigned __int16 *a6,
        double a7,
        double a8,
        double a9,
        double a10,
        double a11,
        double a12,
        double a13,
        double a14)
{
  __int64 v17; // x23
  unsigned int v18; // w8
  unsigned __int16 *bonded_chan_entry; // x20
  double v22; // d0
  double v23; // d1
  double v24; // d2
  double v25; // d3
  double v26; // d4
  double v27; // d5
  double v28; // d6
  double v29; // d7
  unsigned __int16 *v30; // x0
  double v31; // d0
  double v32; // d1
  double v33; // d2
  double v34; // d3
  double v35; // d4
  double v36; // d5
  double v37; // d6
  double v38; // d7
  unsigned int v39; // w10
  unsigned int v40; // w11
  int v41; // w8
  int v42; // w12
  unsigned __int16 v43; // w13
  __int64 v44; // x23

  if ( a1 < a5 )
  {
    v17 = jiffies;
    if ( reg_extract_puncture_by_bw___last_ticks - jiffies + 125 < 0 )
    {
      qdf_trace_msg(
        0x51u,
        2u,
        "%s: freq %d, ori bw %d can't be smaller than new bw %d",
        a7,
        a8,
        a9,
        a10,
        a11,
        a12,
        a13,
        a14,
        "reg_extract_puncture_by_bw",
        a3,
        a1,
        a5);
      reg_extract_puncture_by_bw___last_ticks = v17;
    }
    return 16;
  }
  if ( a1 == a5 )
  {
    v18 = 0;
    *a6 = a2;
  }
  else
  {
    bonded_chan_entry = reg_get_bonded_chan_entry(a3, a1, a4, a7, a8, a9, a10, a11, a12, a13, a14);
    v30 = reg_get_bonded_chan_entry(a3, a5, 0, v22, v23, v24, v25, v26, v27, v28, v29);
    if ( !bonded_chan_entry )
    {
      v44 = jiffies;
      if ( reg_extract_puncture_by_bw___last_ticks_57 - jiffies + 125 < 0 )
      {
        qdf_trace_msg(
          0x51u,
          2u,
          "%s: bonded chan fails, freq %d, ori bw %d, new bw %d",
          v31,
          v32,
          v33,
          v34,
          v35,
          v36,
          v37,
          v38,
          "reg_extract_puncture_by_bw",
          a3,
          a1,
          a5);
        reg_extract_puncture_by_bw___last_ticks_57 = v44;
      }
      return 16;
    }
    *a6 = 0;
    v18 = 0;
    v39 = *bonded_chan_entry;
    v40 = bonded_chan_entry[1];
    if ( v39 <= v40 )
    {
      v41 = 0;
      v42 = 0;
      v43 = a2;
      do
      {
        if ( a3 == (unsigned __int16)v39
          || v30 && *v30 <= (unsigned int)(unsigned __int16)v39 && v30[1] >= (unsigned int)(unsigned __int16)v39 )
        {
          v40 = (v43 & 1) << v42++;
          v41 |= v40;
          *a6 = v41;
          LOWORD(v40) = bonded_chan_entry[1];
        }
        LOWORD(v39) = v39 + 20;
        v43 >>= 1;
      }
      while ( (unsigned __int16)v39 <= (unsigned int)(unsigned __int16)v40 );
      return 0;
    }
  }
  return v18;
}
