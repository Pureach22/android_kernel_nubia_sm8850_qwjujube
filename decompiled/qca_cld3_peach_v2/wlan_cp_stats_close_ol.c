__int64 __fastcall wlan_cp_stats_close_ol(
        __int64 a1,
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

  if ( a1 )
    return 0;
  qdf_trace_msg(0x62u, 2u, "%s: PSOC is null!", a2, a3, a4, a5, a6, a7, a8, a9, "wlan_cp_stats_close_ol", v9, v10);
  return 4;
}
