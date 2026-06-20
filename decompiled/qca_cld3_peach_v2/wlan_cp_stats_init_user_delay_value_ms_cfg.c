__int64 __fastcall wlan_cp_stats_init_user_delay_value_ms_cfg(
        __int64 a1,
        __int64 a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10)
{
  __int64 result; // x0

  if ( !a1 )
    return qdf_trace_msg(
             0x62u,
             2u,
             "%s: psoc is NULL",
             a3,
             a4,
             a5,
             a6,
             a7,
             a8,
             a9,
             a10,
             "wlan_cp_stats_init_user_delay_value_ms_cfg");
  result = cfg_psoc_get_values(a1);
  *(_QWORD *)(a2 + 40) = *(unsigned int *)(result + 4012);
  return result;
}
