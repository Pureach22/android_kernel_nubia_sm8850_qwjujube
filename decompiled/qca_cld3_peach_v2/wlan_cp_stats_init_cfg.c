__int64 __fastcall wlan_cp_stats_init_cfg(
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
    return qdf_trace_msg(0x62u, 2u, "%s: psoc is NULL", a3, a4, a5, a6, a7, a8, a9, a10, "wlan_cp_stats_init_cfg");
  *(_BYTE *)(a2 + 32) = *(_BYTE *)(cfg_psoc_get_values(a1) + 1142);
  result = cfg_psoc_get_values(a1);
  *(_BYTE *)(a2 + 33) = *(_BYTE *)(result + 1143);
  return result;
}
