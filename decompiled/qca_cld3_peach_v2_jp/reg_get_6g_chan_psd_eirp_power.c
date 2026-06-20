__int64 __fastcall reg_get_6g_chan_psd_eirp_power(
        int a1,
        __int64 a2,
        _WORD *a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10,
        double a11)
{
  __int64 v11; // x29
  __int64 v12; // x30
  __int64 v13; // x8
  __int64 v15; // x20

  if ( a2 )
  {
    v13 = 0;
    while ( *(_DWORD *)(a2 + v13) != a1 )
    {
      v13 += 36;
      if ( v13 == 2160 )
        return 16;
    }
    *a3 = *(char *)(a2 + v13 + 28);
    return 0;
  }
  else
  {
    v15 = jiffies;
    if ( reg_get_6g_chan_psd_eirp_power___last_ticks - jiffies + 125 < 0 )
    {
      qdf_trace_msg(
        0x51u,
        2u,
        "%s: mas_chan_list is NULL",
        a4,
        a5,
        a6,
        a7,
        a8,
        a9,
        a10,
        a11,
        "reg_get_6g_chan_psd_eirp_power",
        v11,
        v12);
      reg_get_6g_chan_psd_eirp_power___last_ticks = v15;
    }
    return 16;
  }
}
