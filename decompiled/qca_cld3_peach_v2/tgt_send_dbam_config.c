__int64 __fastcall tgt_send_dbam_config(
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
  __int64 v11; // x8
  __int64 (*v12)(void); // x8

  v9 = *(_QWORD *)(a1 + 216);
  if ( !v9 || (v10 = *(_QWORD *)(v9 + 80)) == 0 )
  {
    qdf_trace_msg(0x70u, 2u, "%s: NULL psoc", a2, a3, a4, a5, a6, a7, a8, a9, "tgt_send_dbam_config");
    return 29;
  }
  v11 = *(_QWORD *)(v10 + 2128);
  if ( !v11 )
  {
    qdf_trace_msg(0x70u, 2u, "%s: tx_ops is NULL", a2, a3, a4, a5, a6, a7, a8, a9, "wlan_psoc_get_dbam_tx_ops");
    return 0;
  }
  v12 = *(__int64 (**)(void))(v11 + 1944);
  if ( !v12 )
    return 0;
  if ( *((_DWORD *)v12 - 1) != -1700843285 )
    __break(0x8228u);
  return v12();
}
