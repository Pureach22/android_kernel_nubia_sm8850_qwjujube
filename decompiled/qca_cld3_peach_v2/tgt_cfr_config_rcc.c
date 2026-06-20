__int64 __fastcall tgt_cfr_config_rcc(
        __int64 a1,
        __int64 a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10)
{
  __int64 v10; // x8
  __int64 v13; // x8
  __int64 v14; // x8
  unsigned int v15; // w19
  double v16; // d0
  double v17; // d1
  double v18; // d2
  double v19; // d3
  double v20; // d4
  double v21; // d5
  double v22; // d6
  double v23; // d7

  v10 = *(_QWORD *)(a1 + 80);
  if ( v10 && (v13 = *(_QWORD *)(v10 + 2128)) != 0 )
  {
    v14 = *(_QWORD *)(v13 + 424);
    if ( !v14 )
      return 0;
  }
  else
  {
    qdf_trace_msg(0x6Au, 2u, "%s: tx_ops is NULL", a3, a4, a5, a6, a7, a8, a9, a10, "wlan_psoc_get_cfr_txops");
    v14 = 0x4802500B437F8LL;
  }
  if ( *(_DWORD *)(v14 - 4) != -539177542 )
    __break(0x8228u);
  v15 = ((__int64 (__fastcall *)(__int64, __int64))v14)(a1, a2);
  if ( v15 )
    qdf_trace_msg(
      0x6Au,
      2u,
      "%s: Error occurred with exit code %d\n",
      v16,
      v17,
      v18,
      v19,
      v20,
      v21,
      v22,
      v23,
      "tgt_cfr_config_rcc",
      v15);
  return v15;
}
