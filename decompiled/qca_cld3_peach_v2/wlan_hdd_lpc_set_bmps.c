__int64 __fastcall wlan_hdd_lpc_set_bmps(
        __int64 result,
        char a2,
        unsigned int a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10,
        double a11)
{
  __int64 v11; // x8
  __int64 v12; // x20
  unsigned __int8 *v15; // x22
  __int64 v16; // x8
  __int64 v17; // x9
  __int64 v18; // x10
  __int64 v19; // x20
  __int64 v20; // x20

  if ( result )
  {
    v11 = *(_QWORD *)(result + 24);
    v12 = result;
    if ( v11 && *(_QWORD *)(v11 + 16) )
    {
      if ( (*(_QWORD *)(result + 1640) & 1) != 0 && (v15 = (unsigned __int8 *)(result + 52840), result != -52840)
        || (*(_QWORD *)(result + 1640) & 2) != 0 && (v15 = (unsigned __int8 *)(result + 58928), result != -58928)
        || (*(_QWORD *)(result + 1640) & 4) != 0 && (v15 = (unsigned __int8 *)(result + 65016), result != -65016) )
      {
        do
        {
          result = wlan_hdd_set_powersave(v15, a2 & 1, a3, a4, a5, a6, a7, a8, a9, a10, a11);
          if ( (unsigned __int8)(73 * ((unsigned int)((_DWORD)v15 - *(_DWORD *)v15 - 52840) >> 3) + 1) > 2u )
            break;
          v16 = (unsigned __int8)(73 * ((unsigned int)((_DWORD)v15 - *(_DWORD *)v15 - 52840) >> 3) + 1);
          v15 = nullptr;
          v17 = v12 + 52840 + 6088LL * (unsigned int)v16;
          do
          {
            if ( v15 )
              break;
            v18 = *(_QWORD *)(v12 + 1640) >> v16++;
            v15 = (unsigned __int8 *)((v18 << 63 >> 63) & v17);
            v17 += 6088;
          }
          while ( v16 != 3 );
        }
        while ( v15 );
      }
    }
    else
    {
      v19 = jiffies;
      if ( wlan_hdd_lpc_set_bmps___last_ticks_52 - jiffies + 125 < 0 )
      {
        result = qdf_trace_msg(
                   0x33u,
                   2u,
                   "%s: null mac_handle pointer",
                   a4,
                   a5,
                   a6,
                   a7,
                   a8,
                   a9,
                   a10,
                   a11,
                   "wlan_hdd_lpc_set_bmps");
        wlan_hdd_lpc_set_bmps___last_ticks_52 = v19;
      }
    }
  }
  else
  {
    v20 = jiffies;
    if ( wlan_hdd_lpc_set_bmps___last_ticks - jiffies + 125 < 0 )
    {
      result = qdf_trace_msg(
                 0x33u,
                 2u,
                 "%s: null hdd_adapter pointer",
                 a4,
                 a5,
                 a6,
                 a7,
                 a8,
                 a9,
                 a10,
                 a11,
                 "wlan_hdd_lpc_set_bmps");
      wlan_hdd_lpc_set_bmps___last_ticks = v20;
    }
  }
  return result;
}
