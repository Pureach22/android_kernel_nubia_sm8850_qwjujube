__int64 __fastcall reg_get_max_txpower_for_6g_tpe(
        __int64 a1,
        __int64 a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10,
        __int64 a11,
        unsigned int a12,
        int a13,
        char a14,
        char *a15)
{
  __int64 v15; // x20
  unsigned int v17; // w8
  char *v18; // x19
  int v19; // w20
  char is_ap_power_type_c2c; // w0
  char v21; // w8
  __int64 v22; // x19
  char *v23; // x20
  unsigned int v24; // w22
  int v25; // w21
  char v26; // w0
  char v27; // w8
  __int64 v28; // x20
  __int64 v29; // x20

  if ( *(_DWORD *)(channel_map + 504) <= (unsigned int)(unsigned __int16)a2
    && *(_DWORD *)(channel_map + 1212) >= (unsigned int)(unsigned __int16)a2 )
  {
    v17 = a12 & 0xFFFFFFFD;
    if ( (a14 & 1) != 0 )
    {
      if ( v17 )
      {
        v18 = a15;
        v19 = a13;
        is_ap_power_type_c2c = reg_is_ap_power_type_c2c(a12);
        a13 = v19;
        a15 = v18;
        if ( (is_ap_power_type_c2c & 1) == 0 )
          return 16;
      }
      if ( a13 == 1 )
      {
        v21 = 5;
      }
      else
      {
        if ( a13 )
        {
          v28 = jiffies;
          if ( reg_get_max_psd___last_ticks - jiffies + 125 < 0 )
          {
            qdf_trace_msg(0x51u, 2u, "%s: Invalid client type", a3, a4, a5, a6, a7, a8, a9, a10, "reg_get_max_psd");
            reg_get_max_psd___last_ticks = v28;
          }
          return 16;
        }
        v21 = -1;
      }
    }
    else
    {
      if ( v17 )
      {
        v22 = a1;
        v23 = a15;
        v24 = a2;
        v25 = a13;
        v26 = reg_is_ap_power_type_c2c(a12);
        a13 = v25;
        a2 = v24;
        a15 = v23;
        v27 = v26;
        a1 = v22;
        if ( (v27 & 1) == 0 )
          return 16;
      }
      if ( a13 != 1 )
      {
        if ( !a13 )
        {
          *a15 = reg_get_channel_reg_power_for_freq(a1, a2);
          return 0;
        }
        v29 = jiffies;
        if ( reg_get_max_eirp___last_ticks - jiffies + 125 < 0 )
        {
          qdf_trace_msg(0x51u, 2u, "%s: Invalid client type", a3, a4, a5, a6, a7, a8, a9, a10, "reg_get_max_eirp");
          reg_get_max_eirp___last_ticks = v29;
        }
        return 16;
      }
      v21 = 24;
    }
    *a15 = v21;
    return 0;
  }
  v15 = jiffies;
  if ( reg_get_max_txpower_for_6g_tpe___last_ticks - jiffies + 125 < 0 )
  {
    qdf_trace_msg(
      0x51u,
      2u,
      "%s: %d is not a 6G channel frequency",
      a3,
      a4,
      a5,
      a6,
      a7,
      a8,
      a9,
      a10,
      "reg_get_max_txpower_for_6g_tpe",
      (unsigned int)a2);
    reg_get_max_txpower_for_6g_tpe___last_ticks = v15;
  }
  return 16;
}
