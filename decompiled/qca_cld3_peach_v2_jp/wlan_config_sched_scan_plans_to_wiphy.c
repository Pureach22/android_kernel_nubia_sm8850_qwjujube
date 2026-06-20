__int64 __fastcall wlan_config_sched_scan_plans_to_wiphy(__int64 a1, __int64 a2)
{
  __int64 result; // x0

  result = ucfg_scan_get_pno_scan_support(a2);
  if ( (result & 1) != 0 )
  {
    *(_WORD *)(a1 + 137) = 4097;
    *(_WORD *)(a1 + 142) = 255;
    *(_BYTE *)(a1 + 139) = 16;
    *(_DWORD *)(a1 + 144) = 2;
    *(_DWORD *)(a1 + 148) = ucfg_scan_get_max_sched_scan_plan_interval(a2);
    result = ucfg_scan_get_max_sched_scan_plan_iterations(a2);
    *(_DWORD *)(a1 + 152) = result;
  }
  return result;
}
