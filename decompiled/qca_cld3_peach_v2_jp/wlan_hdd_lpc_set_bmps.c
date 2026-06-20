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
  _DWORD *v13; // x22
  __int64 v16; // x20
  __int64 v17; // x20

  if ( result )
  {
    v11 = *(_QWORD *)(result + 24);
    v12 = result;
    if ( v11 && *(_QWORD *)(v11 + 16) )
    {
      if ( (*(_QWORD *)(result + 1640) & 1) != 0 )
      {
        v13 = (_DWORD *)(result + 52832);
        if ( result != -52832 )
        {
          do
            result = wlan_hdd_set_powersave(
                       (unsigned __int8 *)(v12 + 52832),
                       a2 & 1,
                       a3,
                       a4,
                       a5,
                       a6,
                       a7,
                       a8,
                       a9,
                       a10,
                       a11);
          while ( !(unsigned __int8)~(-910593773 * ((unsigned int)((_DWORD)v13 - *v13 - 52832) >> 4))
               && (*(_QWORD *)(v12 + 1640) & 1) != 0 );
        }
      }
    }
    else
    {
      v16 = jiffies;
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
        wlan_hdd_lpc_set_bmps___last_ticks_52 = v16;
      }
    }
  }
  else
  {
    v17 = jiffies;
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
      wlan_hdd_lpc_set_bmps___last_ticks = v17;
    }
  }
  return result;
}
