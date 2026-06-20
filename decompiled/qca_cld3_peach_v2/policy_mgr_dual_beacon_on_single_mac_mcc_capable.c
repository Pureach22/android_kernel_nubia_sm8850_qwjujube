__int64 __fastcall policy_mgr_dual_beacon_on_single_mac_mcc_capable(
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
  __int64 v9; // x8
  __int64 v10; // x0
  char v11; // w19
  const char *v12; // x2

  if ( a1 && (v9 = *(_QWORD *)(a1 + 2800)) != 0 && (v10 = *(_QWORD *)(v9 + 16)) != 0 )
  {
    v11 = wmi_service_enabled(v10, 0x99u, a2, a3, a4, a5, a6, a7, a8, a9);
    if ( (v11 & 1) != 0 )
      v12 = "%s: Dual beaconing on different channel on single MAC supported";
    else
      v12 = "%s: Dual beaconing on different channel on single MAC is not supported";
  }
  else
  {
    v11 = 0;
    v12 = "%s: Invalid WMI handle";
  }
  qdf_trace_msg(0x4Fu, 8u, v12, a2, a3, a4, a5, a6, a7, a8, a9, "policy_mgr_dual_beacon_on_single_mac_mcc_capable");
  return v11 & 1;
}
