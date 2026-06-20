__int64 __fastcall wlan_hdd_get_dfs_mode(
        __int64 result,
        double a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9)
{
  __int64 v9; // x29
  __int64 v10; // x30

  if ( (unsigned int)(result - 1) >= 3 )
  {
    qdf_trace_msg(
      0x33u,
      8u,
      "%s: ACS dfs mode is NONE",
      a2,
      a3,
      a4,
      a5,
      a6,
      a7,
      a8,
      a9,
      "wlan_hdd_get_dfs_mode",
      v9,
      v10);
    return 0;
  }
  return result;
}
