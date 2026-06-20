__int64 __fastcall tgt_cfr_deinit_pdev(
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
  __int64 v11; // x8
  __int64 v12; // x8
  unsigned int v13; // w19
  double v14; // d0
  double v15; // d1
  double v16; // d2
  double v17; // d3
  double v18; // d4
  double v19; // d5
  double v20; // d6
  double v21; // d7

  v9 = *(_QWORD *)(a1 + 80);
  if ( v9 && (v11 = *(_QWORD *)(v9 + 2128)) != 0 )
  {
    v12 = *(_QWORD *)(v11 + 392);
    if ( !v12 )
      return 0;
  }
  else
  {
    qdf_trace_msg(0x6Au, 2u, "%s: tx_ops is NULL", a2, a3, a4, a5, a6, a7, a8, a9, "wlan_psoc_get_cfr_txops");
    v12 = 0x15F71400048025LL;
  }
  if ( *(_DWORD *)(v12 - 4) != -199421295 )
    __break(0x8228u);
  v13 = ((__int64 (__fastcall *)(__int64, __int64))v12)(v9, a1);
  if ( v13 )
    qdf_trace_msg(
      0x6Au,
      2u,
      "%s: Error occurred with exit code %d\n",
      v14,
      v15,
      v16,
      v17,
      v18,
      v19,
      v20,
      v21,
      "tgt_cfr_deinit_pdev",
      v13);
  return v13;
}
