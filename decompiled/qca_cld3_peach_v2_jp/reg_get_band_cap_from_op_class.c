__int64 __fastcall reg_get_band_cap_from_op_class(
        unsigned __int8 *a1,
        unsigned __int8 a2,
        unsigned __int8 *a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10,
        double a11)
{
  char *class_from_country; // x22
  double v14; // d0
  double v15; // d1
  double v16; // d2
  double v17; // d3
  double v18; // d4
  double v19; // d5
  double v20; // d6
  double v21; // d7
  unsigned int v22; // w19
  __int64 v23; // x28
  unsigned __int8 *v24; // x20
  int v25; // t1
  int v26; // w24
  int v27; // w25
  __int64 v28; // x24
  __int64 v29; // x21

  class_from_country = reg_get_class_from_country(a1, a4, a5, a6, a7, a8, a9, a10, a11);
  v22 = 0;
  do
  {
    if ( !*class_from_country )
      break;
    if ( a2 )
    {
      v23 = a2;
      v24 = a3;
      do
      {
        v25 = *v24++;
        if ( (unsigned __int8)*class_from_country == v25 )
        {
          v26 = *((_DWORD *)class_from_country + 3);
          v27 = 5 * (unsigned __int8)class_from_country[16];
          if ( (reg_is_24ghz_ch_freq((unsigned int)(v27 + v26)) & 1) != 0 )
          {
            v22 |= 1u;
          }
          else if ( (reg_is_5ghz_ch_freq((unsigned int)(v27 + v26)) & 1) != 0 )
          {
            v22 |= 2u;
          }
          else if ( (reg_is_6ghz_chan_freq((unsigned int)(v27 + v26)) & 1) != 0 )
          {
            v22 |= 4u;
          }
          else
          {
            v28 = jiffies;
            if ( reg_get_band_cap_from_chan_set___last_ticks - jiffies + 125 < 0 )
            {
              qdf_trace_msg(
                0x51u,
                2u,
                "%s: Unknown band",
                v14,
                v15,
                v16,
                v17,
                v18,
                v19,
                v20,
                v21,
                "reg_get_band_cap_from_chan_set");
              reg_get_band_cap_from_chan_set___last_ticks = v28;
            }
          }
        }
        --v23;
      }
      while ( v23 );
    }
    class_from_country += 96;
  }
  while ( class_from_country );
  if ( !v22 )
  {
    v29 = jiffies;
    if ( reg_get_band_cap_from_op_class___last_ticks - jiffies + 125 < 0 )
    {
      qdf_trace_msg(
        0x51u,
        2u,
        "%s: None of the operating classes is found",
        v14,
        v15,
        v16,
        v17,
        v18,
        v19,
        v20,
        v21,
        "reg_get_band_cap_from_op_class");
      reg_get_band_cap_from_op_class___last_ticks = v29;
    }
  }
  return v22;
}
