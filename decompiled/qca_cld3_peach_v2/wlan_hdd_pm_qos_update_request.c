__int64 __fastcall wlan_hdd_pm_qos_update_request(
        __int64 result,
        _DWORD *a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10)
{
  if ( !result )
    return qdf_trace_msg(
             0x33u,
             2u,
             "%s: hdd_ctx is null",
             a3,
             a4,
             a5,
             a6,
             a7,
             a8,
             a9,
             a10,
             "wlan_hdd_pm_qos_update_request");
  if ( (*(_BYTE *)(result + 1461) & 1) == 0 )
    return hdd_pm_qos_update_request(result, a2);
  return result;
}
