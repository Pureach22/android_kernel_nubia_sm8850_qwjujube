__int64 __fastcall hdd_get_tx_stbc(
        __int64 a1,
        _DWORD *a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10)
{
  __int64 v12; // x21
  __int16 ht_config; // w0
  double v14; // d0
  double v15; // d1
  double v16; // d2
  double v17; // d3
  double v18; // d4
  double v19; // d5
  double v20; // d6
  double v21; // d7
  unsigned int v22; // w20

  v12 = *(_QWORD *)(*(_QWORD *)(a1 + 24) + 16LL);
  qdf_trace_msg(0x33u, 8u, "%s: enter", a3, a4, a5, a6, a7, a8, a9, a10, "hdd_get_tx_stbc");
  ht_config = sme_get_ht_config(v12, *(unsigned __int8 *)(*(_QWORD *)(a1 + 52832) + 8LL), 7);
  v22 = ht_config;
  if ( ht_config < 0 )
  {
    qdf_trace_msg(
      0x33u,
      2u,
      "%s: Failed to get TX STBC value",
      v14,
      v15,
      v16,
      v17,
      v18,
      v19,
      v20,
      v21,
      "hdd_get_tx_stbc");
  }
  else
  {
    *a2 = ht_config;
    return 0;
  }
  return v22;
}
