__int64 __fastcall reg_apply_puncture(
        __int64 a1,
        unsigned __int16 a2,
        unsigned int a3,
        unsigned int a4,
        unsigned int a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10,
        double a11,
        double a12,
        double a13)
{
  __int64 pdev_obj; // x0
  double v18; // d0
  double v19; // d1
  double v20; // d2
  double v21; // d3
  double v22; // d4
  double v23; // d5
  double v24; // d6
  double v25; // d7
  __int64 v26; // x19
  unsigned __int16 *bonded_chan_entry; // x0
  double v28; // d0
  double v29; // d1
  double v30; // d2
  double v31; // d3
  double v32; // d4
  double v33; // d5
  double v34; // d6
  double v35; // d7
  unsigned int v36; // w4
  unsigned int v37; // w8
  __int64 v39; // x20
  __int64 v40; // x23
  char v41; // w9
  __int16 v42; // w17
  __int16 v43; // w1
  unsigned int v44; // w8
  unsigned int v45; // w2
  __int16 v46; // w3
  __int16 v47; // w8
  __int64 v48; // x20
  __int64 v49; // x20

  pdev_obj = reg_get_pdev_obj(a1, a6, a7, a8, a9, a10, a11, a12, a13);
  if ( pdev_obj )
  {
    v26 = pdev_obj;
    bonded_chan_entry = reg_get_bonded_chan_entry(a3, a4, a5, v18, v19, v20, v21, v22, v23, v24, v25);
    if ( bonded_chan_entry )
    {
      v36 = *bonded_chan_entry;
      v37 = bonded_chan_entry[1];
      if ( v36 > v37 )
      {
LABEL_4:
        reg_compute_pdev_current_chan_list(v26, v28, v29, v30, v31, v32, v33, v34, v35);
        return 0;
      }
      v41 = 0;
      while ( (((unsigned __int64)a2 >> v41) & 1) == 0 )
      {
LABEL_10:
        v36 += 20;
        ++v41;
        if ( v36 > v37 )
          goto LABEL_4;
      }
      v42 = 0;
      v43 = 101;
      while ( 1 )
      {
        v44 = (v42 + v43) / 2;
        v45 = *(_DWORD *)(channel_map + 12LL * (int)v44);
        if ( v45 == v36 )
          break;
        v46 = v44 - 1;
        if ( v45 < v36 )
          v47 = v44 + 1;
        else
          v47 = v42;
        if ( v45 >= v36 )
          v43 = v46;
        v42 = v47;
        if ( v47 > v43 )
        {
          v48 = jiffies;
          if ( reg_get_chan_enum_for_freq___last_ticks - jiffies + 125 < 0 )
          {
            qdf_trace_msg(
              0x51u,
              8u,
              "%s: invalid channel center frequency %d",
              v28,
              v29,
              v30,
              v31,
              v32,
              v33,
              v34,
              v35,
              "reg_get_chan_enum_for_freq");
            reg_get_chan_enum_for_freq___last_ticks = v48;
          }
          v44 = 102;
          goto LABEL_26;
        }
      }
      if ( v44 < 0x66 )
      {
        *(_BYTE *)(v26 + 7344 + 36LL * v44 + 30) = 1;
        v37 = bonded_chan_entry[1];
        goto LABEL_10;
      }
LABEL_26:
      v49 = jiffies;
      if ( reg_apply_puncture___last_ticks_63 - jiffies + 125 < 0 )
      {
        qdf_trace_msg(
          0x51u,
          8u,
          "%s: Invalid chan enum %d",
          v28,
          v29,
          v30,
          v31,
          v32,
          v33,
          v34,
          v35,
          "reg_apply_puncture",
          v44);
        reg_apply_puncture___last_ticks_63 = v49;
      }
    }
    else
    {
      v40 = jiffies;
      if ( reg_apply_puncture___last_ticks_61 - jiffies + 125 < 0 )
      {
        qdf_trace_msg(
          0x51u,
          2u,
          "%s: bonded chan fails, freq %d, bw %d, cen320_freq %d",
          v28,
          v29,
          v30,
          v31,
          v32,
          v33,
          v34,
          v35,
          "reg_apply_puncture",
          a3,
          a4,
          a5);
        reg_apply_puncture___last_ticks_61 = v40;
      }
    }
  }
  else
  {
    v39 = jiffies;
    if ( reg_apply_puncture___last_ticks - jiffies + 125 < 0 )
    {
      qdf_trace_msg(0x51u, 2u, "%s: pdev reg obj is NULL", v18, v19, v20, v21, v22, v23, v24, v25, "reg_apply_puncture");
      reg_apply_puncture___last_ticks = v39;
    }
  }
  return 16;
}
