__int64 __fastcall wlan_cp_stats_disable_ol(
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
  __int64 v9; // x20
  void (*v10)(void); // x8
  void (__fastcall *v12)(_QWORD); // x8
  const char *v14; // x2

  if ( !a1 )
  {
    qdf_trace_msg(0x62u, 2u, "%s: PSOC is null!", a2, a3, a4, a5, a6, a7, a8, a9, "wlan_cp_stats_disable_ol");
    return 4;
  }
  v9 = *(_QWORD *)(a1 + 2128);
  if ( !v9 )
  {
    qdf_trace_msg(0x62u, 2u, "%s: tx_ops is NULL", a2, a3, a4, a5, a6, a7, a8, a9, "target_if_cp_stats_get_tx_ops");
    v14 = "%s: tx_ops is null!";
LABEL_14:
    qdf_trace_msg(0x62u, 2u, v14, a2, a3, a4, a5, a6, a7, a8, a9, "wlan_cp_stats_disable_ol");
    return 29;
  }
  v10 = *(void (**)(void))(v9 + 280);
  if ( !v10 )
  {
    v14 = "%s: cp_stats_legacy_detach function ptr is null!";
    goto LABEL_14;
  }
  if ( *((_DWORD *)v10 - 1) != -770124015 )
    __break(0x8228u);
  v10();
  v12 = *(void (__fastcall **)(_QWORD))(v9 + 264);
  if ( !v12 )
  {
    v14 = "%s: cp_stats_detach function ptr is null!";
    goto LABEL_14;
  }
  if ( *((_DWORD *)v12 - 1) != -770124015 )
    __break(0x8228u);
  v12(a1);
  return 0;
}
