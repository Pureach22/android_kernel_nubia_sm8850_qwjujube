__int64 __fastcall tgt_mgmt_txrx_register_ev_handler(
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
  double v13; // d0
  double v14; // d1
  double v15; // d2
  double v16; // d3
  double v17; // d4
  double v18; // d5
  double v19; // d6
  double v20; // d7

  if ( !a1 )
  {
    v12 = "%s: psoc is null";
LABEL_9:
    qdf_trace_msg(0x4Bu, 2u, v12, a2, a3, a4, a5, a6, a7, a8, a9, "wlan_psoc_get_mgmt_txrx_txops");
    qdf_trace_msg(
      0x4Bu,
      2u,
      "%s: txops is null for mgmt txrx module",
      v13,
      v14,
      v15,
      v16,
      v17,
      v18,
      v19,
      v20,
      "tgt_mgmt_txrx_register_ev_handler");
    return 29;
  }
  v9 = *(_QWORD *)(a1 + 2128);
  if ( !v9 )
  {
    v12 = "%s: tx_ops is NULL";
    goto LABEL_9;
  }
  v10 = *(__int64 (**)(void))(v9 + 32);
  if ( !v10 )
    return 0;
  if ( *((_DWORD *)v10 - 1) != -770124015 )
    __break(0x8228u);
  return v10();
}
