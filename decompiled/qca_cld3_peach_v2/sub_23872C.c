__int64 __fastcall sub_23872C(__int64 a1, __int64 a2)
{
  __int64 v2; // x13

  return wmi_unified_send_roam_scan_stats_cmd(a1, a2, *(_QWORD *)(v2 + 168));
}
