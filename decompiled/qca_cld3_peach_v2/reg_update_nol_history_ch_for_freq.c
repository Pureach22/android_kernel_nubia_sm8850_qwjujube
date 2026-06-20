__int64 __fastcall reg_update_nol_history_ch_for_freq(
        __int64 a1,
        __int64 a2,
        unsigned __int8 a3,
        char a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10,
        double a11,
        double a12)
{
  const char *v13; // x2
  __int64 result; // x0
  __int64 v17; // x25
  char v18; // w26
  unsigned int v19; // w4
  __int16 v20; // w9
  __int16 v21; // w10
  unsigned int v22; // w11
  unsigned int v23; // w12
  __int64 v24; // x20
  __int64 v25; // [xsp+0h] [xbp-10h]
  __int64 v26; // [xsp+8h] [xbp-8h]

  v13 = "%s: chan_list or num_ch is NULL";
  if ( !a2 || !a3 )
    return qdf_trace_msg(0x51u, 2u, v13, a5, a6, a7, a8, a9, a10, a11, a12, "reg_update_nol_history_ch_for_freq");
  result = wlan_objmgr_pdev_get_comp_private_obj(a1, 0xDu);
  if ( !result )
  {
    v13 = "%s: reg psoc private obj is NULL";
    return qdf_trace_msg(0x51u, 2u, v13, a5, a6, a7, a8, a9, a10, a11, a12, "reg_update_nol_history_ch_for_freq");
  }
  v17 = 0;
  v18 = a4 & 1;
  v25 = result + 7344;
  v26 = result;
  do
  {
    v19 = *(unsigned __int16 *)(a2 + 2 * v17);
    v20 = 0;
    v21 = 101;
    while ( 1 )
    {
      v22 = (v20 + v21) / 2;
      v23 = *(_DWORD *)(channel_map + 12LL * (int)v22);
      if ( v23 == v19 )
        break;
      if ( v23 >= v19 )
        v21 = v22 - 1;
      else
        v20 = v22 + 1;
      if ( v20 > v21 )
      {
        v24 = jiffies;
        if ( reg_get_chan_enum_for_freq___last_ticks - jiffies + 125 < 0 )
        {
          qdf_trace_msg(
            0x51u,
            8u,
            "%s: invalid channel center frequency %d",
            a5,
            a6,
            a7,
            a8,
            a9,
            a10,
            a11,
            a12,
            "reg_get_chan_enum_for_freq");
          reg_get_chan_enum_for_freq___last_ticks = v24;
        }
        goto LABEL_5;
      }
    }
    if ( v22 >= 0x66 )
    {
LABEL_5:
      result = qdf_trace_msg(
                 0x51u,
                 2u,
                 "%s: Invalid ch in nol list, chan %d",
                 a5,
                 a6,
                 a7,
                 a8,
                 a9,
                 a10,
                 a11,
                 a12,
                 "reg_update_nol_history_ch_for_freq",
                 v25,
                 v26);
      goto LABEL_6;
    }
    *(_BYTE *)(v25 + 36LL * v22 + 26) = v18;
    *(_BYTE *)(v26 + 36LL * v22 + 26) = v18;
LABEL_6:
    ++v17;
  }
  while ( v17 != a3 );
  return result;
}
