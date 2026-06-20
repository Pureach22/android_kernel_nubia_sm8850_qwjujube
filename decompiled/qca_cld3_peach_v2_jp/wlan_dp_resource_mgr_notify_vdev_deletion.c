__int64 __fastcall wlan_dp_resource_mgr_notify_vdev_deletion(
        __int64 result,
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
  if ( !result )
    return qdf_trace_msg(
             0x45u,
             5u,
             "%s: DP resource mgr context not present",
             a3,
             a4,
             a5,
             a6,
             a7,
             a8,
             a9,
             a10,
             "wlan_dp_resource_mgr_notify_vdev_deletion");
  if ( *(_DWORD *)(a2 + 16) == 6 )
  {
    *(_BYTE *)(result + 28) = 0;
    return wlan_dp_resource_mgr_select_resource_level(result, a3, a4, a5, a6, a7, a8, a9, a10);
  }
  return result;
}
