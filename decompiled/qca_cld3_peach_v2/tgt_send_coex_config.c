__int64 __fastcall tgt_send_coex_config(
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
  __int64 v9; // x0
  __int64 v10; // x8
  __int64 v11; // x8
  __int64 (*v12)(void); // x8
  const char *v14; // x2

  if ( !a1 )
  {
    v14 = "%s: NULL vdev";
    goto LABEL_11;
  }
  v9 = *(_QWORD *)(a1 + 216);
  if ( !v9 || (v10 = *(_QWORD *)(v9 + 80)) == 0 )
  {
    v14 = "%s: NULL psoc";
LABEL_11:
    qdf_trace_msg(0x70u, 2u, v14, a2, a3, a4, a5, a6, a7, a8, a9, "tgt_send_coex_config");
    return 29;
  }
  v11 = *(_QWORD *)(v10 + 2128);
  if ( !v11 )
  {
    qdf_trace_msg(0x70u, 2u, "%s: tx_ops is NULL", a2, a3, a4, a5, a6, a7, a8, a9, "wlan_psoc_get_coex_txops");
    return 0;
  }
  v12 = *(__int64 (**)(void))(v11 + 1920);
  if ( !v12 )
    return 0;
  if ( *((_DWORD *)v12 - 1) != -2089547856 )
    __break(0x8228u);
  return v12();
}
