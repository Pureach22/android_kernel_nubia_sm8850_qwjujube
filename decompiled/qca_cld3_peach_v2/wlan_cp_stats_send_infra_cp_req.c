__int64 __fastcall wlan_cp_stats_send_infra_cp_req(
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
  __int64 (*v10)(void); // x8
  const char *v12; // x2

  if ( !a1 || (v9 = *(_QWORD *)(a1 + 2128)) == 0 )
  {
    qdf_trace_msg(0x62u, 2u, "%s: tx_ops is NULL", a2, a3, a4, a5, a6, a7, a8, a9, "target_if_cp_stats_get_tx_ops");
    v12 = "%s: could not get tx_ops";
LABEL_8:
    qdf_trace_msg(0x62u, 2u, v12, a2, a3, a4, a5, a6, a7, a8, a9, "wlan_cp_stats_send_infra_cp_req");
    return 29;
  }
  v10 = *(__int64 (**)(void))(v9 + 320);
  if ( !v10 )
  {
    v12 = "%s: could not get send_req_infra_twt_stats";
    goto LABEL_8;
  }
  if ( *((_DWORD *)v10 - 1) != 116166279 )
    __break(0x8228u);
  return v10();
}
