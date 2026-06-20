__int64 __fastcall ucfg_send_infra_cp_stats_request(
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

  v9 = *(_QWORD *)(a1 + 216);
  if ( v9 )
    v10 = *(_QWORD *)(v9 + 80);
  else
    v10 = 0;
  return wlan_cp_stats_send_infra_cp_req(v10, a2, a3, a4, a5, a6, a7, a8, a9);
}
