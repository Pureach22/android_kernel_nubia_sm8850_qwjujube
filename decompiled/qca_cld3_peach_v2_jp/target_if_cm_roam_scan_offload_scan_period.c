__int64 __fastcall target_if_cm_roam_scan_offload_scan_period(
        __int64 a1,
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
  if ( (unsigned __int8)*a2 < 6u )
    return wmi_unified_roam_scan_offload_scan_period(a1, a2);
  qdf_trace_msg(
    0x49u,
    2u,
    "%s: Invalid vdev id:%d",
    a3,
    a4,
    a5,
    a6,
    a7,
    a8,
    a9,
    a10,
    "target_if_cm_roam_scan_offload_scan_period");
  return 16;
}
