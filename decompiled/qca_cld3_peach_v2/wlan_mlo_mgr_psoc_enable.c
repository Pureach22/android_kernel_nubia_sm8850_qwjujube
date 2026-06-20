__int64 __fastcall wlan_mlo_mgr_psoc_enable(
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

  if ( !a1 )
  {
    v12 = "%s: psoc is null";
LABEL_10:
    qdf_trace_msg(0x8Fu, 2u, v12, a2, a3, a4, a5, a6, a7, a8, a9, "wlan_mlo_mgr_psoc_enable");
    return 29;
  }
  v9 = *(_QWORD *)(a1 + 2128);
  if ( !v9 )
  {
    qdf_trace_msg(0x49u, 2u, "%s: tx_ops is NULL", a2, a3, a4, a5, a6, a7, a8, a9, "target_if_mlo_get_tx_ops");
    v12 = "%s: tx_ops is null!";
    goto LABEL_10;
  }
  v10 = *(__int64 (**)(void))(v9 + 1984);
  if ( !v10 )
  {
    v12 = "%s: register_events function is null!";
    goto LABEL_10;
  }
  if ( *((_DWORD *)v10 - 1) != -770124015 )
    __break(0x8228u);
  return v10();
}
