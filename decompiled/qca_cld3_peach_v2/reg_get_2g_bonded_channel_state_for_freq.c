__int64 __fastcall reg_get_2g_bonded_channel_state_for_freq(
        __int64 a1,
        unsigned int a2,
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
  __int64 v12; // x29
  __int64 v13; // x30
  __int64 result; // x0
  __int64 v16; // x21
  int v17; // w23
  unsigned int channel_state_for_pwrmode; // w20
  __int64 v19; // x21
  __int64 pdev_obj; // x0
  double v21; // d0
  double v22; // d1
  double v23; // d2
  double v24; // d3
  double v25; // d4
  double v26; // d5
  double v27; // d6
  double v28; // d7
  __int64 v29; // x22
  double v30; // d0
  double v31; // d1
  double v32; // d2
  double v33; // d3
  double v34; // d4
  double v35; // d5
  double v36; // d6
  double v37; // d7
  __int16 v38; // w9
  __int16 v39; // w10
  unsigned int v40; // w12
  unsigned int v41; // w13
  __int64 v42; // x21
  __int64 v43; // x8
  unsigned int v44; // w9
  __int64 v45; // [xsp+8h] [xbp-38h]

  if ( a4 > 1 )
    return 4;
  v45 = v13;
  if ( a4 == 1 )
  {
    if ( a2 + 20 != a3 && a3 + 20 != a2 )
      return 4;
    v17 = 1;
    v16 = a1;
    channel_state_for_pwrmode = reg_get_channel_state_for_pwrmode(a1, a3, 0, a5, a6, a7, a8, a9, a10, a11, a12);
    a1 = v16;
    if ( channel_state_for_pwrmode == 4 )
      return 4;
  }
  else
  {
    v17 = a4;
    channel_state_for_pwrmode = 4;
  }
  v19 = a1;
  pdev_obj = reg_get_pdev_obj(a1, a5, a6, a7, a8, a9, a10, a11, a12);
  if ( !pdev_obj )
  {
    qdf_trace_msg(
      0x51u,
      2u,
      "%s: reg pdev priv obj is NULL",
      v21,
      v22,
      v23,
      v24,
      v25,
      v26,
      v27,
      v28,
      "reg_get_2g_bonded_channel_state_for_freq",
      v12,
      v45);
    return 4;
  }
  v29 = pdev_obj;
  LODWORD(result) = reg_get_channel_state_for_pwrmode(v19, a2, 0, v21, v22, v23, v24, v25, v26, v27, v28);
  if ( channel_state_for_pwrmode >= (unsigned int)result )
    result = (unsigned int)result;
  else
    result = channel_state_for_pwrmode;
  if ( (result & 0xFFFFFFFB) != 0 )
  {
    v38 = 0;
    v39 = 101;
    while ( 1 )
    {
      v40 = (v38 + v39) / 2;
      v41 = *(_DWORD *)(channel_map + 12LL * (int)v40);
      if ( v41 == a2 )
        break;
      if ( v41 >= a2 )
        v39 = v40 - 1;
      else
        v38 = v40 + 1;
      if ( v38 > v39 )
      {
        v42 = jiffies;
        if ( reg_get_chan_enum_for_freq___last_ticks - jiffies + 125 < 0 )
        {
          qdf_trace_msg(
            0x51u,
            8u,
            "%s: invalid channel center frequency %d",
            v30,
            v31,
            v32,
            v33,
            v34,
            v35,
            v36,
            v37,
            "reg_get_chan_enum_for_freq",
            a2,
            v12,
            v45);
          reg_get_chan_enum_for_freq___last_ticks = v42;
        }
        return 4;
      }
    }
    if ( v40 > 0x65 )
      return 4;
    v43 = v29 + 36LL * v40;
    v44 = *(unsigned __int16 *)(v43 + 20);
    if ( v17 )
    {
      if ( v44 > 0x28 || *(unsigned __int16 *)(v43 + 22) < 0x28u )
        return 0;
    }
    else if ( v44 > 0x14 || *(unsigned __int16 *)(v43 + 22) <= 0x13u )
    {
      return 0;
    }
  }
  return result;
}
