__int64 __fastcall reg_get_channel_list_with_power(
        __int64 a1,
        __int64 a2,
        unsigned __int8 *a3,
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
  __int64 pdev_obj; // x0
  double v16; // d0
  double v17; // d1
  double v18; // d2
  double v19; // d3
  double v20; // d4
  double v21; // d5
  double v22; // d6
  double v23; // d7
  __int64 v24; // x11
  __int64 v25; // x10
  unsigned __int8 v26; // w9
  unsigned int v27; // w13
  __int64 v28; // x13
  __int64 v29; // x20
  __int64 v30; // x20
  __int64 result; // x0
  __int64 v32; // x10
  __int64 v33; // x13
  __int64 v34; // x15
  _DWORD *v35; // x16
  __int64 v36; // x17

  if ( !a1 )
  {
    v29 = jiffies;
    if ( reg_get_channel_list_with_power___last_ticks - jiffies + 125 < 0 )
    {
      qdf_trace_msg(0x51u, 2u, "%s: invalid pdev", a5, a6, a7, a8, a9, a10, a11, a12, "reg_get_channel_list_with_power");
      reg_get_channel_list_with_power___last_ticks = v29;
    }
    return 4;
  }
  pdev_obj = reg_get_pdev_obj(a1, a5, a6, a7, a8, a9, a10, a11, a12);
  if ( !pdev_obj )
  {
    v30 = jiffies;
    if ( reg_get_channel_list_with_power___last_ticks_38 - jiffies + 125 < 0 )
    {
      qdf_trace_msg(
        0x51u,
        2u,
        "%s: reg pdev priv obj is NULL",
        v16,
        v17,
        v18,
        v19,
        v20,
        v21,
        v22,
        v23,
        "reg_get_channel_list_with_power");
      reg_get_channel_list_with_power___last_ticks_38 = v30;
    }
    return 4;
  }
  if ( a2 && a3 )
  {
    v24 = 1476;
    v25 = 0;
    v26 = 0;
    if ( !a4 )
      v24 = 3672;
    *a3 = 0;
    do
    {
      if ( v25 == 3672 )
      {
        __break(0x5512u);
        return reg_get_channel_list_with_power_for_freq();
      }
      if ( (*(_BYTE *)(pdev_obj + v25 + 12) & 1) == 0 && *(_DWORD *)(pdev_obj + v25 + 8) )
      {
        v27 = v26++;
        v28 = a2 + 12LL * v27;
        *(_DWORD *)v28 = *(_DWORD *)(pdev_obj + v25);
        *(_BYTE *)(v28 + 4) = *(_BYTE *)(pdev_obj + v25 + 4);
        *(_DWORD *)(v28 + 8) = *(_DWORD *)(pdev_obj + v25 + 16);
      }
      v25 += 36;
    }
    while ( v24 != v25 );
    if ( a4 )
    {
      v32 = 508;
      v33 = pdev_obj + 37156;
      v34 = a4;
      do
      {
        if ( a4 == 0xFFFFFFFFLL )
          v34 = *(unsigned int *)(v33 - 212);
        if ( (unsigned __int64)(v34 - 13) >= 0xFFFFFFFFFFFFFFF4LL )
        {
          v35 = (_DWORD *)(v33 + 4 * v34);
          if ( (*(_BYTE *)(v35 - 39) & 1) == 0 )
          {
            if ( *v35 )
            {
              v36 = a2 + 12LL * v26++;
              *(_DWORD *)v36 = *(_DWORD *)(channel_map + v32 - 4);
              *(_BYTE *)(v36 + 4) = *(_BYTE *)(channel_map + v32);
              *(_DWORD *)(v36 + 8) = *(_DWORD *)(v33 + 8 * v34 - 100);
            }
          }
        }
        v32 += 12;
        v33 += 268;
      }
      while ( v32 != 1228 );
    }
    result = 0;
    *a3 = v26;
  }
  else
  {
    qdf_trace_msg(
      0x51u,
      2u,
      "%s: chan_list or num_ch is NULL",
      v16,
      v17,
      v18,
      v19,
      v20,
      v21,
      v22,
      v23,
      "reg_get_channel_list_with_power");
    return 16;
  }
  return result;
}
