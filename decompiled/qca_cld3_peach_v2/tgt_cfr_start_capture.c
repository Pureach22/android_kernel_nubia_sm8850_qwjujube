__int64 __fastcall tgt_cfr_start_capture(
        __int64 a1,
        __int64 a2,
        __int64 a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10,
        double a11)
{
  __int64 v11; // x8
  __int64 v15; // x8
  __int64 v16; // x8
  unsigned int v17; // w19
  double v18; // d0
  double v19; // d1
  double v20; // d2
  double v21; // d3
  double v22; // d4
  double v23; // d5
  double v24; // d6
  double v25; // d7

  v11 = *(_QWORD *)(a1 + 80);
  if ( v11 && (v15 = *(_QWORD *)(v11 + 2128)) != 0 )
  {
    v16 = *(_QWORD *)(v15 + 408);
    if ( !v16 )
      return 0;
  }
  else
  {
    qdf_trace_msg(0x6Au, 2u, "%s: tx_ops is NULL", a4, a5, a6, a7, a8, a9, a10, a11, "wlan_psoc_get_cfr_txops");
    v16 = 0xB438040015F7FCLL;
  }
  if ( *(_DWORD *)(v16 - 4) != 1050566274 )
    __break(0x8228u);
  v17 = ((__int64 (__fastcall *)(__int64, __int64, __int64))v16)(a1, a2, a3);
  if ( v17 )
    qdf_trace_msg(
      0x6Au,
      2u,
      "%s: Error occurred with exit code %d\n",
      v18,
      v19,
      v20,
      v21,
      v22,
      v23,
      v24,
      v25,
      "tgt_cfr_start_capture",
      v17);
  return v17;
}
