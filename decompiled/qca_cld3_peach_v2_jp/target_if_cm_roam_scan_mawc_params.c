__int64 __fastcall target_if_cm_roam_scan_mawc_params(
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
  if ( (wmi_service_enabled(a1, 0xACu, a3, a4, a5, a6, a7, a8, a9, a10) & 1) == 0 )
    *(_DWORD *)(a2 + 8) += 96;
  return wmi_unified_roam_mawc_params_cmd(a1, a2);
}
