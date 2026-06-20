__int64 __fastcall reg_chan_band_to_freq(
        __int64 a1,
        unsigned int a2,
        unsigned __int8 a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10,
        double a11)
{
  __int64 pdev_obj; // x0
  double v15; // d0
  double v16; // d1
  double v17; // d2
  double v18; // d3
  double v19; // d4
  double v20; // d5
  double v21; // d6
  double v22; // d7
  __int64 v23; // x0
  double v24; // d0
  double v25; // d1
  double v26; // d2
  double v27; // d3
  double v28; // d4
  double v29; // d5
  double v30; // d6
  double v31; // d7
  __int64 result; // x0
  __int64 v33; // x20
  const char *v34; // x3
  __int64 v35; // x21
  __int64 v36; // x21
  __int64 v37; // x0

  if ( !(_BYTE)a2 )
  {
    v33 = jiffies;
    if ( reg_chan_band_to_freq___last_ticks - jiffies + 125 < 0 )
    {
      qdf_trace_msg(0x51u, 8u, "%s: Invalid channel %d", a4, a5, a6, a7, a8, a9, a10, a11, "reg_chan_band_to_freq", 0);
      reg_chan_band_to_freq___last_ticks = v33;
      return 0;
    }
    return 0;
  }
  pdev_obj = reg_get_pdev_obj(a1, a4, a5, a6, a7, a8, a9, a10, a11);
  if ( !pdev_obj )
  {
    v34 = "reg_chan_band_to_freq";
LABEL_11:
    qdf_trace_msg(0x51u, 2u, "%s: reg pdev priv obj is NULL", v15, v16, v17, v18, v19, v20, v21, v22, v34);
    return 0;
  }
  if ( (a3 & 4) != 0 )
  {
    if ( (a3 & 3) != 0 )
    {
      v35 = jiffies;
      if ( reg_chan_band_to_freq___last_ticks_29 - jiffies + 125 < 0 )
      {
        qdf_trace_msg(
          0x51u,
          2u,
          "%s: Incorrect band_mask %x",
          v15,
          v16,
          v17,
          v18,
          v19,
          v20,
          v21,
          v22,
          "reg_chan_band_to_freq",
          a3);
        reg_chan_band_to_freq___last_ticks_29 = v35;
        return 0;
      }
    }
    else
    {
      if ( (unsigned __int8)a2 != 2 )
        return (unsigned __int16)reg_compute_chan_to_freq(a1, a2, 0x2Bu, 0x65u, v15, v16, v17, v18, v19, v20, v21, v22);
      if ( *(_DWORD *)(pdev_obj + 8864) && (*(_BYTE *)(pdev_obj + 8868) & 1) == 0 )
        return *(unsigned int *)(pdev_obj + 8856);
    }
    return 0;
  }
  if ( (a3 & 1) != 0 )
  {
    v23 = reg_get_pdev_obj(a1, v15, v16, v17, v18, v19, v20, v21, v22);
    if ( v23 )
    {
      LOWORD(result) = reg_compute_chan_to_freq_for_chlist(v23 + 7344, a2, 0, 13);
      if ( (_WORD)result )
        return (unsigned __int16)result;
    }
    else
    {
      qdf_trace_msg(
        0x51u,
        2u,
        "%s: reg pdev priv obj is NULL",
        v24,
        v25,
        v26,
        v27,
        v28,
        v29,
        v30,
        v31,
        "reg_compute_chan_to_freq");
    }
  }
  if ( (a3 & 2) != 0 )
  {
    v37 = reg_get_pdev_obj(a1, v15, v16, v17, v18, v19, v20, v21, v22);
    if ( v37 )
      return (unsigned __int16)reg_compute_chan_to_freq_for_chlist(v37 + 7344, a2, 14, 41);
    v34 = "reg_compute_chan_to_freq";
    goto LABEL_11;
  }
  v36 = jiffies;
  if ( reg_chan_band_to_freq___last_ticks_31 - jiffies + 125 < 0 )
  {
    qdf_trace_msg(
      0x51u,
      2u,
      "%s: Incorrect band_mask %x",
      v15,
      v16,
      v17,
      v18,
      v19,
      v20,
      v21,
      v22,
      "reg_chan_band_to_freq",
      a3);
    reg_chan_band_to_freq___last_ticks_31 = v36;
    return 0;
  }
  return 0;
}
