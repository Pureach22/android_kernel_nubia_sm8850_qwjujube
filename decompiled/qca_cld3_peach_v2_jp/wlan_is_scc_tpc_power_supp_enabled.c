__int64 __fastcall wlan_is_scc_tpc_power_supp_enabled(
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
  __int64 v10; // x8
  __int64 v11; // x8
  __int64 v12; // x0

  v9 = *(_QWORD *)(a1 + 152);
  if ( !v9 )
    return 0;
  v10 = *(_QWORD *)(v9 + 80);
  if ( !v10 )
    return 0;
  v11 = *(_QWORD *)(v10 + 2800);
  if ( !v11 )
    return 0;
  v12 = *(_QWORD *)(v11 + 16);
  if ( v12 )
    LOBYTE(v12) = wmi_service_enabled(v12, 0x146u, a2, a3, a4, a5, a6, a7, a8, a9);
  return v12 & 1;
}
